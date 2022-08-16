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

bool seen[N] = {0}, used[N] = {0};
queue <int> q;
vector <pii> g[N];

int main()
{
	fast_cin();
	int n, k, d, temp = 0;
	cin >> n >> k >> d;
	for (int i = 0; i < k; ++i)
	{
		int p;
		cin >> p;
		if (seen[p])
		{
			++temp;
			continue;
		}

		seen[p] = true;
		q.push(p);
	}

	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb({v, i});
		g[v].pb({u, i});
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto &i : g[cur])
		{
			if (!seen[i.first])
			{
				used[i.second] = true;
				seen[i.first] = true;
				q.push(i.first);
			}
		}
	}

	cout << k - 1 - temp << endl;
	for (int i = 1; i < n; ++i)
		if (!used[i])
			cout << i << ' ';
}