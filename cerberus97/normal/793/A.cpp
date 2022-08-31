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

ll a[N];

int main()
{
	int n, k;
	cin >> n >> k;	
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	ll ans = 0, cur = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (abs(a[i] - cur) % k)
		{
			cout << -1;
			return 0;
		}

		if (a[i] >= cur)
			ans += (a[i] - cur) / k;

		else
		{
			ans += i * ((cur - a[i]) / k);
			cur = a[i];
		}
	}

	cout << ans;
}