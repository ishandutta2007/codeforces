#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2005;

char s1[N], s2[N];
int n1, n2;

namespace ac {
	int son[N][10], tot = 1, fq[N];
	int add(int x, int c) {
		if(!son[x][c]) son[x][c] = ++ tot, fq[tot] = x;
		return son[x][c];
	}
	int d[N], d0, fa[N], dep[N];
	void build_fail() {
		fo(i, 0, 9) son[0][i] = 1;
		d[d0 = 1] = 1;
		for(int i = 1; i <= d0; i ++) {
			int x = d[i];
			fo(c, 0, 9) if(son[x][c]) {
				int y = son[x][c];
				d[++ d0] = y;
				dep[y] = dep[x] + 1;
				int p = fa[x];
				while(!son[p][c]) p = fa[p];
				p = son[p][c];
				fa[y] = p;
			}
		}
	}
	int st;
	int p1[N][N], p2[N][N];
	void dg(int x, int y, int z1, int z2) {
		p1[st][x] = z1;
		p2[st][x] = z2;
		fo(c, 0, 9) if(son[x][c]) {
			int z3 = z1, z4 = z2;
			if(z3 == 1) {
				if(y <= n1) {
					z3 = (s1[y] == c) ? 1 : (c < s1[y] ? 0 : 2);
					if(y == 1 && c == 0) z3 = 0;
				}
			}
			if(z4 == 1) {
				if(y <= n2) {
					z4 = (s2[y] == c) ? 1 : (c < s2[y] ? 0 : 2);
					if(y == 1 && c == 0) z4 = 2;
				}
			}
			dg(son[x][c], y + 1, z3, z4);
		}
	}
	int up[N][10];
	
	int pd1(int x, int y, int c) {
		if(p1[x][y] != 1) return p1[x][y] == 2;
		int l = dep[y] - dep[x] + 1;
		if(l == 1 && c == 0) return 0;
		if(l > n1) return 0;
		return c >= s1[l];
	}
	int pd2(int x, int y, int c) {
		if(p2[x][y] != 1) return p2[x][y] == 0;
		int l = dep[y] - dep[x] + 1;
		if(l == 1 && c == 0) return 0;
		if(l > n2) return 0;
		return c <= s2[l];
	}
	int f[N][10][N], g[N];
	int calc(int x, int y) {
		int ans = 0;
		if(n1 == n2) {
			if(dep[x] - dep[y] == n1) {
				ans += (p1[y][x] != 0) && (p2[y][x] != 2);
			}
		} else {
			if(dep[x] - dep[y] == n1) ans += (p1[y][x] != 0);
			if(dep[x] - dep[y] == n2) ans += (p2[y][x] != 2);
		}
		return ans;
	}
	
	void build() {
		int x = 1;
		fo(i, 1, n1) {
			s1[i] -= '0';
			x = add(x, s1[i]);
		}
		x = 1;
		fo(i, 1, n2) {
			s2[i] -= '0';
			x = add(x, s2[i]);
		}
		build_fail();
		for(st = 1; st <= tot; st ++) {
			dg(st, 1, 1, 1);
		}
		fo(i, 1, tot) {
			fo(c, 0, 9) {
				int p = i;
				while(!son[p][c]) p = fa[p];
				p = son[p][c];
				up[i][c] = p;
			}
		}
		fo(x, 1, tot) {
			d0 = 0;
			for(int p = x; p; p = fq[p])
				d[++ d0] = p;
			fo(i, 1, d0) {
				int y = d[i];
				g[x] += calc(x, y);
			}
		}
		fo(x, 1, tot) fo(c, 0, 9) {
			int y = up[x][c];
			d0 = 0;
			for(int p = x; p; p = fq[p]) d[++ d0] = p;
			fo(i, dep[y] + 1, d0) {
				int z = d[i];
				int t = dep[x] - dep[z];
				if(n1 == n2) {
					if(t + 1 <= n1 && pd1(z, x, c) && pd2(z, x, c)) {
						f[x][c][n1 - t] ++;
					}
				} else {
					if(t + 1 <= n1 && pd1(z, x, c)) {
						f[x][c][n1 - t] ++;
					}
					if(t + 1 <= n2 && pd2(z, x, c)) {
						f[x][c][n2 - t] ++;
					}
				}
			}
			f[x][c][0] += g[y];
			fo(j, 1, 2000) f[x][c][j] += f[x][c][j - 1];
		}
	}
}

using ac :: tot;

const int inf = 1e9;

int n;

int f[N][N], fr[N][N][2];

int bz[N][N];

int ans3[N];

void dg(int i, int j) {
	if(i > n) return;
	fo(c, 0, 9) {
		int nj = ac :: up[j][c];
		int v = f[i][j] + ac :: f[j][c][n - i];
		if(v == f[i + 1][nj] && bz[i + 1][nj]) {
			ans3[i + 1] = c;
			dg(i + 1, nj);
			return;
		}
	}
}

int main() {
	scanf("%s", s1 + 1);
	n1 = strlen(s1 + 1);
	scanf("%s", s2 + 1);
	n2 = strlen(s2 + 1);
	ac :: build();
	scanf("%d", &n);
	fo(i, 0, n) fo(j, 1, tot) f[i][j] = -inf;
	f[0][1] = 0;
	fo(i, 0, n - 1) {
		fo(j, 1, tot) if(f[i][j] > -inf){
			fo(c, 0, 9) {
				int nj = ac :: up[j][c];
				int v = f[i][j] + ac :: f[j][c][n - i];
				if(v > f[i + 1][nj]) {
					f[i + 1][nj] = v;
				}
			}
		}
	}
//	fo(i, 0, n) {
//		fo(j, 1, tot) if(f[i][j] > -inf) {
//			pp("%d %d %d\n", i, j, f[i][j]);
//		}
//	}
	int ans = 0;
	fo(j, 1, tot) {
		ans = max(ans, f[n][j]);
	}
	int ans2 = 0;
	fo(i, n1 + 1, n2 - 1) if(i <= n) ans2 += n - i + 1;
	pp("%d\n", ans + ans2);
	fo(j, 1, tot) {
		if(f[n][j] == ans) bz[n][j] = 1;
	}
	fd(i, n - 1, 0) {
		fo(j, 1, tot) if(f[i][j] > -inf){
			fo(c, 0, 9) {
				int nj = ac :: up[j][c];
				int v = f[i][j] + ac :: f[j][c][n - i];
				if(v == f[i + 1][nj] && bz[i + 1][nj]) {
					bz[i][j] = 1;
				}
			}
		}
	}
	dg(0, 1);
	fo(i, 1, n) pp("%d", ans3[i]); hh;
}