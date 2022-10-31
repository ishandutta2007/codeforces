#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 7;
const int inf = 1000000;

int low[MAXN][MAXN], up[MAXN][MAXN], active[MAXN][MAXN], visit[MAXN], r[MAXN], c[MAXN];
int n, go[MAXN][MAXN];

void travel(int x) {
	visit[x] = 1;
	for(int i = x + 1; i <= n; i++) {
		if (go[x][i] < low[x][i] && !visit[i])
			continue;
		travel(i);
	}
}

int ans1 = inf, ans2 = -1;

void dfs(int x, int y) {
	if (x == n) {
		for(int i = 1; i <= n; i++)
			visit[i] = 0;
		travel(1);
		int tmp = 0;
		for(int i = 2; i <= n; i++)
			tmp += go[1][i];
		if (visit[n]) {
			int cost = 0;
			for(int i = 1; i <= n; i++)
				for(int j = i + 1; j <= n; j++)
					if (go[i][j] > 0) {
						cost += active[i][j];
						cost += go[i][j] * go[i][j];
					}
			if (tmp < ans1 || tmp == ans1 && cost > ans2)
				ans1 = tmp, ans2 = cost;
		}
		return;
	}
	int xx = x, yy = y;
	if (yy == n)
		xx++, yy = xx + 1;
	else
		yy++;
	for(go[x][y] = low[x][y]; go[x][y] <= up[x][y]; go[x][y]++) {
		r[y] += go[x][y];
		c[x] += go[x][y];
		int flag = 1;
		if (y == n) {
			if (x == 1) {
				if (c[x] > ans1)
					flag = 0;
			} else {
				if (r[x] != c[x])
					flag = 0;
			}
		}
		if (flag)
			dfs(xx, yy);
		r[y] -= go[x][y];
		c[x] -= go[x][y];
	}
}

int main() {

	scanf("%d", &n);
	for(int i = 1; i <= n * (n - 1) / 2; ++i) {
		int s, f, l, h, a;
		scanf("%d %d %d %d %d", &s, &f, &l, &h, &a);
		low[s][f] = l;
		up[s][f] = h;
		active[s][f] = a;
	}
	dfs(1, 2);
	if (ans1 == inf) {
		printf("-1 -1\n");
	} else {
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}