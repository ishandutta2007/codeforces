#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;


int n, l[N], h[N], mi[N], mx[N];
vector<int> a[N];

int d[N], d0;

map<int, int> bz;

#define low(x) ((x) & -(x))

int f[N];

void add(int x, int y) {
	while(x <= d0) {f[x] ++, x += low(x);}
}

int sum(int x) {
	int s = 0;
	for(; x; x -= low( x))
		s += f[x];
	return s;
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%d", &l[i]);
		a[i].resize(l[i]);
		ff(j, 0, l[i]) scanf("%d", &a[i][j]);
		mi[i] = 1e9;
		ff(j, 0, l[i]) {
			if(a[i][j] > mi[i]) h[i] = 1;
			mi[i] = min(mi[i], a[i][j]);
			mx[i] = max(mx[i], a[i][j]);
		}
		if(!h[i]) {
			d[++ d0] = mi[i];
			d[++ d0] = mx[i];
		} else {
		}
	}
	ll ans = 0;
	sort(d + 1, d + d0 + 1);
	d0 = unique(d + 1, d + d0 + 1) - (d + 1);
	fo(i, 1, d0) bz[d[i]] = i;
	int h0 = 0;
	fo(i, 1, n) if(!h[i]) {
		add(bz[mi[i]], 1);
		h0 ++;
	}
	fo(i, 1, n) if(!h[i]) {
		ans += sum(bz[mx[i]] - 1);
	}
	ans += (ll) n * n - (ll) h0 * h0;
	pp("%lld\n", ans);
}