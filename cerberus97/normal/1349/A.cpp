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

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	int m = a.back();
	vector<bool> is_prime(m + 1, true);
	vector<int> min_factor(m + 1);
	is_prime[0] = is_prime[1] = false;
	for (int p = 2; p <= m; ++p) {
		if (is_prime[p]) {
			min_factor[p] = p;
			for (int x = 2 * p; x <= m; x += p) {
				if (is_prime[x]) {
					is_prime[x] = false;
					min_factor[x] = p;
				}
			}
		}
	}
	vector<vector<int>> at(m + 1);
	for (auto& i : a) {
		while (i > 1) {
			int p = min_factor[i], cnt = 0;
			while (i % p == 0) {
				i /= p;
				++cnt;
			}
			at[p].pb(cnt);
		}
	}
	ll ans = 1;
	for (int p = 2; p <= m; ++p) {
		if (is_prime[p]) {
			sort(at[p].begin(), at[p].end());
			int cnt = 0;
			if (int(at[p].size()) == n - 1) {
				cnt = at[p][0];
			} else if (int(at[p].size()) == n) {
				cnt = at[p][1];
			}
			while (cnt--) {
				ans *= p;
			}
		}
	}
	cout << ans << '\n';
}