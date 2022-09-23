#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

struct NODE {
	int mn, add;
};

struct SegTree {
	NODE T[4 * 404040];

	void init(int idx, int s, int e) {
		T[idx].mn = T[idx].add = 0;
		if(s == e) return;
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
	}

	void init(int n) {
		init(1, 1, n);
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].mn += x; T[idx].add += x;
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		T[idx].mn = min(T[idx << 1].mn, T[idx << 1 | 1].mn) + T[idx].add;
	}

	int get() {
		return T[1].mn;
	}
}seg;

int N;
int B[202020];
int A[202020];
bool chk[404040];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= 2 * N; i++) chk[i] = false;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &B[i]);
			chk[B[i]] = true;
		}
		int t = 0;
		for(int i = 1; i <= 2 * N; i++) if(!chk[i]) A[++t] = i;

		seg.init(2 * N);
		int l = N, r = 0;
		for(int i = 1; i <= N; i++) {
			seg.upd(1, 1, 2 * N, B[i], 2 * N, 1);
			seg.upd(1, 1, 2 * N, A[N - i + 1], 2 * N, -1);
			if(seg.get() < 0) { l = i - 1; break; }
		}

		seg.init(2 * N);
		for(int i = N; i >= 1; i--) {
			seg.upd(1, 1, 2 * N, B[i], 2 * N, -1);
			seg.upd(1, 1, 2 * N, A[N - i + 1], 2 * N, 1);
			if(seg.get() < 0) { r = i; break; }
		}
		printf("%d\n", max(0, l - r + 1));
	}
	return 0;
}