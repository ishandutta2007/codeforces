#include <iostream>

int N;
int A, B;

void read() {
	int tmp;
	for(int a = 0; a < 3; ++a) {
		std::cin >> tmp;
		A += tmp;
	}
	for(int b = 0; b < 3; ++b) {
		std::cin >> tmp;
		B += tmp;
	}
	std::cin >> N;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	
	read();
	
	if((A / 5 + (A % 5 != 0)) + (B / 10 + (B % 10 != 0)) <= N)
		std::cout << "YES";
	else
		std::cout << "NO";
}