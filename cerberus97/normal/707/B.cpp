#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int> > g[100005];
bool isStorage[100005] = {0};

int main()
{
	int n, m, k, u, v, l;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> l;

		g[u].push_back(make_pair(v, l));
		g[v].push_back(make_pair(u, l));
	}

	for (int i = 0; i < k; ++i)
	{
		cin >> u;
		isStorage[u] = true;
	}

	int ans = 2e9;

	for (int i = 1; i <= n; ++i)
	{
		if (!isStorage[i])
			continue;

		for (vector <pair <int, int> >::iterator j = g[i].begin(); j != g[i].end(); ++j)
		{
			if (!isStorage[j->first])
			{
				ans = min(ans, j->second);
			}
		}
	}

	if (ans == 2e9)
		cout << -1;

	else
		cout << ans;
}