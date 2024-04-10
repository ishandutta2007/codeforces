#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1005;

int n, m, t;
char s[N][N];
ll x, y, z;

int mov[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};


int bz[N][N], tt;

int siz[N];

void dg(int x, int y) {
	if(bz[x][y]) return;
	bz[x][y] = tt;
	siz[tt] ++;
}

int bx[N][N];

int d[N * N][2], d0;

ll dis[N][N];

int main() {
	scanf("%d %d %d", &n, &m, &t);
	fo(i, 1, n) scanf("%s", s[i] + 1);
	fo(i, 1, n) fo(j, 1, m) dis[i][j] = 2e18;
	fo(i, 1, n) {
		fo(j, 1, m) {
			fo(k, 0, 3) {
				int u = i + mov[k][0], v = j + mov[k][1];
				if(u > 0 && v > 0 && u <= n && v <= m && s[i][j] == s[u][v]) {
					bz[i][j] = 1;
				}
			}
			if(bz[i][j]) {
				bx[i][j] = 1;
				dis[i][j] = 0;
				d[++ d0][0] = i;
				d[d0][1] = j;
			}
		}
	}
	for(int i = 1; i <= d0; i ++) {
		int x = d[i][0], y = d[i][1];
		fo(k, 0, 3) {
			int u = x + mov[k][0], v = y + mov[k][1];
			if(u > 0 && v > 0 && u <= n && v <= m && !bx[u][v])  {
				bx[u][v] = 1;
				dis[u][v] = dis[x][y] + 1;
				d[++ d0][0] = u; d[d0][1] = v;
			}
		}
	}
	fo(ii, 1, t) {
		scanf("%lld %lld %lld", &x, &y, &z);
			if(z <= dis[x][y]) {
				pp("%c\n", s[x][y]);
			} else {
				int v = s[x][y] - '0';
				v ^= (z - dis[x][y]) & 1;
				pp("%d\n", v);
			}
	}
}