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

const int N = 1e6 + 10, M = 2e6 + 10, mod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += mod;
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
	int t; cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		vector<int> k(n);
		for (auto& i : k) {
			cin >> i;
		}
		sort(k.begin(), k.end(), greater<int>());
		if (p == 1) {
			cout << n % 2 << '\n';
			continue;
		}
		vector<pii> v1, v2;
		for (auto& i : k) {
			if (v1.empty()) {
				v1.pb({i, 1});
			} else {
				while (!v2.empty() and v2.back().first == i and v2.back().second == p - 1) {
					v2.pop_back();
					++i;
				}
				if (i == v1.back().first) {
					v1.pop_back();
				} else if (!v2.empty() and v2.back().first == i) {
					++v2.back().second;
				} else {
					v2.pb({i, 1});
				}
			}
		}
		int ans = 0;
		for (auto& tmp : v1) {
			ans = add(ans, mul(tmp.second, pwr(p, tmp.first)));
		}
		for (auto& tmp : v2) {
			ans = sub(ans, mul(tmp.second, pwr(p, tmp.first)));
		}
		cout << ans << '\n';
	}
}