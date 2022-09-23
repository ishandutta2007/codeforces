#include <bits/stdc++.h>

using namespace std;

int A[303030];
int R[303030];

int N;

int T[4 * 303030];

const int base = 524288;

void upd(int p, int x) {
	p--; p += base;
	T[p] = x; p >>= 1;
	while(p) {
		T[p] = min(T[p << 1], T[p << 1 | 1]);
		p >>= 1;
	}
}

int get(int p, int q) {
	p--; q--;
	p += base; q += base;
	int ret = 987654321;
	while(p <= q) {
		if(p & 1) { ret = min(ret, T[p]); p++; }
		if(!(q & 1)) { ret = min(ret, T[q]); q--; }
		p >>= 1; q >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) A[N + i] = A[i];
	for(int i = 1; i <= N; i++) A[2 * N + i] = A[i];

	N *= 3;
	for(int i = 1; i <= N; i++) upd(i, A[i]);

	for(int i = 1; i <= N; i++) {
		int l = i, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			int t = get(i, m);
			if(t < (A[i] + 1) / 2) r = m - 1;
			else l = m + 1;
		}
		R[i] = l;
	}

	// for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	// for(int i = 1; i <= N; i++) printf("%d ", R[i]); puts("");

	for(int i = 1; i <= N; i++) upd(i, R[i]);

	for(int i = 1; i <= N / 3; i++) {
		int l = i, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			int t = get(i, m);
			if(t <= m) r = m - 1;
			else l = m + 1;
		}
		if(l > N) printf("-1 ");
		else printf("%d ", l - i);
	}
	puts("");

	return 0;
}