/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e3 + 5;
const ll inf = 1e10;

vector <int> g[N];
ll sz[N], dp[N][N][2], c[N], d[N], temp[N][2];

void get_size(int cur);
void solve(int cur);

int main()
{
	int n; ll b;
	cin >> n >> b >> c[1] >> d[1];
	for (int i = 2; i <= n; ++i)
	{
		int x;
		cin >> c[i] >> d[i] >> x;
		g[x].pb(i);
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k < 2; ++k)
				dp[i][j][k] = inf;

	get_size(1);
	solve(1);
	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = 0; j <= sz[i]; ++j)
	// 	{
	// 		cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
	// 	}

	// 	cout << endl;
	// }

	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (dp[1][i][0] <= b or dp[1][i][1] <= b)
			++ans;

		else
			break;
	}

	cout << ans;
}

void get_size(int cur)
{
	sz[cur] = 1;
	for (auto &i : g[cur])
	{
		get_size(i);
		sz[cur] += sz[i];
	}
}

void solve(int cur)
{
	dp[cur][0][0] = 0;
	dp[cur][0][1] = inf;
	dp[cur][1][0] = c[cur];
	dp[cur][1][1] = c[cur] - d[cur];
	int ctr = 1;
	for (auto &i : g[cur])
	{
		solve(i);
		for (int j = 0; j <= ctr; ++j)
			for (int k = 0; k < 2; ++k)
				temp[j][k] = dp[cur][j][k];
			
		for (int a = 0; a <= ctr; ++a)
		{
			for (int b = 1; b <= sz[i]; ++b)
			{
				dp[cur][a + b][0] = min(dp[cur][a + b][0], temp[a][0] + dp[i][b][0]);
				dp[cur][a + b][1] = min(dp[cur][a + b][1], temp[a][1] + min(dp[i][b][0], dp[i][b][1]));
			}
		}

		ctr += sz[i];
	}
}