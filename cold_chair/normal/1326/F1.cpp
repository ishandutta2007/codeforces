#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 15;

#define low(x) ((x) & -(x))

int a2[N];

int n, m;
char s[N][N];
int a[N][N];


int us[N], w[N];

int t[8][5100][8], t0[8];

void dfs(int x) {
	if(x > m) {
		t0[m] ++;
		fo(i, 1, m) t[m][t0[m]][i] = w[i];
		return;
	}
	fo(i, 1, m) if(!us[i]) {
		us[i] = 1;
		w[x] = i;
		dfs(x + 1);
		us[i] = 0;
	}
}

int cho[N];

int p[N], p0, q[N], q0;
ll f[1 << 7][N], g[1 << 7][N];

ll ans[1 << 14];

int d[1000005][2], d0;

void dg(int x, int y) {
	if(n - x + 1 < y) return;
	if(y < 0) return;
	if(x > n) {
		p0 = q0 = 0;
		fo(i, 1, n) if(cho[i]) p[++ p0] = i; else
			q[++ q0] = i;
			
//		fo(i, 1, p0) pp("%d ", p[i]); hh;
//		fo(i, 1, q0) pp("%d ", q[i]); hh; hh;
		
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		
		fo(i, 1, t0[p0]) {
			int s = 0;
			fo(j, 2, p0) {
				s += a2[j - 2] * a[p[t[p0][i][j]]][p[t[p0][i][j - 1]]];
			}
			f[s][p[t[p0][i][p0]]] ++;
		}
		
		fo(i, 1, t0[q0]) {
			int s = 0;
			fo(j, 2, p0) {
				s += a2[j - 2] * a[q[t[q0][i][j]]][q[t[q0][i][j - 1]]];
			}
			g[s][q[t[q0][i][1]]] ++;
		}		
		
		d0 = 0;
		ff(s2, 0, a2[q0 - 1]) fo(j, 1, n) if(g[s2][j])
			d[++ d0][0] = s2, d[d0][1] = j;
			
		ff(s1, 0, a2[p0 - 1]) fo(i, 1, n) if(f[s1][i])
			fo(k, 1, d0) {
				int s2 = d[k][0], j = d[k][1];
				ans[s1 | (s2 << p0) | (a[i][j] ? a2[p0 - 1] : 0)] += f[s1][i] * g[s2][j];
			}
		return;
	}
	cho[x] = 1; dg(x + 1, y - 1);
	cho[x] = 0; dg(x + 1, y);
}

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	a2[0] = 1; fo(i, 1, 14) a2[i] = a2[i - 1] * 2;
	
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%s", s[i] + 1);
		fo(j, 1, n) a[i][j] = s[i][j] - '0';
	}
	
	
	for(m = 1; m <= 7; m ++) dfs(1);
	m = (n + 1) / 2;
	dg(1, m);
	ff(i, 0, a2[n - 1]) pp("%lld ", ans[i]); hh;
}