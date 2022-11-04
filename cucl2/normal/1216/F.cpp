#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int maxn = 1 << 18;

struct ZkwSeg {
	ll dt[maxn << 1];
	ZkwSeg() { memset(dt, Inf, sizeof(dt)); }
	void inline add(int a, ll x) {
		a += maxn;
		dt[a] = min(dt[a], x);
		while (a >>= 1) dt[a] = min(dt[a << 1], dt[a << 1 | 1]);
	}
	ll inline get(int l, int r) {
		ll res = 1e18;
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = min(res, dt[l++]);
			if (r & 1) res = min(res, dt[--r]);
		}
		return res;
	}
} seg;

int N, K;
char s[maxn];

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", s + 1);
	seg.add(0, 0);
	repi(i, N) {
		int rgl = i, rgr = i;
		if (s[i] == '1') rgl = max(1, i - K), rgr = min(N, i + K);
		ll val = seg.get(rgl - 1, N);
		seg.add(rgr, val + i);
	}
	printf("%lld\n", seg.get(N, N));
	return 0;
}