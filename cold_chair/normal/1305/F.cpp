#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int M = 1e6 + 105;

int bz[M], p[M], p0;

void sieve(int n) {
	fo(i, 2, n) {
		if(!bz[i]) p[++ p0] = i;
		for(int j = 1; i * p[j] <= n; j ++) {
			int k = i * p[j];
			bz[k] = 1;
			if(i % p[j] == 0) break;
		}
	}
}

const int N = 2e5 + 5;

int n; ll a[N];

ll u[1000], u0;

void fen(ll n) {
	u0 = 0;
	for(int i = 1; i <= p0 && (ll) p[i] * p[i] <= n; i ++) if(n % p[i] == 0) {
		u[++ u0] = p[i];
		while(n % p[i] == 0) n /= p[i];
	}
	if(n > 1) u[++ u0] = n;
}

map<ll, int> w;
map<ll, int> :: iterator it;

ll ans;

void check(ll x) {
	ll s = 0;
	fo(i, 1, n) {
		if(a[i] >= x) {
			ll y = a[i] % x;
			s += min(y, x - y);
		} else s += x - a[i];
		if(s > ans) return;
	}
	ans = s;
}

int main() {
	srand(time(0) + clock());
	sieve(1e6);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%lld", &a[i]);
	random_shuffle(a + 1, a + n + 1);
	fo(i, 1, n - 1) {
		swap(a[i], a[rand() % n + 1]);
	}
	fo(i, 1, min(n, 50)) {
		fo(j, -1, 1) {
			ll x = a[i] + j;
			if(x > 1) {
				fen(x);
				fo(k, 1, u0) w[u[k]] = 1;
			}
		}
	}
	ans = n;
	for(it = w.begin(); it != w.end(); it ++)
		check((*it).first);
	pp("%lld\n", ans);
}