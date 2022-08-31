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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, M_SZ = 30;

class gaussian
{
	public:
	typedef int mat_type;
	int pr[M_SZ];

	void rref(mat_type a[M_SZ], int m, int n)
	{
		for (int i = 0; i < n; ++i)
			pr[i] = -1;

		int start_row = 0;
		for (int k = 0; k < n and start_row < m; ++k)
		{
			int pivot_row = start_row;
			for (int i = start_row; i < m; ++i)
				if (a[i] > a[pivot_row])
					pivot_row = i;

			swap(a[start_row], a[pivot_row]);
			if (a[start_row] & (1 << (n - k - 1)))
			{
				for (int i = start_row + 1; i < m; ++i)
					if (a[i] & (1 << (n - k - 1)))
						a[i] ^= a[start_row];

				pr[k] = start_row++;
			}
		}

		for (int k = n - 1; k >= 0; --k)
			if (pr[k] != -1)
				for (int i = pr[k] - 1; i >= 0; --i)
					if (a[i] & (1 << (n - k - 1)))
						a[i] ^= a[pr[k]];
	}
};

vector <pii> g[N];
vector <pair <pii, int>> edges;
bool seen[N];
int dist[N], a[M_SZ];

int minimize(int m, int p);
void dfs(int cur, int d);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
		edges.pb({{u, v}, w});
	}

	dfs(1, 0);
	int s = 0;
	for (auto &e : edges)
	{
		a[s] = e.second ^ dist[e.first.first] ^ dist[e.first.second];
		if (minimize(s, a[s]))
			gaussian().rref(a, ++s, M_SZ);
	}

	cout << minimize(s, dist[n]);
}

int minimize(int m, int p)
{
	for (int i = 0; i < m; ++i)
		p = min(p, p ^ a[i]);

	return p;
}

void dfs(int cur, int d)
{
	dist[cur] = d;
	seen[cur] = true;
	for (auto &i: g[cur])
		if (!seen[i.first])
			dfs(i.first, d ^ i.second);
}