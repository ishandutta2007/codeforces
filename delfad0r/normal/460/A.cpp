#include <cstdio>
#include <iostream>

int N, M;

int main() {
	std::cin >> N >> M;
	for(int d = 1; ; ++d) {
		if(N == 0) {
			std::cout << d - 1;
			return 0;
		}
		--N;
		if(d % M == 0) ++N;
	}
}