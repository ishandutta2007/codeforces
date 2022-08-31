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

const int N = 1e5 + 5, M = 50;

ll ctr[M] = {0};
vector <ll> a;

bool check(ll x);

int main()
{
	ll n;
	cin >> n;
	ll j = 0;
	for (ll i = 0; i < n; ++i)
	{
		ll x;
		cin >> x;
		while ((1ll << j) < x)
			++j;

		if ((1ll << j) == x)
			++ctr[j];

		else
			a.pb(x);
	}

	if (!check(ctr[0]))
	{
		cout << -1;
		return 0;
	}

	ll l = 1, r = ctr[0] - 1;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		if (check(mid))
			r = mid - 1;

		else
			l = mid + 1;
	}

	for (ll i = r + 1; i <= ctr[0]; ++i)
		cout << i << ' ';
}

bool check(ll x)
{
	vector <ll> cur;
	for (auto i : a)
		cur.pb(i);

	ll temp[M] = {0};
	temp[0] = x;
	for (ll i = 0; i < ctr[0] - temp[0]; ++i)
		cur.pb(1);

	for (ll i = 1; i < M; ++i)
	{
		if (ctr[i] <= temp[i - 1])
		{
			temp[i] = ctr[i];
			temp[i - 1] -= ctr[i];
		}

		else
		{
			temp[i] = temp[i - 1];
			temp[i - 1] = 0;
			for (ll j = 0; j < ctr[i] - temp[i]; ++j)
				cur.pb(1ll << i);
		}
	}

	ll j = M - 1;
	sort(cur.begin(), cur.end(), greater <ll>());
	for (auto &i : cur)
	{
		while (j >= 0 and temp[j] == 0)
			--j;

		if (j < 0)
			return false;

		if (i > (1ll << (j + 1)))
			return false;

		else
			--temp[j];
	}

	return true;
}