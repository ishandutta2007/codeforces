#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <int, pii> lake;

const int N = 55, INF = 2147483647;

#define row first
#define col second
#define land '*'
#define water '.'
#define lakeSize first
#define lakeStart second

bool seen[N][N];
char s[N][N];

int getLakeSize(int x, int y, int n, int m)
{
	queue <pii> q;
	q.push({x, y});

	int ans = 0;
	seen[x][y] = true;

	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();

		++ans;

		if (cur.row == 1 or cur.row == n or cur.col == 1 or cur.col == m)
			ans = -INF;

		for (int i = cur.row - 1; i <= cur.row + 1; ++i)
		{
			for (int j = cur.col - 1; j <= cur.col + 1; ++j)
			{
				if (i != cur.row and j != cur.col)
					continue;

				if (i < 1 or i > n or j < 1 or j > m)
					continue;

				if (s[i][j] == land)
					continue;

				if (!seen[i][j])
				{
					q.push({i, j});
					seen[i][j] = true;
				}
			}
		}
	}

	return max(0, ans);
}

void convToEarth(int x, int y, int n, int m)
{
	queue <pii> q;
	q.push({x, y});
	s[x][y] = land;

	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();

		for (int i = cur.row - 1; i <= cur.row + 1; ++i)
		{
			for (int j = cur.col - 1; j <= cur.col + 1; ++j)
			{
				if (i != cur.row and j != cur.col)
					continue;

				if (i < 1 or i > n or j < 1 or j > m)
					continue;

				if (s[i][j] == land)
					continue;

				q.push({i, j});
				s[i][j] = land;
			}
		}
	}
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> s[i][j];

	int lakes = 0;
	priority_queue <lake, vector <lake>, greater <lake> > pq;

	for (int i = 2; i < n; ++i)
	{
		for (int j = 2; j < m; ++j)
		{
			if (s[i][j] == water and !seen[i][j])
			{
				int sz = getLakeSize(i, j, n, m);

				if (sz)
				{
					++lakes;
					pq.push({sz, {i, j}});
				}
			}
		}
	}

	int ans = 0;
	//cout << lakes << endl;

	while (lakes > k)
	{
		lake cur = pq.top();
		pq.pop();

		ans += cur.lakeSize;
		convToEarth(cur.lakeStart.row, cur.lakeStart.col, n, m);

		--lakes;
	}

	cout << ans << '\n';

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cout << s[i][j];

		cout << '\n';
	}
}