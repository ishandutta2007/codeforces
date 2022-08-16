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

const int N = 3e5 + 5;
const ll inf = 1e15;

ll a[N];
multiset <ll, greater <ll>> s;
vector <int> g[N];

int main()
{
	fast_cin();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		s.insert(a[i]);
	}

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	ll ans = inf;
	for (int i = 1; i <= n; ++i)
	{
		ll temp = a[i];
		s.erase(s.find(a[i]));
		for (auto &j : g[i])
		{
			s.erase(s.find(a[j]));
			temp = max(temp, a[j] + 1);
		}

		if (!s.empty())
			temp = max(temp, (*s.begin()) + 2);
		
		ans = min(ans, temp);
		s.insert(a[i]);
		for (auto &j : g[i])
			s.insert(a[j]);
	}

	cout << ans;
}