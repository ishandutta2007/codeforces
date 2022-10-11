#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, L;
long long A[1200009], B[1200009], C[1200009];

bool solve(long long pos) {
	for (int i = 0; i < 6 * N; i++) C[i] = 0;
	for (int i = 0; i < N; i++) {
		int pos1 = lower_bound(A, A + 6 * N, B[i] + L - pos) - A;
		int pos2 = lower_bound(A, A + 6 * N, B[i] + L + pos + 1LL) - A;
		pos1 += N; pos1 -= i;
		pos2 += N; pos2 -= i; if (pos2 - pos1 >= N) pos2 = pos1 + N;
		C[pos1]++; C[pos2]--;
	}
	for (int i = 1; i < 6 * N; i++) C[i] += C[i - 1];

	for (int i = 0; i < N; i++) {
		if (C[i] + C[i + N] + C[i + N + N] + C[i +  N + N + N] + C[i + N + N + N + N] + C[i + N + N + N + N + N] == N) return true;
	}
	return false;
}

int main() {
	scanf("%lld%lld", &N, &L);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]); sort(A, A + N); for (int i = N; i < 6 * N; i++) A[i] = A[i - N] + L;
	for (int i = 0; i < N; i++) scanf("%lld", &B[i]); sort(B, B + N);

	long long cl = 0, cr = L + 1, cm, minx = (1LL << 60);
	for (int i = 0; i < 35; i++) {
		cm = (cl + cr) / 2;
		bool t = solve(cm);
		if (t == true) { minx = min(minx, cm); cr = cm; }
		else { cl = cm; }
	}
	cout << minx << endl;
	return 0;
}