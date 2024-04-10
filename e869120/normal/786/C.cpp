#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 17], C[1 << 17], B[1 << 17];

int solve(int pos) {
	for (int i = 1; i <= N; i++) C[i] = 0;

	int L = 1, cnt = 0, types = 0;
	for (int i = 1; i <= N; i++) {
		if (C[A[i]] == 0) {
			if (types == pos) {
				types = 0; cnt++;
				for (int j = L; j < i; j++) C[A[j]] = 0;
				L = i;
			}
			C[A[i]] = 1;
			types++;
		}
	}
	cnt++;
	return cnt;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	int TT = 1000;
	for (int i = 1; i <= TT; i++) B[i] = solve(i);
	int E = N;
	for (int i = 1; i <= N; i++) {
		int cl = 1, cr = N + 1, cm, maxn = 0;
		for (int j = 1; j <= 20; j++) {
			cm = (cl + cr) / 2;
			int G = solve(cm);
			if (G >= i) { maxn = max(maxn, cm); cl = cm; }
			else { cr = cm; }
		}
		for (int j = maxn + 1; j <= E; j++) B[j] = i - 1;
		E = maxn; if (E <= TT) break;
	}
	for (int i = 1; i <= N; i++) { if (i >= 2) printf(" "); printf("%d", B[i]); } printf("\n");
	return 0;
}