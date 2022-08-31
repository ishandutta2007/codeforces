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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<ll> col;
typedef vector<col> matrix;

const int N = 1e5 + 10, mod = 1e9 + 7;

matrix mat[8];
vector<pll> events;
ll ctr[3];

void init();
matrix solve(matrix a, int mask, ll n);
matrix matrix_exp(matrix a, ll e);
matrix matrix_mul(matrix a, matrix b);

void print(matrix a) {
	for (auto &r : a) {
		for (auto &c : r) {
			cout << c << ' ';
		}
		cout << endl;
	}
}

int main() {
	init();
	int n; ll m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a; ll l, r;
		cin >> a >> l >> r;
		events.pb({l, +a});
		events.pb({r + 1, -a});
	}
	events.pb({m + 1, 0});
	sort(events.begin(), events.end());
	ll j = 1;
	matrix a = {{0, 1, 0}};
	for (auto &p : events) {
		ll i = p.first, c = p.second;
		if (j < i - 1) {
			int k = 0;
			for (int x = 0; x < 3; ++x) {
				if (ctr[x]) {
					k |= (1 << x);
				}
			}
			a = solve(a, k, i - j - 1);
			j = i - 1;
		}
		if (c > 0) {
			++ctr[c - 1];
		} else {
			--ctr[-c - 1];
		}
	}
	cout << a[0][1];
}

void init() {
	int n = 3, s = (1 << n);
	for (int mask = 0; mask < s; ++mask) {
		mat[mask].resize(n);
		for (int i = 0; i < n; ++i) {
			mat[mask][i].resize(n);
			for (int j = 0; j < n; ++j) {
				if (abs(i - j) <= 1 and !(mask & (1 << j))) {
					mat[mask][i][j] = 1;
				} else {
					mat[mask][i][j] = 0;
				}
			}
		}
		// cout << bitset<3>(mask) << endl;
		// print(mat[mask]);
		// cout << endl;
	}
}

matrix solve(matrix a, int mask, ll n) {
	// print(a);
	// cout << endl;
	// cout << bitset<3>(mask) << ' ' << n << endl << endl;
	matrix m = matrix_exp(mat[mask], n);
	return matrix_mul(a, m);
}

matrix matrix_exp(matrix a, ll e) {
	matrix ans = a;
	--e;
	while (e) {
		if (e & 1) {
			ans = matrix_mul(ans, a);
		}
		e >>= 1;
		a = matrix_mul(a, a);
	}
	return ans;
}

matrix matrix_mul(matrix a, matrix b) {
	int n = a.size(), p = b.size(), m = b[0].size();
	matrix ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i].resize(m);
		for (int j = 0; j < m; ++j) {
			ans[i][j] = 0;
			for (int k = 0; k < p; ++k) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= mod;
			}
		}
	}
	return ans;
}