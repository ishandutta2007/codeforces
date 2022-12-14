#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> pii;

bool us[1<<20];
int n, m;
vector<int> g[1<<20];
int pr[1<<20];
pii p[1<<20];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i].first);
		p[i].second = i;
		pr[i] = p[i].first;
	}

	for (int i = 0; i < m; i++)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		g[j].push_back(k);
		g[k].push_back(j);
	}

	int ans = 0;
	memset(us, 0, sizeof(us));
	sort(p + 1, p + n + 1, greater<pii>());
	for (int i = 1; i <= n; ++i)
	{
		int v = p[i].second;
		us[v] = 1;
		for (int j = 0; j < (int) g[v].size(); ++j)
		{
			int u = g[v][j];
			if (!us[u])
			{
				ans += pr[u];
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}