#include <bits/stdc++.h>

using namespace std;

const int Z = 2200;

int N, M, K;
int L[2020];
int R[2020];

struct NODE {
	int lz, sum;
};

struct SegTree {
	NODE T[4 * 5050];

	void init(int idx, int s, int e) {
		T[idx].lz = T[idx].sum = 0;
		if(s == e) return;
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
	}

	void init() { init(1, 1, N + Z); }

	void propa(int idx, int s, int e) {
		T[idx].sum += (e - s + 1) * T[idx].lz;
		if(s != e) {
			T[idx << 1].lz += T[idx].lz;
			T[idx << 1 | 1].lz += T[idx].lz;
		}
		T[idx].lz = 0;
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].lz += x;
			propa(idx, s, e);
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		T[idx].sum = T[idx << 1].sum + T[idx << 1 | 1].sum;
	}

	int get(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return 0;
		if(p <= s && e <= q) return T[idx].sum;
		int m = s + e >> 1;
		return get(idx << 1, s, m, p, q) + get(idx << 1 | 1, m + 1, e, p, q);
	}

	void upd(int p, int q, int x) { upd(1, 1, N + Z, max(1, p + Z), min(q + Z, N + Z), x); }
	int query(int i) {
		return get(1, 1, N + Z, 1, i + Z);
	}
}seg;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= M; i++) scanf("%d%d", &L[i], &R[i]);
	int ans = 0;
	for(int i = 1; i <= N - K + 1; i++) {
		int l = i, r = i + K - 1;
		int add = 0;
		seg.init();
		for(int j = 1; j <= M; j++) {
			bool ok = false;
			if(l <= L[j] && R[j] <= r) ok = true;
			if(L[j] <= l && r <= R[j]) ok = true;
			if(ok) { add += min(R[j] - L[j] + 1, K); continue; }

			if(R[j] < l || r < L[j]) {
				if(R[j] - L[j] + 1 >= K) {
					seg.upd(L[j] - K + 1, L[j], 1);
					seg.upd(R[j] - K + 2, R[j] + 1, -1);
				}
				else {
					seg.upd(L[j] - K + 1, R[j] - K + 1, 1);
					seg.upd(L[j] + 1, R[j] + 1, -1);
				}
				continue;
			}

			int t = min(R[j] - l, r - L[j]) + 1;
			add += t;
			if(R[j] - L[j] + 1 >= K) {
				seg.upd(L[j] - (K - t) + 1, L[j], 1);
				seg.upd(R[j] - K + 2, R[j] - t + 1, -1);
			}
			else {
				seg.upd(L[j] - (K - t) + 1, R[j] - K + 1, 1);
				seg.upd(L[j] + 1, R[j] - t + 1, -1);
			}
		}

		int mx = 0;
		for(int j = 1; j <= N; j++) mx = max(mx, seg.query(j));
		// printf("%d %d %d\n", i, add, mx);
		ans = max(ans, mx + add);
	}
	printf("%d\n", ans);
	return 0;
}