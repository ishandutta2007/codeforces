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

const int N = 1e5 + 5;

ll ans[N] = {0}, a[N];

int main()
{
	int n; ll s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int l = 1, r = n;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		vector <ll> v;
		for (int i = 0; i < n; ++i)
			v.pb(a[i] + mid * (i + 1));

		ll temp = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < mid; ++i)
			temp += v[i];

		if (temp <= s)
		{
			l = mid + 1;
			ans[mid] = temp;
		}

		else
			r = mid - 1;
	}

	cout << l - 1 << ' ' << ans[l - 1];
}