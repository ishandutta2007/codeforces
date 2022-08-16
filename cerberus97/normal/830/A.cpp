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

const int N = 2e3 + 5;
const ll inf = 1e15;

ll a[N], b[N], dp[N][N];
bool seen[N][N] = {0};

ll f(int n, int k, ll p);

int main()
{
	int n, k; ll p;
	cin >> n >> k >> p;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int j = 1; j <= k; ++j)
		cin >> b[j];

	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + k);
	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = i; j <= k; ++j)
	// 	{
	// 		dp[i][j] = min(dp[i][j - 1], max(abs(a[i] - b[j]) + abs(b[j] - p), dp[i - 1][j - 1]))
	// 	}
	// }

	// cout << dp[n][k];
	cout << f(n, k, p);
}

ll f(int n, int k, ll p)
{
	if (k < n)
		return inf;

	if (!n)
		return 0;

	if (!k)
		return inf;

	if (seen[n][k])
		return dp[n][k];

	seen[n][k] = true;
	dp[n][k] = min(f(n, k - 1, p), max(abs(a[n] - b[k]) + abs(b[k] - p), f(n - 1, k - 1, p)));
	return dp[n][k];
}