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

const int N = 2e5 + 5;

vector <int> g[N];
int mx = 1, c[N];
bool seen[N] = {0};

void color(int cur, int a, int b);

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

	c[1] = 1;
	color(1, 1, 0);
	cout << mx << endl;
	for (int i = 1; i <= n; ++i)
		cout << c[i] << ' ';
}

void color(int cur, int a, int b)
{
	seen[cur] = true;
	int x = 1;

	for (auto &i : g[cur])
	{
		if (!seen[i])
		{
			while (x == a or x == b)
				++x;

			mx = max(mx, x);
			c[i] = x;
			color(i, x, a);
			++x;
		}
	}
}