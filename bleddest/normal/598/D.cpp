#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef long double ld;

#define ft first
#define sd second
#define mp make_pair
#define pb push_back

const ll INF = ll(1e17);
const ld eps = ld(1e-8);

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<string> g;
vector<vector<int> > comp;
vector<int> comps;
vector<vector<int> > weight;
int cnt = 0;

int n, m, k;

inline bool good(int i, int j)
{
	return (i >= 0 && i < n && j >= 0 && j < m);
}

inline int calc(int i, int j)
{
	int ans = 0;
	for (int a = 0; a < 4; a++)
	{
		int x = i + dx[a];
		int y = j + dy[a];
		if (good(x, y))
			if (g[x][y] == '*')
				ans++;
	}
	return ans;
}

void dfs(int i, int j)
{
	comps[cnt] += weight[i][j];
	comp[i][j] = cnt;
	for (int a = 0; a < 4; a++)
	{
		int x = i + dx[a];
		int y = j + dy[a];
		if (good(x, y))
			if (g[x][y] != '*' && comp[x][y] == -1)
				dfs(x, y);
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d %d", &n, &m, &k);
	g.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
	}

	comp = vector<vector<int> >(n, vector<int>(m, -1));
	weight = vector<vector<int> >(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] != '*')
				weight[i][j] = calc(i, j);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (comp[i][j] == -1 && g[i][j] != '*')
			{
				comps.pb(0);
				dfs(i, j);
				cnt++;
			}
		}
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		printf("%d\n", comps[comp[x][y]]);
	}
}