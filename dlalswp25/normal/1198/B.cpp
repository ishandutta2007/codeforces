#include <bits/stdc++.h>

using namespace std;

int T[4 * 202020];
int A[202020];
int L[202020];
int lt[202020];

int N, Q;

void upd(int idx, int s, int e, int p, int x) {
	if(e < s || p < s || e < p) return;
	if(s == e) {
		T[idx] = x; return;
	}
	int m = s + e >> 1;
	upd(idx * 2, s, m, p, x);
	upd(idx * 2 + 1, m + 1, e, p, x);
	T[idx] = max(T[idx * 2], T[idx * 2 + 1]);
}

int get(int idx, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return T[idx];
	int m = s + e >> 1;
	return max(get(idx * 2, s, m, p, q), get(idx * 2 + 1, m + 1, e, p, q));
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	scanf("%d", &Q);
	for(int q = 1; q <= Q; q++) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int p, x; scanf("%d%d", &p, &x);
			L[p] = x;
			lt[p] = q;
		}
		else {
			int x; scanf("%d", &x);
			upd(1, 1, Q, q, x);
		}
	}

	for(int i = 1; i <= N; i++) {
		if(lt[i] == 0) printf("%d ", max(A[i], get(1, 1, Q, 1, Q)));
		else printf("%d ", max(L[i], get(1, 1, Q, lt[i] + 1, Q)));
	}
	puts("");

	return 0;
}