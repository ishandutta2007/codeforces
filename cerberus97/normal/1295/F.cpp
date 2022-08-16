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

const int N = 60, M = 2 * N, mod = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= mod) a -= mod;
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
		e /= 2;
		x = mul(x, x);
	}
	return res;
}

int inv(int x) {
	return pwr(x, mod - 2);
}

int l[N], r[N], dp[N][M], nck[M][M];
bool seen[M][M];

int choose(vector<int>& wt, int i, int j);

int main() {
	fast_cin();
	int n; cin >> n;
	set<int> s;
	for (int i = n; i >= 1; --i) {
		cin >> l[i] >> r[i];
		l[i] += i;
		r[i] += i;
		s.insert(l[i]);
		s.insert(r[i] + 1);
	}
	vector<int> vals;
	for (auto& v : s) {
		vals.pb(v);
	}
	int m = vals.size();
	vector<int> wt(m, 0);
	for (int i = 0; i < m - 1; ++i) {
		wt[i] = vals[i + 1] - vals[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			add(dp[i][j + 1], dp[i][j]);
			for (int k = i + 1; k <= n; ++k) {
				if (l[k] > vals[j] or vals[j] > r[k]) {
					break;
				}
				add(dp[k][j + 1], mul(dp[i][j], choose(wt, j, k - i)));
			}
		}
	}
	int ans = dp[n][m - 1];
	for (int i = 1; i <= n; ++i) {
		ans = mul(ans, inv(r[i] - l[i] + 1));
	}
	cout << ans << endl;
}

int choose(vector<int>& wt, int i, int j) {
	if (j < 0 or j > wt[i]) {
		return 0;
	} else if (seen[i][j]) {
		return nck[i][j];
	} else {
		seen[i][j] = true;
		int n = wt[i], k = j;
		int& ans = nck[i][j];
		ans = 1;
		for (int x = 0; x < k; ++x) {
			ans = mul(ans, n - x);
			ans = mul(ans, inv(k - x));
		}
		return ans;
	}
}