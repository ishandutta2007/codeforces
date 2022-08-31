/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 4e5 + 5;

void get_sizes(int cur);
int findCentroid(int cur, int n);
void solve(int root, int n);
void mark(int cur, int x, int y, int n);

bool seen[N] = {0}, ans[N];
vector <int> g[N];
int sz[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	get_sizes(1);
	memset(seen, 0, sizeof(seen));
	int root = findCentroid(1, n);
	memset(seen, 0, sizeof(seen));
	get_sizes(root);
	memset(seen, 0, sizeof(seen));
	solve(root, n);

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
}

void get_sizes(int cur)
{
	seen[cur] = true;
	sz[cur] = 1;
	for (auto &i : g[cur])
	{
		if (!seen[i])
		{
			get_sizes(i);
			sz[cur] += sz[i];
		}
	}
}

int findCentroid(int cur, int n)
{
	seen[cur] = true;
	for (auto &i : g[cur])
		if (!seen[i] and sz[i] > n/2)
			return findCentroid(i, n);

	return cur;
}

void solve(int root, int n)
{
	ans[root] = 1;
	seen[root] = true;
	multiset <int> s;
	for (auto &i : g[root])
		s.insert(sz[i]);

	for (auto &i : g[root])
	{
		s.erase(s.find(sz[i]));
		auto ub = s.upper_bound(n/2);
		int temp = 0;
		if (ub != s.begin())
		{
			--ub;
			temp = *ub;
		}

		if (n - sz[i] <= n/2)
			temp = max(temp, n - sz[i]);

		mark(i, n - sz[i], temp, n);
		s.insert(sz[i]);
	}
}

void mark(int cur, int x, int y, int n)
{
	seen[cur] = true;
	ans[cur] = (x - y <= n/2);
	int temp = 0;
	for (auto &i : g[cur])
		if (!seen[i])
			mark(i, n - sz[i], y, n);
}