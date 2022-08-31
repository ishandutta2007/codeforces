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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;
const ll inf = 5e18;

ll a[N], f[N], g[N], h[N];

int main()
{
	int n; ll p, q, r;
	cin >> n >> p >> q >> r;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	h[n + 1] = g[n + 1] = f[n + 1] = -inf;
	for (int i = n; i >= 1; --i)
	{
		h[i] = max(h[i + 1], r * a[i]);
		g[i] = max(g[i + 1], q * a[i] + h[i]);
		f[i] = max(f[i + 1], p * a[i] + g[i]);
	}

	cout << f[1];
}