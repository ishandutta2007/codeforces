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

const int N = 1e2 + 5;

int t[N], ans[N];
pii a[N];

int main()
{
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a + n);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		t[i] = (a[i].first + 1) / 2;
		sum += t[i];
		w -= t[i];
	}

	if (w < 0)
	{
		cout << -1;
		return 0;
	}

	for (int i = n - 1; i >= 0; --i)
	{
		if (w <= a[i].first - t[i])
		{
			t[i] += w;
			w = 0;
			break;
		}

		else
		{
			w -= a[i].first - t[i];
			t[i] = a[i].first;
		}
	}

	for (int i = 0; i < n; ++i)
		ans[a[i].second] = t[i];

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
}