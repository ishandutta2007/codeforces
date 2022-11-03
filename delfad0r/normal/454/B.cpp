#include <iostream>

int N;
int A[100000];

int main() {
	std::ios_base::sync_with_stdio(false);
	
	std::cin >> N;
	for(int n = 0; n < N; ++n)
		std::cin >> A[n];
	
	int p = 0;
	for(int n = 1; n < N; ++n) {
		if(A[n] < A[n - 1]) {
			if(p > 0) {
				std::cout << "-1";
				return 0;
			}
			p = n;
		}
	}
	if(p == 0) {
		std::cout << '0';
		return 0;
	}
	if(A[N - 1] > A[0]) {
		std::cout << "-1";
		return 0;
	}
	std::cout << N - p;
}