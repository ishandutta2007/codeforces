/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, mod = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

int pwr(int x, int e) {
	int res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		e /= 2;
	}
	return res;
}

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	if (n == 2) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> p2(m + 1, 1), fact = p2, finv = p2;
	for (int i = 1; i <= m; ++i) {
		p2[i] = mul(2, p2[i - 1]);
		fact[i] = mul(i, fact[i - 1]);
		finv[i] = pwr(fact[i], mod - 2);
	}
	ll ans = 0;
	for (int v = n - 1; v <= m; ++v) {
		ll temp = mul(mul(fact[v - 1], finv[n - 2]), finv[v - n + 1]);
		ans = add(ans, temp);
	}
	ans = mul(ans, p2[n - 3]);
	ans = mul(ans, n - 2);
	cout << ans << endl;
}