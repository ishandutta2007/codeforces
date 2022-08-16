#include <iostream>
#include <vector>

using namespace std;

#define weight second
#define node first

typedef long long ll;
typedef pair <int, ll> pil;

const int N = 5e3 + 5;
const ll mx = 1e15;

ll dp[N][N];
bool seen[N];
vector <pil> g[N], h[N];
int ans = 0, n, m;

void solve(int cur)
{
	if (cur == n)
		return;

	seen[cur] = true;

	for (auto &i : g[cur])
	{
		if (!seen[i.node])
			solve(i.node);

		for (int j = 1; j <= n; ++j)
		{
			dp[cur][j] = min(dp[cur][j], dp[i.node][j-1] + i.weight);
		}
	}
}

void backtrack(int st, int dest, int ans)
{
	cout << st << ' ';

	if (st == dest)
		return;

	ll mn = mx;
	int p = 0;

	for (auto &i : g[st])
	{
		if (dp[i.node][ans-1] + i.weight < mn)
		{
			mn = dp[i.node][ans-1] + i.weight;
			p = i.node;
		}
	}

	backtrack(p, dest, ans-1);
}

int main()
{
	int t, u, v, w;
	cin >> n >> m >> t;

	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = mx;
	
	dp[n][1] = 0;
	solve(1);

	int ans = 0;

	for (int i = n; i >= 2; --i)
	{
		if (dp[1][i] <= t)
		{
			ans = i;
			break;
		}
	}

	cout << ans << '\n';
	backtrack(1, n, ans);
}