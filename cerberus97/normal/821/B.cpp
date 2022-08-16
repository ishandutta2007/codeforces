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

int main()
{
	ll m, b;
	cin >> m >> b;

	ll max_x = m * b, ans = 0;
	for (ll i = 0; i <= max_x; ++i)
	{
		ll y = b - (i / m + !!(i % m));
		ll temp = ((i * (i + 1)) / 2) * (y + 1) + ((y * (y + 1)) / 2) * (i + 1);
		// cout << i << ' ' << y << ' ' << temp << endl;
		ans = max(ans, temp);
	}

	cout << ans;
}