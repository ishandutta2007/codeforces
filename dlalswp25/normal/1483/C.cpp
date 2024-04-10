#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 1010101010;
const ll INF = 1LL << 60;

int N;
int H[303030];
int B[303030];
ll E[303030];
ll D[303030];
vector<pii> V;

struct SegTree {
	ll T[1050505] = {0, };
	int base = 524288;

	void upd(int p, ll x) {
		p += base; p--;
		T[p] = x;
		while(p > 1) {
			p >>= 1;
			T[p] = max(T[p << 1], T[p << 1 | 1]);
		}
	}

	ll get(int p, int q) {
		if(q < p) return -INF;
		p += base; q += base;
		p--; q--;
		ll ret = -INF;
		while(p <= q) {
			if(p & 1) { ret = max(ret, T[p]); p++; }
			if(~q & 1) { ret = max(ret, T[q]); q--; }
			p >>= 1; q >>= 1;
		}
		return ret;
	}
}seg, seg2;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &H[i]);
	}
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

	ll ans = -INF;
	for(int i = 1; i <= N; i++) {
		if(i == 1) D[i] = E[i] = B[i];
		else {
			D[i] = -INF;
			while(V.size() && V.back().first > H[i]) {
				seg2.upd(V.back().second, -INF);
				V.pop_back();
			}
			int t = (V.size() ? V.back().second : 0);
			E[i] = seg.get(t, i - 1) + B[i];
			D[i] = max(E[i], seg2.get(1, t));
		}
		V.emplace_back(H[i], i);
		seg.upd(i, D[i]);
		seg2.upd(i, E[i]);
		//printf("%d %lld\n", i, D[i]);
	}

	printf("%lld\n", D[N]);

	return 0;
}