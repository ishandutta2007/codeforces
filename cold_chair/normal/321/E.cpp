#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

#define gc getchar

const int N = 4005;

int n, k;
int a[N][N], s[N][N];

int calc(int x, int y) {
	return s[y][y] - s[y][x - 1] - s[x - 1][y] + s[x - 1][x - 1];
}

struct P {
	ll x, y;
	P(ll _x = 0, ll _y = 0) {
		x = _x, y = _y;
	}
};

bool operator < (P a, P b) { return a.x == b.x ? a.y > b.y : a.x < b.x;}

P f[N];

struct nod {
	int x, l, r;
} d[N];

int st, en;

ll xs;

P ca(int x, int y) {
	P g = f[x];
	g.x += xs + calc(x + 1, y);
	g.y ++;
	return g;
}

void dp(ll _xs) {
	xs = _xs;
	
	st = en = 1;
	d[1] = (nod) {0, 1, n};
	f[0] = P(0, 0);
	fo(i, 1, n) {
		int u = d[st].x;
		f[i] = ca(d[st].x, i);
		
		if(++ d[st].l > d[st].r) st ++;
		
		while(st <= en) {
			if(ca(i, d[en].l) < ca(d[en].x, d[en].l)) {
				en --;
			} else break;
		}
		int as = i + 1;
		if(st <= en) {
			as = d[en].r + 1;
			for(int l = d[en].l, r = d[en].r; l <= r; ) {
				int m = l + r >> 1;
				if(ca(i, m) < ca(d[en].x, m)) as = m, r = m - 1; else l = m + 1;
			}
			d[en].r = as - 1;
		}
		if(as <= n) {
			d[++ en] = (nod) {i, as, n};
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	fo(i, 1, n) {
		fo(j, 1, n) {
			char c = ' ';
			while(c < '0' || c > '9') c = gc();
			a[i][j] = c - '0';
			s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
		}
	}
	ll as = 0;
	for(ll l = -2e8, r = 2e8; l <= r; ) {
		ll m = l + r >> 1;
		dp(m);
		if(f[n].y >= k) as = m, l = m + 1; else r = m - 1;
	}
	dp(as);
	ll ans = f[n].x - as * k;
	pp("%lld\n", ans / 2);
}