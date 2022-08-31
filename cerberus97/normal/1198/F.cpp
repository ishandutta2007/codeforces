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

const int N = 1e5 + 10, MAGIC = 9;
const int K = 330, S = (1 << MAGIC) + 10;

int a[N], ans[N], mask1[N], mask2[N];
// pii dp[K][S][S];

bool solve(int n, int g1, int g2);
vector<int> get_primes(int g, int n, int* mask);

int main() {
	// cout << sizeof(dp) / 1e6 << endl;
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int c1 = 1;
	for (int c2 = n; c2 >= 2 and c2 >= n - MAGIC; --c2) {
		int g1 = a[c1], g2 = a[c2];
		a[c1] = a[c2] = 0;
		if (solve(n, g1, g2)) {
			ans[c1] = 1;
			ans[c2] = 2;
			cout << "YES\n";
			for (int i = 1; i <= n; ++i) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
			return 0;
		}
		a[c1] = g1;
		a[c2] = g2;
	}
	cout << "NO\n";
}

bool solve(int n, int g1, int g2) {
	vector<int> p1 = get_primes(g1, n, mask1);
	vector<int> p2 = get_primes(g2, n, mask2);
	int k1 = p1.size(), k2 = p2.size();
	int t1 = (1 << k1), t2 = (1 << k2);
	set<int> temp;
	for (int j = 0; j < k1; ++j) {
		int left = 2 * MAGIC;
		for (int i = 1; i <= n and left; ++i) {
			if (mask1[i] & (1 << j)) {
				--left;
				temp.insert(i);
			}
		}
	}
	for (int j = 0; j < k2; ++j) {
		int left = 2 * MAGIC;
		for (int i = 1; i <= n and left; ++i) {
			if (mask2[i] & (1 << j)) {
				--left;
				temp.insert(i);
			}
		}
	}
	vector<int> v;
	for (auto &i : temp) {
		v.pb(i);
	}
	vector<vector<vector<pii>>> dp(v.size() + 1);
	for (int i = 0; i <= int(v.size()); ++i) {
		dp[i].resize(t1);
		for (int m1 = 0; m1 < t1; ++m1) {
			dp[i][m1].resize(t2);
			for (int m2 = 0; m2 < t2; ++m2) {
				dp[i][m1][m2] = {-1, -1};
			}
		}
	}
	dp[0][0][0] = {0, 0};
	for (int i = 0; i < int(v.size()); ++i) {
		for (int m1 = 0; m1 < t1; ++m1) {
			for (int m2 = 0; m2 < t2; ++m2) {
				if (dp[i][m1][m2].first == -1) {
					continue;
				}
				dp[i + 1][m1 | mask1[v[i]]][m2] = {m1, m2};
				dp[i + 1][m1][m2 | mask2[v[i]]] = {m1, m2};
			}
		}
	}
	if (dp[int(v.size())][t1 - 1][t2 - 1].first != -1) {
		int si = v.size(), m1 = t1 - 1, m2 = t2 - 1;
		for (int i = 1; i <= n; ++i) {
			ans[i] = 1;
		}
		while (si) {
			if (m2 != dp[si][m1][m2].second) {
				ans[v[si - 1]] = 2;
			}
			tie(m1, m2) = dp[si][m1][m2];
			--si;
		}
		return true;
	} else {
		return false;
	}
}

vector<int> get_primes(int g, int n, int* mask) {
	vector<int> primes;
	int sq = sqrt(g);
	for (int i = 2; i <= sq; ++i) {
		if (g % i == 0) {
			primes.pb(i);
			while (g % i == 0) {
				g /= i;
			}
		}
	}
	if (g > 1) {
		primes.pb(g);
	}
	int k = primes.size();
	for (int i = 1; i <= n; ++i) {
		mask[i] = 0;
		for (int j = 0; j < k; ++j) {
			if (a[i] % primes[j]) {
				mask[i] |= (1 << j);
			}
		}
	}
	return primes;
}