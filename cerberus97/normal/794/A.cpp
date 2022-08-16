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

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll x;
		cin >> x;
		if (x > b and x < c)
			++ans;
	}	

	cout << ans;
}