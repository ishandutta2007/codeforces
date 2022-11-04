#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
#define fl fflush(stdout)
using namespace std;

const int N = 505;

int n, k;
int a[N], bz[N];
int x, y, d[N], d0;
int b[N], b0, b2[N];

int cmpd(int x, int y) {
	return a[x] < a[y];
}

int t[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &k);
	if(k <= n / 2) {
		fo(i, 1, k) {
			pp("? ");
			b0 = 0;
			fo(j, 1, n) if(!bz[j] && b0 < k) {
				pp("%d ", j);
				b0 ++;
			}
			hh; fl;
			scanf("%d %d", &x, &y);
			bz[x] = 1; a[x] = y;
			d[i] = x;
		}
		sort(d + 1, d + k + 1, cmpd);
		pp("? ");
		fo(i, 1, k) pp("%d ", d[i]);
		hh; fl;
		scanf("%d %d", &x, &y);
		fo(i, 1, k) if(x == d[i]) {
			pp("! %d\n", i); return 0;
		}
	}
	d0 = n - k + 1;
	fo(i, 1, d0) {
		pp("? ");
		b0 = 0;
		fo(j, 1, n) if(!bz[j] && b0 < k) {
			pp("%d ", j);
			b0 ++;
		}
		hh; fl;
		scanf("%d %d", &x, &y);
		bz[x] = i; a[x] = y; d[i] = x;
	}
	int v = d[d0];
	sort(d + 1, d + d0 + 1, cmpd);
	int ax = x, ay = y;
	fo(i, 1, d0) if(d[i] == v) {
		v = i; break;
	}
	int u, ut;
	if(v > 1) u = d[v - 1], ut = 0; else u = d[v + 1], ut = 1;
	int ans = 1;
	fo(i, 1, n) if(!bz[i]) {
		pp("? %d %d ", d[v], u);
		fo(j, 1, n) if(i != j && !bz[j]) pp("%d ", j);
		hh; fl;
		scanf("%d %d", &x, &y);
		t[i] = ut ^ (y != ay);
		ans += !t[i];
	}
	pp("! %d\n", ans);
	
}