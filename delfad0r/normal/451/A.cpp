#include <algorithm>
#include <iostream>

int N, M;

int main() {
	std::cin >> N >> M;
	if(std::min(N, M) % 2 == 0)
		std::cout << "Malvika";
	else
		std::cout << "Akshat";
}