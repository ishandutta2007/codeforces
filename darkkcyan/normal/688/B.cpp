#include <iostream>
using namespace std;

void print() {
	char ch;
	if (!(cin >> ch)) return;
	cout << ch;
	print();
	cout << ch;
}

int main() {
	print();
	return 0;
}