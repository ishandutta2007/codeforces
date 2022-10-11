#include <iostream>
#include <vector>
using namespace std;

vector<int> solve_zero(int N) {
	if (N % 2 == 1) return vector<int>{};

	vector<int> A(N, 0);
	while (N >= 2) {
		int D = 0;
		for (int i = 1; i < 20; i++) {
			if ((1 << i) - 2 >= N) { D = (1 << i) - 2; break; }
		}
		for (int i = D - N + 1; i <= N; i++) A[i - 1] = D + 1 - i;
		N = D - N;
	}
	return A;
}

vector<int> solve_nonzero(int N) {
	if (N <= 5) return vector<int>{};
	if (N == 6) return vector<int>{3, 6, 1, 5, 4, 2};

	vector<int> A(N, 0);
	while (true) {
		if (N == 7) {
			A[0] = 3; A[1] = 6; A[2] = 7; A[3] = 5; A[4] = 4; A[5] = 2; A[6] = 1;
			break;
		}
		int D = 0; for (int i = 0; i < 20; i++) { if (N >= (1 << i)) D = (1 << i); }
		if (D == N) return vector<int>{};
		for (int i = D; i <= N; i++) A[i - 1] = (((i - D) + 1) % (N - D + 1)) + D;
		N = D - 1;
	}
	return A;
}

int main() {
	int T; cin >> T;
	vector<int> E1 = solve_zero(T);
	vector<int> E2 = solve_nonzero(T);
	if (E1.size() == 0) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 0; i < E1.size(); i++) { if (i) printf(" "); printf("%d", E1[i]); } printf("\n");
	}
	if (E2.size() == 0) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 0; i < E2.size(); i++) { if (i) printf(" "); printf("%d", E2[i]); } printf("\n");
	}
	return 0;
}