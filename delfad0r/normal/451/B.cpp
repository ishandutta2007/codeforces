#include <algorithm>
#include <iostream>

int N;
int A[100000];
int A_sorted[100000];

int main() {
	std::ios_base::sync_with_stdio(false);
	
	std::cin >> N;
	for(int n = 0; n < N; ++n) {
		std::cin >> A[n];
		A_sorted[n] = A[n];
	}
	
	std::sort(A_sorted, A_sorted + N);
	int l = 0, r = N - 1;
	while(l < N && A[l] == A_sorted[l])
		++l;
	while(r >= 0 && A[r] == A_sorted[r])
		--r;
	if(r < l) {
		std::cout << "yes\n1 1";
		return 0;
	}
	std::reverse(A + l, A + r + 1);
	if(std::equal(A, A + N, A_sorted))
		std::cout << "yes\n" << l + 1 << " " << r + 1;
	else
		std::cout << "no";
}