#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;   

const int N = 1e5 + 5;

int n, m, k, p;
int h[N], a[N];

struct P {
	int x; ll y;
	P(int _x = 0, ll _y = 0) {
		x = _x, y = _y;
	}
};

bool operator < (P a, P b) {
	return a.y > b.y;
}

priority_queue<P> s;

ll divs(ll x, ll y) {
	return x / y + (x % y != 0);
}

ll c[N];

int pd(ll x) {
	while(s.size()) s.pop();
	fo(i, 1, n) if(x < a[i]) return 0;
	fo(i, 1, n) c[i] = x, s.push(P(i, c[i] / a[i] + 1));
	ll sy = 0;
	fo(ti, 1, m) {
		while(s.top().y - ti == 0) {
			P b = s.top(); s.pop();
			ll z = c[b.x] - (ll) ti * a[b.x];
			ll t = divs(-z, p);
			if(t > sy) return 0;
			sy -= t;
			c[b.x] += t * p;
			s.push(P(b.x, c[b.x] / a[b.x] + 1));
		}
		sy += k;
	}
	fo(i, 1, n) {
		c[i] -= (ll) m * a[i];
		if(c[i] < h[i]) sy -= divs(h[i] - c[i], p);
	}
	return sy >= 0;
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &k, &p);
	fo(i, 1, n) scanf("%d %d", &h[i], &a[i]);
	ll ans;
	for(ll l = 0, r = 1e18; l <= r; ) {
		ll mi = l + r >> 1;
		if(pd(mi)) ans = mi, r = mi - 1; else l = mi + 1;
	}
	pp("%I64d\n", ans);
}