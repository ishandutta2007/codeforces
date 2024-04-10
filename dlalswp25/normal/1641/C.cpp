#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N, Q;
int qs[202020][4];
int A[202020];
int B[202020];
int C[202020];

struct Node {
	int mn = INF;
	int lz = INF;
};

struct SegTreeLazy {
	Node T[4 * 202020];

	void propa(int idx, int s, int e) {
		T[idx].mn = min(T[idx].mn, T[idx].lz);
		if(s != e) {
			T[idx << 1].lz = min(T[idx << 1].lz, T[idx].lz);
			T[idx << 1 | 1].lz = min(T[idx << 1 | 1].lz, T[idx].lz);
		}
		T[idx].lz = INF;
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
		T[idx].mn = min(T[idx << 1].mn, T[idx << 1 | 1].mn);
	}

	int get(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return INF;
		if(p <= s && e <= q) return T[idx].mn;
		int m = s + e >> 1;
		return min(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}
}seg2;

struct SegTree {
	int T[4 * 202020];

	void upd(int idx, int s, int e, int p, int x) {
		if(p < s || e < p) return;
		if(s == e) {
			T[idx] = x; return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, x);
		upd(idx << 1 | 1, m + 1, e, p, x);
		T[idx] = max(T[idx << 1], T[idx << 1 | 1]);
	}

	int get(int idx, int s, int e, int p, int q) {
		if(q < p || q < s || e < p) return 0;
		if(p <= s && e <= q) return T[idx];
		int m = s + e >> 1;
		return max(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}
}seg;

struct BIT {
	int T[202020];

	void clr() {
		for(int i = 1; i <= N; i++) T[i] = 0;
	}

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}

	void upd(int l, int r, int v) {
		upd(l, v); upd(r + 1, -v);
	}

	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt;

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= Q; i++) {
		scanf("%d%d", &qs[i][0], &qs[i][1]);
		if(!qs[i][0]) scanf("%d%d", &qs[i][2], &qs[i][3]);
	}

	for(int i = 1; i <= Q; i++) {
		if(qs[i][0]) continue;
		if(qs[i][3]) continue;
		int l = qs[i][1], r = qs[i][2];
		fwt.upd(l, r, 1);
		seg2.upd(1, 1, N, l, r, i);
	}

	for(int i = 1; i <= N; i++) {
		A[i] = seg2.get(1, 1, N, i, i);
		if(A[i] == INF) A[i] = 0;
	}
	for(int i = 1; i <= N; i++) seg.upd(1, 1, N, i, A[i]);

	for(int i = 1; i <= N; i++) {
		if(fwt.get(i)) B[i] = 1;
	}
	fwt.clr();
	for(int i = 1; i <= N; i++) if(!B[i]) fwt.upd(i, 1);

	for(int i = 1; i <= Q; i++) {
		if(qs[i][0]) {
			int t = qs[i][1];
			if(B[t]) {
				if(seg.get(1, 1, N, t, t) > i) puts("N/A");
				else puts("NO");
			}
			else {
				if(!C[t] || C[t] > i) puts("N/A");
				else puts("YES");
			}
		}
		else {
			if(!qs[i][3]) continue;
			int l = qs[i][1], r = qs[i][2];
			int tl = l, tr = r;
			int fl = fwt.get(l - 1);
			if(fwt.get(r) - fl >= 2) continue;
			while(l <= r) {
				int m = l + r >> 1;
				if(fwt.get(m) - fl == 0) l = m + 1;
				else r = m - 1;
			}
			// l
			int t = seg.get(1, 1, N, tl, tr);
			t = max(t, i);
			if(!C[l]) C[l] = t;
			else if(C[l] > t) C[l] = t;
		}
	}
	return 0;
}