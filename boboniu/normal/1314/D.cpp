#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
mt19937 rnd(random_device{}());

int n, k, w[100][100], dp[100][20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	int ans = (1 << 30);
	while (clock() <= 2.8 * CLOCKS_PER_SEC)
	{
		vector<int> e[2];
		e[0].push_back(0);
		for (int i = 1; i < n; i++)
			e[rnd() % 2].push_back(i);
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= k; j++)
				dp[i][j] = (1 << 30);
		dp[0][0] = 0;
		for (int t = 0; t < k; t++)
		{
			for (auto u : e[t % 2])
				for (auto v : e[(t + 1) % 2])
					dp[v][t + 1] = min(dp[v][t + 1], dp[u][t] + w[u][v]);
		}
		ans = min(ans, dp[0][k]);
	}
	cout << ans << endl;
}