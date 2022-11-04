#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 19;


int a2[N];

int n;
char str[N][N];
int a[N][N];


#define low(x) ((x) & -(x))
int cnt[1 << 18];

ll f[N][1 << 18], b[N][1 << 18];

void fwt(ll *a, int n, int f) {
	for(int i = 1; i < n; i *= 2) for(int j = 0; j < n; j += 2 * i) ff(k, 0, i)
		a[i + j + k] += a[j + k] * f;
}

ll c[N][1 << 18];

ll solve(ll *a) {
	ll ans = 0;
	ff(i, 0, a2[n]) ans += a[i] * ((n - cnt[i]) & 1 ? -1 : 1);
	return ans;
}

ll ans[1 << 18];

ll val;

int d[N], m, p[N], us[N];

void dfs(int x) {
	if(x > m) {
		int s = 0, t = 0;
		fo(i, 1, m) {
			fo(j, 1, p[i] - 1) s += a2[t ++];
			t ++;
		}
		ans[s] += val;
		return;
	}
	fo(i, 1, m) if(!us[i]) {
		if(d[i] == d[i - 1] && !us[i - 1]) continue;
		us[i] = 1; p[x] = d[i];
		dfs(x + 1);
		us[i] = 0;
	}
}

void dg(int x, int y, int z) {
	if(z == n) {
		val = solve(c[x]);
		m = x;
		dfs(1);
		return;
	}
	if(z > n) return;
	fo(i, y, n - z) {
		ff(j, 0, a2[n]) c[x + 1][j] = c[x][j] * b[i][j];
		d[x + 1] = i;
		dg(x + 1, i, z + i);
	}
}

ll e[1 << 18];

int main() {
	a2[0] = 1; fo(i, 1, 18) a2[i] = a2[i - 1] * 2;
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%s", str[i] + 1);
		fo(j, 1, n) a[i][j] = str[i][j] - '0';
	}
	ff(i, 1, a2[n]) cnt[i] = cnt[i ^ low(i)] + 1;
	fo(i, 1, n) f[i][a2[i - 1]] = 1;
	ff(s, 1, a2[n]) {
		fo(i, 1, n) if(f[i][s]) {
			fo(j, 1, n) if(!(s >> (j - 1) & 1) && a[i][j]) {
				f[j][s ^ a2[j - 1]] += f[i][s];
			}
		}
	}
	ff(s, 1, a2[n]) fo(i, 1, n) {
		b[cnt[s]][s] += f[i][s];
	}
	fo(i, 1, n) fwt(b[i], a2[n], 1);
	c[0][0] = 1; fwt(c[0], a2[n], 1);
	dg(0, 1, 0);
	fo(i, 0, n - 2) {
		ff(s, 0, a2[n]) if(!(s >> i & 1))
			ans[s] -= ans[s ^ a2[i]];
	}
	ff(i, 0, a2[n - 1]) pp("%lld ", ans[i]); hh;
}