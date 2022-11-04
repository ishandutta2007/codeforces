#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;

int n;
ll a[N];
int cnt[64];
int f[150][150];

const int inf = 1e9;

#define cmin(a, b) ((a) > (b) ? (a) = (b) : 0)
int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%I64d", &a[i]);
	}
	int n0 = n; n = 0;
	fo(i, 1, n0) if(a[i]) a[++ n] = a[i];
	fo(i, 1, n) {
		ff(j, 0, 64) if(a[i] >> j & 1) cnt[j] ++;
	}
	ff(j, 0, 64) if(cnt[j] > 2) {
		pp("3\n"); return 0;
	}
	int ans = inf;
	fo(u, 1, n) fo(v, u + 1, n) if(((a[u] & a[v]) > 0)) {
		fo(i, 1, n) fo(j, 1, n) f[i][j] = inf;	
		fo(i, 1, n) fo(j, i + 1, n) if((a[i] & a[j]) > 0 && (i != u || j != v)) f[i][j] = f[j][i] = 1;
		fo(k, 1, n) fo(i, 1, n) fo(j, 1, n) cmin(f[i][j], f[i][k] + f[k][j]);
		fo(i, 1, n) if(i != u && i != v) ans = min(ans, f[i][u] + 1 + f[i][v]);
	}
	pp("%d\n", ans >= inf ? -1 : ans);
}