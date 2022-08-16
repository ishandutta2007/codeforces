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

const int N = 2e5 + 10, mod = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul(ll a, int b) {
	a *= b;
	return a % mod;
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
	int n, k;
	cin >> n >> k;
	if (k < 0 or k >= n) {
		cout << 0 << endl;
		return 0;
	}
	k = n - k;
	vector<int> fact(n + 1), finv(n + 1);
	fact[0] = finv[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mul(fact[i - 1], i);
		finv[i] = pwr(fact[i], mod - 2);
	}
	auto choose = [&](int x, int y) {
		return mul(mul(fact[x], finv[y]), finv[x - y]);
	};
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		int temp = mul(choose(k, i), pwr(k - i, n));
		ans = add(ans, (i % 2 == 0 ? temp : mod - temp));
	}
	ans = mul(ans, mul((k == n ? 1 : 2), choose(n, k)));
	cout << ans << '\n';
}