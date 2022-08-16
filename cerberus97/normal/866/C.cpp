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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pld;

const int kN = 60, kT = 5e3 + 10;
const ld eps = 1e-10;

int f[kN], s[kN];
ld p[kN], dp[kN][kT];
bool seen[kN][kT];

ld check(ld k, int n, int r);
ld solve(int i, int j, const int &n, const int &r, const ld &k);

int main() {
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; ++i) {
		cin >> f[i] >> s[i] >> p[i];
		p[i] *= 0.01;
	}
	// for (ld k = 0; k <= 1000; k += 10) {
	// 	cout << k << ' ' << k - check(k, n, r) << endl;
	// }
	ld lo = 0, hi = 3.5e7;
	for (int i = 0; i < 55; ++i) {
		ld mid = (lo + hi) / 2;
		if (check(mid, n, r) > eps) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << fixed << setprecision(12) << lo << endl;
}

ld check(ld k, int n, int r) {
	memset(seen, 0, sizeof(seen));
	return k - solve(1, 0, n, r, k);
}

ld solve(int i, int j, const int &n, const int &r, const ld &k) {
	if (j > r) {
		return k;
	} else if (i == n + 1) {
		return 0;
	} else if (seen[i][j]) {
		return dp[i][j];
	}
	seen[i][j] = true;
	dp[i][j] = min(k, p[i] * (f[i] + solve(i + 1, j + f[i], n, r, k)) + (1 - p[i]) * (s[i] + solve(i + 1, j + s[i], n, r, k)));
	return dp[i][j];
}