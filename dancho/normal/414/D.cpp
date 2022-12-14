#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int m, k, p;
vector<int> g[1<<20];

int dep[1<<20];

int d[1<<20];
long long ps[1<<20];

void dfs(int v)
{
	for (int i = 0; i < (int) g[v].size(); ++i)
	{
		int u = g[v][i];
		if (dep[u] == -1)
		{
			dep[u] = dep[v] + 1;
			++d[ dep[u] ];
			dfs(u);
		}
	}
}

int main()
{
	scanf("%d %d %d", &m, &k, &p);
	for (int i = 1; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	memset(dep, -1, sizeof(dep));
	dep[1] = 0;
	dfs(1);
	
	ps[0] = 0;
	for (int i = 1; i <= m; ++i)
	{
		ps[i] = ps[i-1] + d[i];
	}
	
	long long mx = 0;
	long long pr = 0;
	int s = 0;
	for (int i = 1; i <= m; ++i)
	{
		if (d[i] == 0)
			break;
		// I have enough coins for s + 1, s + 2, s + 3, ..., i.
		pr = pr + ps[i - 1] - ps[s];
		while (pr > p)
		{
			++s;
			pr -= (long long) d[s] * (i - s);
		}
		// pr <= p
		long long re = p - pr;
		mx = max(mx, (long long) ps[i] - ps[s] + min((long long) d[s], re / (i-s)));
	}
	
	if (mx > k)
		mx = k;
	printf("%d\n", (int) mx);
	return 0;
}