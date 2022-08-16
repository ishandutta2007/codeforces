#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define dist second
#define loc first
#define diff first
#define ind second

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int ans[N], st[N], en[N];
ll dist[N], a[N];
vector <pii> g[N];

void solve(int cur, int m, ll d)
{
	dist[m] = d;
	// ind[m] = cur;

	int i = lower_bound(dist, dist + m, dist[m] - a[cur]) - dist;

	if (i != m)
	{
		st[i]++;
		en[m-1]++;
	}

	for (auto &i : g[cur])
	{
		solve(i.first, m+1, i.second + dist[m]);
	}

	ans[cur] += en[m];
	en[m-1] += en[m] - st[m];
	st[m] = 0;
	en[m] = 0;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 2; i <= n; ++i)
	{
		int p;
		ll w;
		cin >> p >> w;

		g[p].push_back({i, w});
	}

	solve(1, 0, 0);

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
}