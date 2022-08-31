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
	int q;
	cin >> q;
	while (q--)
	{
		ll n;
		cin >> n;
		ll l = 2, r = n;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			if ((mid * (mid + 1)) / 2 <= n)
				l = mid + 1;
			else
				r = mid - 1;
		}

		ll b = l - 1, a = n - b;
		cout << max(a + ((b * (b - 1)) / 2), 2 * (a - 1)) << endl;
	}
}