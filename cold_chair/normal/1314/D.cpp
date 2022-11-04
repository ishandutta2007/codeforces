#include <bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int inf = 1e9;

const int N = 85;

int n, k, c[N], d[2][N], d0[2];
int a[N][N];
int dis[11][N];
int ans;

int main() {
	srand(time(0) + clock());
	scanf("%d %d", &n, &k);
	fo(i, 1, n) fo(j, 1, n)
		scanf("%d", &a[i][j]);
	ans = inf;
	fo(T, 1, 50000) {
		d0[0] = d0[1] = 0;
		fo(i, 1, n) {
			c[i] = rand() % 2;
			d[c[i]][++ d0[c[i]]] = i;
		}
		memset(dis, 127, sizeof dis);
		dis[0][1] = 0;
		fo(t, 0, k - 1) {
			fo(i, 1, n) if(dis[t][i] < inf)
				fo(j, 1, d0[!c[i]]) {
					int y = d[!c[i]][j];
					dis[t + 1][y] = min(dis[t + 1][y], dis[t][i] + a[i][y]);	
				}
		}
		ans = min(ans, dis[k][1]);
	}
	pp("%d\n", ans);
}