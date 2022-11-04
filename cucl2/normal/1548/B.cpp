#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

const int maxn = 1 << 18;
ll inline gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct Segtree {
	ll dt[maxn << 1];
	void inline set(int a, ll x) {
		dt[a += maxn] = x;
		while (a >>= 1) dt[a] = gcd(dt[a << 1], dt[a << 1 | 1]);
	}
	ll inline get(int l, int r) {
		ll res = 0;
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = gcd(res, dt[l++]);
			if (r & 1) res = gcd(res, dt[--r]);
		}
		return res;
	}
} seg;

int N;
ll a[maxn];

void solve() {
	scanf("%d", &N);
	rep(i, N) scanf("%lld", a + i);
	for(int i = N - 1; i; --i) a[i] = abs(a[i] - a[i - 1]), seg.set(i, a[i]);
	int r = 1;
	ll g = 0;
	int ans = 1;
	repi(i, N - 1) {
		while (r < N && g != 1) g = gcd(g, a[r++]);
		if (r == N && g != 1) ++r;
		ans = max(ans, r - i);
		g = seg.get(i + 1, r - 1);
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}