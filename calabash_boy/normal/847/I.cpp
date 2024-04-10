#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 260

typedef long long LL;

int n, m;
int q, p;
char map[MAXN][MAXN];
int vst[MAXN][MAXN];
LL v[MAXN][MAXN];
int ans;

queue< pair<int, int> > que;

int main()
{
	scanf("%d%d%d%d", &n, &m, &q, &p);
	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			map[i][j] = getchar();
		getchar();
	}

	pair<int, int> pos;
	int x, y;
	int tmp;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] != '.' && map[i][j] != '*') {
				memset(vst, 0, sizeof(vst));

				vst[i][j] = q * (map[i][j] - 'A' + 1);
				que.push(make_pair(i, j));

				while (!que.empty()) {
					pos = que.front();
					que.pop();
					x = pos.first;
					y = pos.second;

					v[x][y] += vst[x][y];

					tmp = vst[x][y] >> 1;
					if (tmp) {
						if (x > 1 && map[x-1][y] != '*' && !vst[x-1][y]) {
							vst[x-1][y] = tmp;
							que.push(make_pair(x-1, y));
						}
						if (y > 1 && map[x][y-1] != '*' && !vst[x][y-1]) {
							vst[x][y-1] = tmp;
							que.push(make_pair(x, y-1));
						}
						if (x < n && map[x+1][y] != '*' && !vst[x+1][y]) {
							vst[x+1][y] = tmp;
							que.push(make_pair(x+1, y));
						}
						if (y < m && map[x][y+1] != '*' && !vst[x][y+1]) {
							vst[x][y+1] = tmp;
							que.push(make_pair(x, y+1));
						}
					}
				}
			}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (v[i][j] > p)
				ans++;

	printf("%d\n", ans);

	return 0;
}