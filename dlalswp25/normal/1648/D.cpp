#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int N, Q;
int A[3][505050];
ll S[3][505050];
int L[505050];
int R[505050];
int K[505050];
vector<int> V[505050];
vector<int> W[505050];

struct Node {
	ll mn, mx, lz;

	Node() : mn(INF), mx(-INF), lz(-INF) {}
};

struct SegTree {
	Node T[4 * 505050];

	void propa(int idx, int s, int e) {
		T[idx].mx = max(T[idx].mx, T[idx].lz - T[idx].mn);
		if(s != e) {
			T[idx << 1].lz = max(T[idx << 1].lz, T[idx].lz);
			T[idx << 1 | 1].lz = max(T[idx << 1 | 1].lz, T[idx].lz);
		}
		T[idx].lz = -INF;
	}

	void add(int idx, int s, int e, int p, ll x, ll y) {
		propa(idx, s, e);
		if(p < s || e < p) return;
		if(s == e) {
			T[idx].mn = x;
			T[idx].mx = y;
			return;
		}
		int m = s + e >> 1;
		add(idx << 1, s, m, p, x, y);
		add(idx << 1 | 1, m + 1, e, p, x, y);
		T[idx].mn = min(T[idx << 1].mn, T[idx << 1 | 1].mn);
		T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx);
	}

	void ers(int idx, int s, int e, int p) {
		propa(idx, s, e);
		if(p < s || e < p) return;
		if(s == e) {
			T[idx].mn = INF;
			T[idx].mx = -INF;
			return;
		}
		int m = s + e >> 1;
		ers(idx << 1, s, m, p);
		ers(idx << 1 | 1, m + 1, e, p);
		T[idx].mn = min(T[idx << 1].mn, T[idx << 1 | 1].mn);
		T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx);
	}

	void upd(int idx, int s, int e, int p, int q, ll x) {
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
		T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx);
	}

	ll get(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return -INF;
		if(p <= s && e <= q) return T[idx].mx;
		int m = s + e >> 1;
		return max(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}
}seg;

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 0; i < 3; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			S[i][j] = S[i][j - 1] + A[i][j];
		}
	}

	for(int i = 1; i <= Q; i++) {
		scanf("%d%d%d", &L[i], &R[i], &K[i]);
		V[L[i]].push_back(i);
	}

	ll ans = -INF;
	int id = 0;
	for(int i = 1; i <= N; i++) {
		ll t = max(S[0][i] - S[1][i - 1], seg.get(1, 1, Q, 1, id));
		for(int j : V[i]) {
			id++;
			W[R[j]].push_back(id);
			seg.add(1, 1, Q, id, K[j], t - K[j]);
		}

		for(int j : W[i - 1]) {
			seg.ers(1, 1, Q, j);
		}

		seg.upd(1, 1, Q, 1, id, S[0][i] - S[1][i - 1]);

		ans = max(ans, seg.get(1, 1, Q, 1, id) + S[1][i] + S[2][N] - S[2][i - 1]);
	}
	printf("%lld\n", ans);
	return 0;
}