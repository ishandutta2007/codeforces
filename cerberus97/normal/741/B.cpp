/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5;

bool seen[N] = {0}, mem[N][N] = {0};
ll w[N], b[N], dp[N][N];
vector <int> g[N];
vector <vector <pii> > c;

void bfs(int st);
ll solve(int i, ll x);

int main()
{
	int n, m, W;
	cin >> n >> m >> W;

	for (int i = 1; i <= n; ++i)
		cin >> w[i];

	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
			bfs(i);
	}

	cout << solve(c.size() - 1, W);
}

void bfs(int st)
{
	vector <pii> cur;
	queue <int> q;

	seen[st] = true;
	q.push(st);
	cur.pb({w[st], b[st]});

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		for (auto i : g[temp])
		{
			if (!seen[i])
			{
				seen[i] = true;
				cur.pb({w[i], b[i]});
				q.push(i);
			}
		}
	}

	sort(cur.begin(), cur.end());
	c.pb(cur);
}

ll solve(int i, ll x)
{
	if (x == 0 or i == -1)
		return 0;

	if (mem[i][x])
		return dp[i][x];

	mem[i][x] = true;
	dp[i][x] = solve(i-1, x);
	ll totalW = 0, totalB = 0;

	for (auto j : c[i])
	{
		if (j.first > x)
			return dp[i][x];

		dp[i][x] = max(dp[i][x], j.second + solve(i-1, x-j.first));
		totalW += j.first;
		totalB += j.second;
	}

	if (totalW <= x)
		dp[i][x] = max(dp[i][x], totalB + solve(i-1, x-totalW));

	return dp[i][x];
}