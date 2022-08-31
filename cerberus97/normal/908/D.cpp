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
typedef long double ld;

const int N = 1e3 + 10, mod = 1e9 + 7;

ll a, b, k;
ll dp[N][N];
bool seen[N][N];

ll fastModExp(ll x, ll e);
ll solve(int x, int y);

int main() {
	ll pa, pb;
	cin >> k >> pa >> pb;
	ll den = fastModExp(pa + pb, mod - 2);
	a = (pa * den) % mod;
	b = (pb * den) % mod;
	cout << solve(1, 0) << endl;
}

ll solve(int x, int y) {
	if (seen[x][y]) {
		return dp[x][y];
	} else if (x + y >= k) {
		return (x + y + (a * fastModExp(b, mod - 2))) % mod;
	} else {
		seen[x][y] = true;
		dp[x][y] = (a * solve(x + 1, y) + b * solve(x, y + x)) % mod;
		return dp[x][y];
	}
}

ll fastModExp(ll x, ll e) {
	ll res = 1;
	x %= mod;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}

		x = (x * x) % mod;
		e >>= 1;
	}

	return res;
}