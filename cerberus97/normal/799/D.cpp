/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 5;
const int M = 40;

bool seen[M][N] = {0};
ll dp[M][N], temp[N], p[M];

ll f (int i, ll j);
ll ceil_div(ll a, ll b);

int main()
{
	ll a, b, h, w; int n;	
	cin >> a >> b >> h >> w >> n;
	if ((a <= h and b <= w) or (a <= w and b <= h))
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; ++i)
		cin >> temp[i];

	sort(temp, temp + n);
	int m = min(n, M);
	for (int i = n - 1, j = 1; j <= m; ++j, --i)
		p[j] = temp[i];

	int ans = N;
	for (int i = 1; i <= m; ++i)
	{
		ll x = ceil_div(a, h), y = ceil_div(b, h);
		if (f(i, x) * w >= b or f(i, y) * w >= a)
		{
			ans = i;
			break;
		}
	}

	if (ans == N)
		cout << -1;

	else
		cout << ans;
}

ll f (int i, ll j)
{
	if (i == 0)
	{
		if (j == 1)
			return 1;

		else
			return 0;
	}

	if (seen[i][j])
		return dp[i][j];

	seen[i][j] = true;
	dp[i][j] = max(min(N, f(i - 1, j) * p[i]), f(i - 1, ceil_div(j, p[i])));
	return dp[i][j];
}

ll ceil_div(ll a, ll b)
{
	return (a / b) + ((a % b) ? 1 : 0);
}