#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 5005;

int n, st, en;
ll x[N], a[N], b[N], c[N], d[N];
ll f[2][N]; int o;

const ll inf = 1e18;

void cmin(ll &x, ll y) {
	x > y ? x = y : 0;
}

int h;

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d %d", &n, &st, &en);
	fo(i, 1, n) scanf("%I64d", &x[i]);
	fo(i, 1, n) scanf("%I64d", &a[i]);
	fo(i, 1, n) scanf("%I64d", &b[i]);
	fo(i, 1, n) scanf("%I64d", &c[i]);
	fo(i, 1, n) scanf("%I64d", &d[i]);
	memset(f[o], 127, sizeof f[o]);
	f[o][0] = 0;
	fo(i, 1, n) {
		memset(f[!o], 127, sizeof f[!o]);
		if(i == st) {
			h ++;
			fo(j, 0, n) if(f[o][j] < inf) {
				cmin(f[!o][j], f[o][j] + d[i] - x[i]);
				if(j) cmin(f[!o][j - 1], f[o][j] + c[i] + x[i]);
			}
		} else
		if(i == en) {
			h --;
			fo(j, 0, n) if(f[o][j] < inf) {
				cmin(f[!o][j], f[o][j] + a[i] + x[i]);
				cmin(f[!o][j + 1], f[o][j] + b[i] - x[i]);
			}
		} else {
			fo(j, 0, n) if(f[o][j] < inf) {
				if(j > 0) cmin(f[!o][j], f[o][j] + b[i] + c[i]);
				if(j + h > 0) cmin(f[!o][j], f[o][j] + d[i] + a[i]);
				if(j > 0 && j + h > 0) cmin(f[!o][j - 1], f[o][j] + c[i] + a[i] + 2 * x[i]);
				cmin(f[!o][j + 1], f[o][j] + b[i] + d[i] - 2 * x[i]);
			}
		}
		o = !o;
		if(i < n) {
			fo(j, 0, n) if(j <= 0 && j + h <= 0)
				f[o][j] = inf;
		}
		//fo(j, 0, i) {
			//pp("%I64d", f[o][j]);
		//} hh;
	}
	pp("%I64d\n", f[o][0]);
}