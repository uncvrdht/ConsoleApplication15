#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* back;
    size_t size;

public:
    Deque() : front(nullptr), back(nullptr), size(0) {}

    void PushFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (IsEmpty()) {
            front = back = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void PushBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (IsEmpty()) {
            front = back = newNode;
        }
        else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void PopFront() {
        if (IsEmpty()) {
            return;
        }

        Node<T>* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        }
        else {
            back = nullptr;
        }
        delete temp;
        size--;
    }

    void PopBack() {
        if (IsEmpty()) {
            return;
        }

        Node<T>* temp = back;
        back = back->prev;
        if (back != nullptr) {
            back->next = nullptr;
        }
        else {
            front = nullptr;
        }
        delete temp;
        size--;
    }

    T Front() const {
        return front->data;
    }

    T Back() const {
        return back->data;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    size_t Size() const {
        return size;
    }
};

int main() {
    Deque<int> deque;

    deque.PushBack(1);
    deque.PushFront(2);
    deque.PushBack(3);

    std::cout << "Deque size: " << deque.Size() << std::endl;

    std::cout << "Front element: " << (deque.IsEmpty() ? -1 : deque.Front()) << std::endl;
    std::cout << "Back element: " << (deque.IsEmpty() ? -1 : deque.Back()) << std::endl;

    deque.PopFront();
    deque.PopBack();

    std::cout << "Deque size after popping front and back: " << deque.Size() << std::endl;

    return 0;
}
