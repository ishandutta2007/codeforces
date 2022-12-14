#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct el
{
	int a, b, c;

	bool operator<(const el& e) const
	{
		return c < e.c;
	}
};

int n, m, k, w;
char t[1024][16][16];
vector<el> e;

int par[1024];

int upar(int v)
{
	if (par[v] == -1)
		return v;
	return (par[v] = upar(par[v]));
}

vector<pair<int, int> > g[1024];

int dif(int v, int u)
{
	int d = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (t[v][i][j] != t[u][i][j])
				++d;
		}
	}
	return d;
}

bool us[1024];

void dfs(int v)
{
	for (int i = 0; i < (int) g[v].size(); ++i)
	{
		int u = g[v][i].first;
		int c = g[v][i].second;
		//~ printf("ED %d %d %d __ %d\n", v, u, c, n * m);
		if (!us[u])
		{
			us[u] = 1;
			if (c == n * m)
				printf("%d %d\n", u + 1, 0);
			else
				printf("%d %d\n", u + 1, v + 1);
			dfs(u);
		}
	}
}

int main()
{
	long long sl = 0;
	scanf("%d %d %d %d", &n, &m, &k, &w);

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; ++j)
			scanf("%s", t[i][j]);
	}

	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if (i == j)
			{
				continue;
			}
			el a;
			a.a = i;
			a.b = j;
			a.c = dif(i, j) * w;
			if (a.c > n * m)
				a.c = n * m;
			e.push_back(a);
		}
	}

	memset(par, -1, sizeof(par));
	sort(e.begin(), e.end());
	for (int i = 0; i < (int) e.size(); i++)
	{
		if (upar(e[i].a) != upar(e[i].b))
		{
			par[ upar(e[i].a) ] = upar(e[i].b);
			sl += e[i].c;
			g[ e[i].a ].push_back(make_pair(e[i].b, e[i].c));
			g[ e[i].b ].push_back(make_pair(e[i].a, e[i].c));
		}
	}

	sl += n * m;
	printf("%lld\n", sl);
	memset(us, 0, sizeof(us));
	us[0] = 1;
	printf("%d %d\n", 1, 0);
	dfs(0);
	return 0;
}