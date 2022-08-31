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

const int N = 35, M = 55;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool seen[N] = {0};
vector <int> g[N];
ll x[N], y[N];

bool solve(int i, ll px, ll py, ll dist, int used);

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	ll dist = (1ll << M);
	if (solve(1, 0, 0, dist, -1))
	{
		cout << "YES\n";
		for (int i = 1; i <= n; ++i)
			cout << x[i] << ' ' << y[i] << '\n';
	}

	else
		cout << "NO";
}

bool solve(int i, ll px, ll py, ll dist, int used)
{
	seen[i] = true;
	x[i] = px;
	y[i] = py;
	if (g[i].size() > 4)
		return false;

	int d = (!used) ? 1 : 0;
	bool ans = 1;
	for (auto &j : g[i])
	{
		if (seen[j])
			continue;

		ans &= solve(j, px + dist*dir[d][0], py + dist*dir[d][1], dist/2 - 5, (d + 2) % 4);
		do
		{
			++d;
		}
		while (d == used);
	}

	return ans;
}