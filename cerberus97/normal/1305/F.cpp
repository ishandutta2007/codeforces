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
#include <chrono>
#include <random>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, IT = 20;

int main() {
	fast_cin();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n; cin >> n;
	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	auto b = a;
// 	sort(b.begin(), b.end());
// 	b.erase(unique(b.begin(), b.end()), b.end());
	int m = b.size();
	set<ll> pfactors;
	for (int it = 0; it < IT; ++it) {
		int i = uniform_int_distribution<int>(0, m - 1)(rng);
		for (ll val = max(1ll, b[i] - 1); val <= b[i] + 1; ++val) {
			ll cpy = val;
			ll sq = sqrt(cpy);
			for (ll p = 2; p <= sq; ++p) {
				if (cpy % p == 0) {
					pfactors.insert(p);
					while (cpy % p == 0) {
						cpy /= p;
					}
				}
			}
			if (cpy > 1) {
				pfactors.insert(cpy);
			}
		}
	}
	ll ans = n;
	for (auto& p : pfactors) {
		ll cand = 0;
		for (auto& i : a) {
			if (i < p) {
				cand += p - i;
			} else {
				ll md = i % p;
				cand += min(md, p - md);
			}
		}
		ans = min(ans, cand);
	}
	cout << ans << endl;
}