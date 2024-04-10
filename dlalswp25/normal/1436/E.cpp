#include <bits/stdc++.h>

using namespace std;

bool chk[101010];
int N;
int A[101010];
int L[101010];

struct SEG {
	int T[4 * 101010];

	void upd(int idx, int s, int e, int p, int x) {
		if(p < s || e < p) return;
		if(s == e) { T[idx] = x; return; }
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, x);
		upd(idx << 1 | 1, m + 1, e, p, x);
		T[idx] = min(T[idx << 1], T[idx << 1 | 1]);
	}

	int get(int idx, int s, int e, int x) {
		// printf("%d %d %d %d\n", idx, s, e, x);
		if(T[idx] >= x) return N + 1;
		if(s == e) return s;
		int m = s + e >> 1;
		if(T[idx << 1] < x) return get(idx << 1, s, m, x);
		return get(idx << 1 | 1, m + 1, e, x);
	}

	void upd(int p, int x) { upd(1, 1, N, p, x); }
	int get(int x) { return get(1, 1, N, x); }
}seg;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if(A[i] != 1) chk[1] = true;
	}

	for(int i = 1; i <= N; i++) {
		if(L[A[i]] == i - 1) { L[A[i]] = i; seg.upd(A[i], i); continue; }
		int t = seg.get(L[A[i]] + 1);
		if(t == A[i]) chk[A[i]] = true;
		seg.upd(A[i], i);
		L[A[i]] = i;
	}
	for(int i = 2; i <= N; i++) {
		if(L[i] != N && seg.get(L[i] + 1) == i) chk[i] = true;
	}
	chk[seg.get(1)] = true;
	for(int i = 1; i <= N + 1; i++) if(!chk[i]) { printf("%d\n", i); return 0; }
	printf("%d\n", N + 2);

	return 0;
}