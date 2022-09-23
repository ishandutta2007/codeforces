#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
ll A[101010];
ll B[101010];
ll D[101010];
ll S[101010];

struct SegTree {
	ll T[4 * 101010];

	void upd(int idx, int s, int e, int p, ll x) {
		if(p < s || e < p) return;
		if(s == e) { T[idx] = x; return; }
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, x);
		upd(idx << 1 | 1, m + 1, e, p, x);
		T[idx] = max(T[idx << 1], T[idx << 1 | 1]);
	}

	ll get(int idx, int s, int e, int p, int q) {
		if(q < p || q < s || e < p) return -(1LL << 60);
		if(p <= s && e <= q) return T[idx];
		int m = s + e >> 1;
		return max(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}
}seg1, seg2;

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	for(int i = 1; i <= N; i++) {
		D[i] = B[i] - A[i];
		S[i] = S[i - 1] + D[i];
	}
	for(int i = 1; i <= N; i++) seg1.upd(1, 1, N, i, S[i]);
	for(int i = 1; i <= N; i++) seg2.upd(1, 1, N, i, -S[i]);

	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		if(S[l - 1] != S[r]) { puts("-1"); continue; }
		if(S[l - 1] > -seg2.get(1, 1, N, l, r)) { puts("-1"); continue; }
		printf("%lld\n", seg1.get(1, 1, N, l, r) - S[l - 1]);
	}
	return 0;
}