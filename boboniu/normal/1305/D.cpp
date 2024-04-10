#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 1111;
int n, deg[maxN], deleted[maxN];
int e[maxN][2];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		cin >> e[i][0] >> e[i][1];
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 1; j <= n; j++)
			deg[j] = 0;
		for (int j = 1; j < n; j++)
		{
			int u = e[j][0], v = e[j][1];
			if (deleted[u] || deleted[v])
				continue;
			deg[u]++;
			deg[v]++;
		}
		vector<int> leaf;
		for (int j = 1; j <= n; j++)
			if (!deleted[j] && deg[j] == 1)
				leaf.push_back(j);
		assert(leaf.size() >= 2);
		cout << "? " << leaf[0] << " " << leaf[1] << endl;
		cout.flush();
		int ans;
		cin >> ans;
		if (ans == leaf[0] || ans == leaf[1])
		{
			cout << "! " << ans << endl;
			return 0;
		}
		deleted[leaf[0]] = deleted[leaf[1]] = 1;
	}
	for (int j = 1; j <= n; j++)
		if (!deleted[j])
			cout << "! " << j << endl;
}