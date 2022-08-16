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

const int N = 1e5 + 5;

int c[N], ctr[N] = {0};
vector <pii> candidates, edges;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		edges.pb({u, v});
	}

	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	for (auto &i : edges)
	{
		if (c[i.first] != c[i.second])
			candidates.pb(i);
	}

	if (candidates.empty())
	{
		cout << "YES\n1";
		return 0;
	}

	int m = candidates.size();
	for (auto &i : candidates)
	{
		ctr[i.first]++;
		ctr[i.second]++;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (ctr[i] == m)
		{
			cout << "YES\n" << i;
			return 0;
		}
	}

	cout << "NO";

}