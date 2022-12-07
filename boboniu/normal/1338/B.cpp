#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 123456;
int n;
bool dep[maxN];
vector<int> e[maxN];

void dfs(int u, int f)
{
	dep[u] = dep[f] ^ 1;
	for (auto v : e[u])
	{
		if (v == f)
			continue;
		dfs(v, u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	int parity = 0;
	int maxEdge = n - 1;
	if (n == 2)
	{
		cout << "1 1\n";
	}
	set<int> matchTo;
	for (int i = 1; i <= n; i++)
		if (e[i].size() == 1)
		{
			int v = e[i][0];
			if (matchTo.count(v))
				maxEdge--;
			matchTo.insert(v);
			parity |= (1 << dep[i]);
		}
	int minEdge = parity == 3 ? 3 : 1;
	cout << minEdge << " " << maxEdge << "\n";
	return 0;
}