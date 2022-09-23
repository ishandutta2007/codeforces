#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1010101010;

int N;
int A[202020];
bool I[202020];

struct Node {
	ll mn, lz;
};

struct SegTree {
	Node T[4 * 202020];

	void init(int idx, int s, int e) {
		T[idx].mn = INF;
		if(s == e) return;
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
	}

	void propa(int idx, int s, int e) {
		T[idx].mn += T[idx].lz;
		if(s != e) {
			T[idx << 1].lz += T[idx].lz;
			T[idx << 1 | 1].lz += T[idx].lz;
		}
		T[idx].lz = 0;
	}

	void add(int x) {
		T[1].lz += x;
		propa(1, 1, N + 1);
	}

	void upd(int idx, int s, int e, int p, int x) {
		propa(idx, s, e);
		if(p < s || e < p) return;
		if(s == e) {
			T[idx].mn = x;
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, x);
		upd(idx << 1 | 1, m + 1, e, p, x);
		T[idx].mn = min(T[idx << 1].mn, T[idx << 1 | 1].mn);
	}

	void upd(int p, int x) { upd(1, 1, N + 1, p, x); }

	ll get(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return INF;
		if(p <= s && e <= q) return T[idx].mn;
		int m = s + e >> 1;
		return min(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}

	ll get(int p, int q) { return get(1, 1, N + 1, p, q); }

}segD, segE;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		bool inv = false;
		if(a > b) { inv = true; swap(a, b); }
		if(a > N || b <= N) { puts("-1"); return 0; }
		I[a] = inv;
		A[a] = b - N;
	}

	segD.init(1, 1, N + 1); segE.init(1, 1, N + 1);
	segD.upd(N + 1, 0);
	segE.upd(N + 1, 0);
	A[0] = N + 1;

	// for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	// for(int i = 1; i <= N; i++) printf("%d ", I[i]); puts("");

	for(int i = 1; i <= N; i++) {
		ll ed = segE.get(A[i] + 1, N + 1);
		ll de = segD.get(A[i] + 1, N + 1);
		if(A[i - 1] < A[i]) {
			segD.add(INF);
			segE.add(INF);
		}
		// printf("%d %lld %lld\n", i, ed, de);
		segD.upd(A[i - 1], ed);
		segE.upd(A[i - 1], de);
		segD.add(I[i]);
		segE.add(!I[i]);

		// for(int j = 1; j <= N + 1; j++) printf("%lld ", segD.get(j, j)); puts("");
		// for(int j = 1; j <= N + 1; j++) printf("%lld ", segE.get(j, j)); puts("");
	}

	ll ans = min(segD.get(1, N + 1), segE.get(1, N + 1));
	if(ans > N) puts("-1");
	else printf("%lld\n", ans);

	return 0;
}