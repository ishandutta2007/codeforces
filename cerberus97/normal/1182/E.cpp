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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<ll> row;
typedef vector<row> matrix;

const int mod = 1e9 + 7, phi_mod = mod - 1;

ll f[3];

matrix matrix_mul(matrix a, matrix b);
matrix matrix_pwr(matrix a, ll e);
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	ll n, c;
	cin >> n >> f[0] >> f[1] >> f[2] >> c;
	matrix c_exponent = {
		{0, 0, 1, 0, 0},
		{1, 0, 1, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, phi_mod - 6, 1, 1}
	};
	c_exponent = matrix_pwr(c_exponent, n - 1);
	matrix init = {{0, 0, 0, 4, 1}};
	matrix res = matrix_mul(init, c_exponent);
	ll ans = pwr(c, res[0][0]);
	matrix f_exponent = {
		{0, 0, 1},
		{1, 0, 1},
		{0, 1, 1}
	};
	f_exponent = matrix_pwr(f_exponent, n - 1);
	for (int i = 0; i < 3; ++i) {
		init = {{0, 0, 0}};
		init[0][i] = 1;
		res = matrix_mul(init, f_exponent);
		ans *= pwr(f[i], res[0][0]);
		ans %= mod;
	}
	cout << ans << endl;
}

matrix matrix_mul(matrix a, matrix b) {
	int n = a.size(), m = a[0].size(), p = b[0].size();
	assert(m == b.size());
	matrix ans(n, row(p, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			for (int k = 0; k < m; ++k) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= phi_mod;
			}
		}
	}
	return ans;
}

matrix matrix_pwr(matrix a, ll e) {
	matrix res = a;
	--e;
	while (e) {
		if (e & 1) {
			res = matrix_mul(res, a);
		}
		a = matrix_mul(a, a);
		e /= 2;
	}
	return res;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e /= 2;
	}
	return res;
}