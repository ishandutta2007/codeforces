/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

vector <int> g[N];
bool univ[N] = {0}, seen[N] = {0};
int s[N];

ll solve(int cur, int k);

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 2*k; ++i)
	{
		int u;
		cin >> u;
		univ[u] = true;
	}	

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	cout << solve(1, k);
}

ll solve(int cur, int k)
{
	seen[cur] = true;
	s[cur] = univ[cur];
	ll ans = 0;
	for (auto &i : g[cur])
	{
		if (!seen[i])
		{
			ans += solve(i, k);
			s[cur] += s[i];
		}
	}

	return ans + min(s[cur], 2*k - s[cur]);
}