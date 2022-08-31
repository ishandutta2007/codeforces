/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

set <int> path[N], non_path[N];
vector <int> g[N];
bool seen[N] = {0};
int deg[N] = {0};

int get_paths(int cur);
int solve(int cur);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++deg[u];
		++deg[v];
	}

	int root = 0;
	for (int i = 1; i <= n; ++i)
		if (deg[i] >= deg[root])
			root = i;

	get_paths(root);
	int len = solve(root);
	if (len == -1)
		cout << "-1\n";
	else
	{
		--len;
		while (len % 2 == 0)
			len /= 2;

		cout << len << '\n';
	}
}

int get_paths(int cur)
{
	seen[cur] = true;
	int p = 1, ctr = 0;
	bool ans = true;
	for (auto &i : g[cur])
	{
		if (!seen[i])
		{
			int x = get_paths(i);
			if (x == -1)
			{
				ans = false;
				non_path[cur].insert(i);
			}
			else
			{
				p = 1 + x;
				if (path[cur].find(x) == path[cur].end())
				{
					path[cur].insert(x);
					++ctr;
				}
			}
		}
	}

	if (ans and ctr <= 1)
		return p;
	return -1;
}

int solve(int cur)
{
	int paths = path[cur].size(), non_paths = non_path[cur].size();
	if (paths > 2 or !paths)
		return -1;

	int p1 = *(path[cur].begin()), p2 = *(path[cur].rbegin());
	if (paths == 2)
	{
		if (!non_paths)
			return 1 + p1 + p2;
		return -1;
	}

	if (!non_paths)
		return 1 + p1;

	if (non_paths >= 2)
		return -1;

	int np = *(non_path[cur].begin());
	path[np].insert(1 + p1);
	return solve(np);
}