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
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e4 + 10, inf = 1e9;

int r[N], c[N], dist[N];
bool seen[N] = {0};

int main()
{
	int n, m, k;
	cin >> n >> m >> k;	
	for (int i = 1; i <= k; ++i)
	{
		cin >> r[i] >> c[i];
		dist[i] = inf;
		if (r[i] == 1 and c[i] == 1)
			dist[i] = 0;
	}

	dist[0] = inf;
	while (true)
	{
		int cur = 0;
		for (int i = 1; i <= k; ++i)
			if (!seen[i] and dist[i] < dist[cur])
				cur = i;

		if (!cur)
			break;

		seen[cur] = true;
		for (int i = 1; i <= k; ++i)
		{
			if (seen[i])
				continue;

			if (abs(r[i] - r[cur]) > 2 and abs(c[i] - c[cur]) > 2)
				continue;

			int temp = 1;
			if (abs(r[i] - r[cur]) + abs(c[i] - c[cur]) == 1)
				temp = 0;

			if (dist[cur] + temp < dist[i])
				dist[i] = dist[cur] + temp;
		}
	}

	int ans = inf;
	for (int i = 1; i <= k; ++i)
	{
		if (r[i] == n and c[i] == m)
			ans = min(ans, dist[i]);

		else if (r[i] >= n - 1 or c[i] >= m - 1)
			ans = min(ans, dist[i] + 1);
	}

	if (ans == inf)
		cout << -1;
	else
		cout << ans;
}