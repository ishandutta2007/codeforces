#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 5e5 + 5;

int T, n, k, x, y, z;
int fi[N], to[N * 2], nt[N * 2], tot, v[N * 2];

void link(int x, int y, int z) {
	nt[++ tot] = fi[x], to[tot] = y, v[tot] = z, fi[x] = tot;
}

ll f[N][2], bz[N];
ll p[N], p0;

int cmp(ll x, ll y) { return x > y;}

void dg(int x) {
	bz[x] = 1;
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i]; if(bz[y]) continue;
		dg(y);
	}
	p0 = 0;
	ll sum = 0;
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i]; if(bz[y]) continue;
		if(f[y][1] < f[y][0] + v[i]) {
			sum += f[y][0] + v[i];
			p[++ p0] = f[y][1] - (f[y][0] + v[i]);
		} else sum += f[y][1];
	}
	sort(p + 1, p + p0 + 1, cmp);
	fo(i, 1, p0) p[i] += p[i - 1];
	if(p0 > k - 1) f[x][0] = p[p0 - (k - 1)] + sum; else
	f[x][0] = sum;
	if(p0 > k) f[x][1] = p[p0 - k] + sum; else
	f[x][1] = sum;
	bz[x] = 0;
}

int main() {
//	freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		tot = 0; fo(i, 1, n) fi[i] = bz[i] = 0;
		scanf("%d %d", &n, &k);
		fo(i, 1, n - 1) {
			scanf("%d %d %d", &x, &y, &z);
			link(x, y, z); link(y, x, z);
		}
		dg(1);
		pp("%I64d\n", max(f[1][0], f[1][1]));
	}
}