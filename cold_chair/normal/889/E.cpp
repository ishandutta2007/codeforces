#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int n; ll x;

struct P {
	ll x, y;
	P(ll _x = 0, ll _y = 0) {
		x = _x, y = _y;
	}
};

bool operator < (P a, P b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

multiset<P> s;
multiset<P> :: iterator it;

P d[N * 60]; int d0;

void ins(P a) {
	if(s.size() && (*--s.end()).x >= a.x) {
		P b = *s.lower_bound(a);
		if(b.y >= a.y) return;
	}
	while(s.size() && (*s.begin()).x <= a.x) {
		P b = *--s.upper_bound(a);
		if(b.y > a.y) break;
		s.erase(b);
	}
	s.insert(a);
}

int main() {
	scanf("%d", &n);
	scanf("%lld", &x);
	s.insert(P(x - 1, 0));
	fo(i, 2, n) {
		scanf("%lld", &x);
		d0 = 0;
		for(it = --s.end(); ; it --) {
			P a = *it;
			if(a.x < x) break;
			d[++ d0] = a;
			if(it == s.begin()) break;
		}
		fo(j, 1, d0) s.erase(d[j]);
		fo(j, 1, d0) {
			ll v = d[j].x / x;
			ins(P(d[j].x % x, d[j].y + v * x * (i - 1)));
			ins(P(x - 1, d[j].y + (v - 1) * x * (i - 1)));
		}
	}
	ll ans = 0;
	for(it = s.begin(); it != s.end(); it ++) {
		P a = *it;
		ans = max(ans, a.y + a.x * n);
	}
	pp("%lld\n", ans);
}