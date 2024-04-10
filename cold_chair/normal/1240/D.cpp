#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3e5 + 5;

int T, n, a[N];

const ll mo = 23333333333333333;

ll mul(ll x, ll y) {
	ll z = (long double) x * y / mo;
	z = x * y - z * mo;
	if(z < 0) z += mo; else if(z >= mo) z -= mo;
	return z;
}

const ll w = 998244353;

ll aw[N];

int z[N], z0;

map<ll, int> bz;

ll ans;

int main() {
//	freopen("a.in", "r", stdin);
	aw[0] = 1; fo(i, 1, 300000) aw[i] = mul(aw[i - 1], w);
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		fo(i, 1, n) scanf("%d", &a[i]);
		ll s = 0;
		ans = 0;
		bz.clear();
		z0 = 0;
		bz[0] ++;
		fo(i, 1, n) {
			if(z0 > 0 && z[z0] == a[i]) s = (s - mul(aw[z0], z[z0]) + mo) % mo, z0 --; else
			z[++ z0] = a[i], s = (s + mul(aw[z0], z[z0])) % mo;
			ans += bz[s];
			bz[s] ++;
		}
		pp("%I64d\n", ans);
	}
}