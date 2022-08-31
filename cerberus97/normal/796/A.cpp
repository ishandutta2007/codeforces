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
	int n, m, k;
	cin >> n >> m >> k;
	int ans = N;
	for (int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		if (a > 0 and a <= k)
			ans = min(ans, 10 * abs(i - m));
	}

	cout << ans;
}