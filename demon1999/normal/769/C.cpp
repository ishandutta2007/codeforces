#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
const int MAXN = 1007;
char a[MAXN][MAXN];
int d[MAXN][MAXN];
int n, m;
char c[] = {'D', 'L', 'R', 'U'};
int dx[] = {1, 0, 0, -1}, dy[] = {0, -1, 1, 0};
const int INF = 1000 * 1000 * 1000 + 7;
bool ok(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int k;
	scanf("%d %d %d", &n, &m, &k);
	int sx = -1, sy = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", a[i]);
		for (int j = m; j >= 1; j--)
		{
			a[i][j] = a[i][j - 1];
			if (a[i][j] == 'X')
			{
				sx = i;
				sy = j;
				a[i][j] = '.';
			}
		}
	}
	if (k % 2 == 1)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = INF;
		}
	}
	d[sx][sy] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	while (!q.empty())
	{
		int x = q.front().fi, y = q.front().se;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (!ok(nx, ny) || a[nx][ny] != '.') continue;
			if (d[nx][ny] > d[x][y] + 1)
			{
				d[nx][ny] = d[x][y] + 1;
				q.push(mp(nx, ny));
			}
		}
	}
	int x = sx, y = sy;
	bool canGo = false;
	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d], ny = y + dy[d];
		if (ok(nx, ny) && a[nx][ny] == '.') canGo = true;
	}
	if (!canGo)
	{
		printf("IMPOSSIBLE\n");
		re 0;
	}
	for (int needMore = k - 1; needMore >= 0; needMore--)
	{
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (ok(nx, ny) && d[nx][ny] <= needMore)
			{
				x = nx;
				y = ny;
				printf("%c", c[dir]);
				break;
			}
		}
	}
	printf("\n");
}