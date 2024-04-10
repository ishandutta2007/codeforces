#include <cstdlib>
#include <iostream>

int N;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	
	for(int y = 0; y < N; ++y) {
		for(int x = 0; x < N; ++x) {
			if(abs(x - (N - 1) / 2) <= (N - 1) / 2 - abs(y - (N - 1) / 2))
				std::cout << 'D';
			else
				std::cout << '*';
		}
		std::cout << '\n';
	}
}