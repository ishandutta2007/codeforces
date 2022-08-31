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
#define sq(x) (x) * (x)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5;
const ll inf = 1e12;
const double pi = 3.1415926535897932384626433832795;

ll x[N], y[N], r[N], a[N], dp[N][3][3];
bool seen[N][3][3] = {0};
vector <int> g[N];

ll f(int i, int s1, int s2);
ll distSq(int i, int j);

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i] >> r[i];
		a[i] = r[i] * r[i];
	}

	r[0] = inf;
	for (int i = 1; i <= n; ++i)
	{
		int p = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (r[j] > r[i] and distSq(i, j) <= a[j] and r[j] < r[p])
				p = j;
		}

		g[p].pb(i);
	}

	ll ans = 0;
	for (auto &i : g[0])
		ans += f(i, 1, 1);

	cout << fixed << setprecision(12) << ans * pi;
}

ll f(int i, int s1, int s2)
{
	if (seen[i][s1 + 1][s2 + 1])
		return dp[i][s1 + 1][s2 + 1];

	ll temp = a[i] * s1;
	for (auto &j : g[i])
		temp += f(j, -s1, s2);

	ll ans = temp;
	temp = a[i] * s2;
	for (auto &j : g[i])
		temp += f(j, s1, -s2);

	ans = max(ans, temp);
	seen[i][s1 + 1][s2 + 1] = true;
	dp[i][s1 + 1][s2 + 1] = ans;
	return ans;
}

ll distSq(int i, int j)
{
	return sq(x[i] - x[j]) + sq(y[i] - y[j]);
}