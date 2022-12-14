#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

int n, m;
char h[64], v[64];

vector<pii> g[64][64];

bool us[64][64];
int cnt;

void dfs(int x, int y)
{
	if (us[x][y])
		return;
	us[x][y] = 1;
	++cnt;
	for (int i = 0; i < (int) g[x][y].size(); i++)
	{
		int nx = g[x][y][i].first, ny = g[x][y][i].second;
		dfs(nx, ny);
	}
	
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%s", h);
	scanf("%s", v);

	for (int i = 0; i < n; i++)
	{
		if (h[i] == '<')
		{
			for (int j = 1; j < m; ++j)
			{
				g[i][j].push_back(make_pair(i, j - 1));
			}
		}
		else if (h[i] == '>')
		{
			for (int j = 0; j + 1 < m; ++j)
			{
				g[i][j].push_back(make_pair(i, j + 1));
			}
		}
	}

	for (int j = 0; j < m; ++j)
	{
		if (v[j] == '^')
		{
			for (int i = 1; i < n; ++i)
			{
				g[i][j].push_back(make_pair(i - 1, j));
			}
		}
		else if (v[j] == 'v')
		{
			for (int i = 0; i + 1 < n; ++i)
			{
				g[i][j].push_back(make_pair(i + 1, j));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			memset(us, 0, sizeof(us));
			cnt = 0;
			dfs(i, j);
			if (cnt != n * m)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	
	return 0;
}