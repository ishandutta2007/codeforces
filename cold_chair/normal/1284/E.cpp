#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2600;

int n;
struct P {
	ll x, y;
	P(ll _x = 0, ll _y = 0) {
		x = _x, y = _y;
	}
};

P a[N];

P operator - (P a, P b) {
	return P(a.x - b.x, a.y - b.y);
}

ll operator ^ (P a, P b) {
	return a.x * b.y - a.y * b.x;
}

int d[N], d0;

P b[N];

int cmpd(int x, int y) {
	if((b[x].y > 0) != (b[y].y > 0))
		return b[x].y < b[y].y;
	return (b[x] ^ b[y]) > 0;
}

ll ans;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%lld %lld", &a[i].x, &a[i].y);
	ans = (ll) n * ((ll) (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24);
	fo(i, 1, n) {
		d0 = 0;
		fo(j, 1, n) if(i != j)
			d[++ d0] = j, b[j] = a[j] - a[i];
//		fo(j, 1, d0) fo(a1, 1, d0) if(a1 != j) fo(a2, a1 + 1, d0) if(a2 != j)
//			fo(a3, a2 + 1, d0) if(a3 != j)
//				if((b[d[j]] ^ b[d[a1]]) < 0 && (b[d[j]] ^ (b[d[a2]])) < 0 && (b[d[j]] ^ b[d[a3]]) < 0)
//					ans --;
		sort(d + 1, d + d0 + 1, cmpd);
		int l = 1, r = d0 + 1;
		while(r > 1 && (b[d[1]] ^ b[d[r - 1]]) < 0) r --;
		fo(j, 1, d0) {
			int x = d[j];
			while(l < j && (b[x] ^ b[d[l]]) >= 0) l ++;
			while(r <= j || (r <= d0 && (b[x] ^ b[d[r]]) >= 0)) r ++;
			ll cnt = (j - l) + (d0 - r + 1);
			ans -= cnt * (cnt - 1) * (cnt - 2) / 6;
		}
	}
	pp("%lld\n", ans);
}