/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;
const ll INF = 1e16;

ll a[N], sum[N], best[N];
bool seen[N] = {0};
vector <int> g[N];

void findSums(int st);
ll solve(int cur);

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;

		g[u].pb(v);
		g[v].pb(u);
	}

	findSums(1);
	memset(seen, 0, sizeof(seen));
	ll ans = solve(1);

	if (ans <= -INF)
		cout << "Impossible";

	else
		cout << ans;
}

void findSums(int st)
{
	seen[st] = true;
	sum[st] = a[st];
	best[st] = -INF;

	for (auto i : g[st])
	{
		if (!seen[i])
		{
			findSums(i);
			sum[st] += sum[i];
			best[st] = max(best[st], best[i]);
		}
	}

	best[st] = max(best[st], sum[st]);
}

ll solve(int cur)
{
	seen[cur] = true;
	ll ans = -INF;
	ll mx1 = -INF, mx2 = -INF;

	for (auto i : g[cur])
	{
		if (!seen[i])
		{
			ans = max(ans, solve(i));

			if (best[i] >= mx1)
			{
				mx2 = mx1;
				mx1 = best[i];
			}

			else if (best[i] >= mx2)
			{
				mx2 = best[i];
			}
		}
	}

	if (mx2 > -INF)
		ans = max(ans, mx1 + mx2);

	return ans;
}