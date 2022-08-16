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

typedef vector<vector<ll>> matrix;

const int N = 1e2 + 10, mod = 1e9 + 7;

int s[N];

matrix matrix_mul(matrix &a, matrix &b);
matrix matrix_pow(matrix a, ll e);
ll inverse(ll x);
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		if (s[i] == 0) {
			++a;
		}
	}
	b = n - a;
	int init = 0;
	for (int i = 0; i < a; ++i) {
		if (s[i] == 0) {
			++init;
		}
	}
	matrix start(a + 1, vector<ll>(1, 0));
	start[init][0] = 1;
	matrix mat(a + 1, vector<ll>(a + 1, 0));
	ll den = inverse((n * (n - 1)) / 2);
	for (int j = max(0, a - b); j <= a; ++j) {
		mat[j][j] = (a * (a - 1)) / 2 + (b * (b - 1)) / 2 + j * (a - j) + (a - j) * (b - a + j);
		mat[j][j] *= den;
		mat[j][j] %= mod;
		if (j > max(0, a - b)) {
			mat[j - 1][j] = j * (b - a + j);
			mat[j - 1][j] *= den;
			mat[j - 1][j] %= mod;
		}
		if (j < a) {
			mat[j + 1][j] = (a - j) * (a - j);
			mat[j + 1][j] *= den;
			mat[j + 1][j] %= mod;
		}
	}
	mat = matrix_pow(mat, k);
	start = matrix_mul(mat, start);
	cout << start[a][0] << '\n';
}

matrix matrix_mul(matrix &a, matrix &b) {
	int n = a.size(), m = a[0].size(), p = b[0].size();
	matrix ans(n, vector<ll>(p, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			for (int k = 0; k < m; ++k) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= mod;
			}
		}
	}
	return ans;
}

matrix matrix_pow(matrix a, ll e) {
	matrix res = a;
	--e;
	while (e) {
		if (e & 1) {
			res = matrix_mul(res, a);
		}
		e /= 2;
		a = matrix_mul(a, a);
	}
	return res;
}

ll inverse(ll x) {
	return pwr(x, mod - 2);
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		e /= 2;
		x = (x * x) % mod;
	}
	return res;
}