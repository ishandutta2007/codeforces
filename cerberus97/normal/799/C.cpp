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

const int N = 1e5 + 5;

int b[N], p[N], b1[N], b2[N];
char t[N];
vector <pii> a[2];

int solve(vector <pii> &v, int x);

int main()
{
	int n, c, d;
	cin >> n >> c >> d;
	int tc = 0, td = 0, ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i] >> p[i] >> t[i];
		a[t[i] - 'C'].pb({p[i], b[i]});

		if (t[i] == 'C' and p[i] <= c)
			tc = max(tc, b[i]);

		else if (t[i] == 'D' and p[i] <= d)
			td = max(td, b[i]);
	}

	ans = max(solve(a[0], c), solve(a[1], d));
	if (tc and td)
		ans = max(ans, tc + td);

	cout << ans;
}

int solve(vector <pii> &v, int x)
{
	sort(v.begin(), v.end());
	int n = v.size(), j = 0;
	b1[0] = -1;
	b2[0] = -1;
	for (int i = 1; i < N; ++i)
	{
		b1[i] = b1[i - 1];
		b2[i] = b2[i - 1];
		while (j < n)
		{
			if (v[j].first <= i)
			{
				if (b1[i] == -1)
					b1[i] = j;

				else if (v[j].second > v[b1[i]].second)
				{
					b2[i] = b1[i];
					b1[i] = j;
				}

				else if (b2[i] == -1 or v[j].second > v[b2[i]].second)
					b2[i] = j;

				++j;
			}

			else
				break;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].first >= x)
			break;

		int cur = x - v[i].first;
		if (b1[cur] != i and b1[cur] != -1)
		{
			ans = max(ans, v[i].second + v[b1[cur]].second);
			continue;
		}

		if (b2[cur] != i and b2[cur] != -1)
			ans = max(ans, v[i].second + v[b2[cur]].second);
	}

	return ans;
}