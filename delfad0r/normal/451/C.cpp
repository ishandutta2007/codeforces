#include <iostream>

int T;

void solve_testcase() {
	long long N, K, D1, D2;
	std::cin >> N >> K >> D1 >> D2;
	if(N % 3 != 0) {
		std::cout << "no\n";
		return;
	}
	if(D2 > D1)
		std::swap(D1, D2);
		
	long long A, B;
	for(int i = 0; i < 4; ++i) {
		switch(i) {
			case 0: A = K + 2 * D1 + D2; 	B = -D1 -2 * D2 + K; 	break;
			case 1: A = K + D1 + D2; 		B = -2 * D1 + D2 + K; 	break;
			case 2: A = K + 2 * D1 - D2; 	B = -D1 - D2 + K; 		break;
			case 3: A = K + D1 + 2 * D2; 	B = -2 * D1 - D2 + K; 	break;
		}
		if(A % 3 == 0 && A <= N && B >= 0) {
			std::cout << "yes\n";
			return;
		}
	}
	std::cout << "no\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> T;
	while(--T >= 0)
		solve_testcase();
}