/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, A = 1e6 + 5, M = log2(A) + 1;

bool bit[N][M], seen[N] = {0};
ll dp[N][M][2] = {0};
vector <int> g[N];
int a[N];

ll solve(int cur);

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
	{
		int temp = a[i];
		for (int j = 0; j < M; ++j)
		{
			bit[i][j] = temp % 2;
			temp /= 2;
		}
	}

	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	cout << solve(1) << '\n';
}

ll solve(int cur)
{
	seen[cur] = true;
	for (int j = 0; j < M; ++j)
		dp[cur][j][bit[cur][j]] = 1;

	ll ans = a[cur];
	for (auto &i : g[cur])
	{
		if (!seen[i])
		{
			ans += solve(i);
			for (int j = 0; j < M; ++j)
			{
				ll temp = dp[cur][j][0] * dp[i][j][1] + dp[cur][j][1] * dp[i][j][0];
				ans += (1 << j) * temp;
				dp[cur][j][0] += dp[i][j][bit[cur][j]];
				dp[cur][j][1] += dp[i][j][!bit[cur][j]];
			}
		}
	}

	return ans;
}