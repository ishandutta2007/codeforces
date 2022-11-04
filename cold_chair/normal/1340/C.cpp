#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 10005;

const int M = 1005;

int n, m, a[N], g, r;
int dis[N][M], bz[N][M];

struct P {
	int x, y;
	P(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};

int ans;

deque<P> q;

int main() {
	scanf("%d %d", &n, &m);
	fo(i, 1, m) scanf("%d", &a[i]);
	scanf("%d %d", &g, &r);
	sort(a + 1, a + m + 1);
	m = unique(a + 1, a + m + 1) - (a + 1);
	bz[1][0] = 1; q.push_front(P(1, 0));
	ans = 1e9;
	while(!q.empty()) {
		P b = q.front(); q.pop_front();
		int x = b.x, y = b.y;
		if(y == 0 && g >= n - a[x]) {
			ans = min(ans, dis[x][y] * (g + r) + n - a[x]);
		}
		if(x > 1) {
			int v = b.y + a[x] - a[x - 1];
			if(v < g) {
				if(!bz[x - 1][v]) {
					bz[x - 1][v] = 1;
					dis[x - 1][v] = dis[x][y];
					q.push_front(P(x - 1, v));
				}
			} else
			if(v == g) {
				if(!bz[x - 1][0]) {
					bz[x - 1][0] = 1;
					dis[x - 1][0] = dis[x][y] + 1;
					q.push_back(P(x - 1, 0));
				}
			}
		}
		if(x < m) {
			int v = b.y + a[x + 1] - a[x];
			if(v < g) {
				if(!bz[x + 1][v]) {
					bz[x + 1][v] = 1;
					dis[x + 1][v] = dis[x][y];
					q.push_front(P(x + 1, v));
				}
			} else
			if(v == g) {
				if(!bz[x + 1][0]) {
					bz[x + 1][0] = 1;
					dis[x + 1][0] = dis[x][y] + 1;
					q.push_back(P(x + 1, 0));
				}
			}
		}
	}
	pp("%d\n", ans == 1e9 ? -1 : ans);
}