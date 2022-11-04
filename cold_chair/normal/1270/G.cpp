#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e6 + 5;

int T, n, a[N], bz[N], z[N], z0;

void dg(int x) {
	if(bz[x]) {
		pp("%d\n", z0 - bz[x] + 1);
		fo(i, bz[x], z0) pp("%d ", z[i]); hh;
		return;
	}
	z[++ z0] = x; bz[x] = z0;
	dg(x - a[x]);
}

int main() {
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		fo(i, 1, n) bz[i] = 0; z0 = 0;
		fo(i, 1, n) scanf("%d", &a[i]);
		dg(1);
	}
}