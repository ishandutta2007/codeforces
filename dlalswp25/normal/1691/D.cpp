#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1LL << 60;

int N;
ll A[202020];
ll S[202020];
ll NS[202020];

struct SegTree {
	pli T[4 * 202020];

	void init(int idx, int s, int e, ll* A) {
		if(s == e) { T[idx] = {A[s], s}; return; }
		int m = s + e >> 1;
		init(idx << 1, s, m, A);
		init(idx << 1 | 1, m + 1, e, A);
		T[idx] = max(T[idx << 1], T[idx << 1 | 1]);
	}

	pli get(int idx, int s, int e, int p, int q) {
		if(q < p || q < s || e < p) return {-INF, 0};
		if(p <= s && e <= q) return T[idx];
		int m = s + e >> 1;
		return max(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}
}segl, segr, segp;

bool f(int l, int r) {
	if(r < l) return true;
	int p = segp.get(1, 1, N, l, r).second;
	ll mxr = segr.get(1, 1, N, p, r).first;
	ll mxl = max(NS[l - 1], segl.get(1, 1, N, l, p - 1).first);
	if(A[p] < mxl + mxr) return false;
	return f(l, p - 1) && f(p + 1, r);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%lld", &A[i]);
			S[i] = S[i - 1] + A[i];
			NS[i] = -S[i];
		}
		segl.init(1, 1, N, NS);
		segr.init(1, 1, N, S);
		segp.init(1, 1, N, A);
		puts(f(1, N) ? "YES" : "NO");
	}
	return 0;
}