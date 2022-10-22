#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

const int N = 5e5 + 100;

int T, n, m;
ll c[N], r[N], h[N];
map<ll, ll> mapa;

ll rnd() {
	ll x = 0;
	rep(i, 0, 18)
		x = x * 10 + rand() % 10;
	return x;
}

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &m);
		rep(i, 1, n) scanf ("%lld", c + i);
		rep(i, 1, n) r[i] = rnd();
		rep(i, 1, m) {
			int u, v;
			scanf ("%d%d", &u, &v);
			h[v] += r[u];
		}
		rep(i, 1, n) 
			mapa[h[i]] += c[i];
		ll out = 0;
		for (auto [x, y] : mapa) {
			if (x != 0)
				out = __gcd(out, y);
		}
		printf ("%lld\n", out);
		rep(i, 1, n) 
			h[i] = 0;
		mapa.clear();
	}
		
		
	
		
	return 0;
}