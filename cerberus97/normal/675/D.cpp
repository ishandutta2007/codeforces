/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int a[N];
set <int> seen;
pii g[N];
map <int, int> inv;

int getParent(int i);

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		inv[a[i]] = i;
		g[i] = {0, 0};
		int par = getParent(i);
		seen.insert(a[i]);
		if (i > 1)
			cout << par << ' ';
	}	
}

int getParent(int i)
{
	if (i == 1)
		return 0;

	auto start = seen.lower_bound(a[i]);
	if (start == seen.end())
		--start;

	int cur = inv[*start];

	while (true)
	{
		if (a[i] < a[cur])
		{
			if (g[cur].first == 0)
			{
				g[cur].first = i;
				break;
			}
			cur = g[cur].first;
		}

		else
		{
			if (g[cur].second == 0)
			{
				g[cur].second = i;
				break;
			}
			cur = g[cur].second;
		}
	}

	return a[cur];
}