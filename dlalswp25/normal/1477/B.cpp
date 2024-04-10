#include <bits/stdc++.h>

using namespace std;

int N, Q;
char A[202020];
char B[202020];
int L[202020];
int R[202020];

struct Node {
	int x = 0;
	int lz = -1;
};

struct SegTree {
	Node T[4 * 202020];

	void init(int idx, int s, int e) {
		T[idx].lz = -1;
		if(s == e) {
			if(B[s] == '0') T[idx].x = 1;
			else T[idx].x = 0;
			return;
		}
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
		T[idx].x = T[idx << 1].x + T[idx << 1 | 1].x;
	}

	void propa(int idx, int s, int e) {
		if(T[idx].lz == 0) T[idx].x = e - s + 1;
		else if(T[idx].lz == 1) T[idx].x = 0;
		if(s != e) {
			if(T[idx].lz != -1) {
				T[idx << 1].lz = T[idx].lz;
				T[idx << 1 | 1].lz = T[idx].lz;
			}
		}
		T[idx].lz = -1;
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].lz = x;
			propa(idx, s, e);
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		T[idx].x = T[idx << 1].x + T[idx << 1 | 1].x;
	}

	int get(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return 0;
		if(p <= s && e <= q) return T[idx].x;
		int m = s + e >> 1;
		return get(idx << 1, s, m, p, q) + get(idx << 1 | 1, m + 1, e, p, q);
	}
}seg;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &Q);
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		for(int i = 1; i <= Q; i++) scanf("%d%d", &L[i], &R[i]);
		bool ans = true;
		seg.init(1, 1, N);
		for(int i = Q; i >= 1; i--) {
			int t = seg.get(1, 1, N, L[i], R[i]);
			int len = R[i] - L[i] + 1;
			if(t * 2 == len) {
				ans = false; break;
			}
			if(t * 2 < len) seg.upd(1, 1, N, L[i], R[i], 1);
			else seg.upd(1, 1, N, L[i], R[i], 0);
		}
		for(int i = 1; i <= N; i++) if(A[i] - '0' != 1 - seg.get(1, 1, N, i, i)) ans = false;
		puts(ans ? "YES" : "NO");
	}
	return 0;
}