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

const int N = 3e5 + 5, mod = 1e9 + 7;

ll x[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i];

	sort(x, x + n);
	ll ans = 0, p = 1;
	for (int i = 0; i < n; ++i)
	{
		ans = (ans + x[i] * p) % mod;
		p = (p * 2) % mod;
	}

	p = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		ll temp = (x[i] * p) % mod;
		temp = mod - temp;
		ans = (ans + temp) % mod;
		p = (p * 2) % mod;
	}

	cout << ans;
}