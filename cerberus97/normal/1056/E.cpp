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

const int N = 1e5 + 10, M = 1e6 + 10, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int P1 = 31, P2 = 37;

ll h0[M], h1[M], inv0[M], inv1[M];

void hsh(string &t);
inline bool eq_hash(int i1, int l1, int i2, int l2);
inline ll pwr(ll x, ll e, ll mod);

int main() {
	fast_cin();
	string s, t;
	cin >> s >> t;
	hsh(t);
	ll c0 = 0, c1 = 0;
	int n = s.length(), m = t.length();
	for (auto &i : s) {
		c0 += (i == '0');
	}
	c1 = n - c0;
	int ans = 0;
	for (int l0 = 1; l0 <= m; ++l0) {
		int l1 = (m - l0 * c0) / c1;
		if (l0 * c0 + l1 * c1 != m or l1 < 1 or l1 >= m) {
			continue;
		}
		int i = 0, j = 0;
		int s0 = -1, s1 = -1;
		for (; i < n; ++i) {
			if (s[i] == '0') {
				s0 = j;
				j += l0;
			} else {
				s1 = j;
				j += l1;
			}
		}
		i = j = 0;
		if (l0 == l1 and eq_hash(s0, l0, s1, l1)) {
			continue;
		}
		// cout << l0 << ' ' << l1 << endl;
		// cout << s0 << ' ' << s1 << endl;
		// cout << get_hash(s0, l0).second << ' ' << get_hash(s1, l1).second << endl;
		bool ok = true;
		for (; i < n; ++i) {
			if (s[i] == '0') {
				if (!eq_hash(j, l0, s0, l0)) {
					ok = false;
					break;
				}
				j += l0;
			} else {
				if (!eq_hash(j, l1, s1, l1)) {
					ok = false;
					break;
				}
				j += l1;
			}
		}
		if (ok) {
			// cout << "ok\n";
			++ans;
		}
	}
	cout << ans << endl;
}

void hsh(string &t) {
	int m = t.length();
	h0[0] = t[0];
	h1[0] = t[0];
	inv0[0] = inv1[0] = 1;
	ll p1 = P1, p2 = P2;
	for (int i = 1; i < m; ++i) {
		h0[i] = (h0[i - 1] + t[i] * p1) % mod1;
		h1[i] = (h1[i - 1] + t[i] * p2) % mod2;
		inv0[i] = pwr(p1, mod1 - 2, mod1);
		inv1[i] = pwr(p2, mod2 - 2, mod2);
		p1 = (p1 * P1) % mod1;
		p2 = (p2 * P2) % mod2;
	}
}

inline bool eq_hash(int i1, int l1, int i2, int l2) {
	int j1 = i1 + l1 - 1, j2 = i2 + l2 - 1;
	ll a0 = (h0[j1] + (i1 ? mod1 - h0[i1 - 1] : 0)) * inv0[i1];
	ll a1 = (h0[j2] + (i2 ? mod1 - h0[i2 - 1] : 0)) * inv0[i2];
	if (a0 % mod1 != a1 % mod1) {
		return false;
	}
	
	a0 = (h1[j1] + (i1 ? mod2 - h1[i1 - 1] : 0)) * inv1[i1];
	a1 = (h1[j2] + (i2 ? mod2 - h1[i2 - 1] : 0)) * inv1[i2];
	if (a0 % mod2 != a1 % mod2) {
		return false;
	}

	return true;
}

inline ll pwr(ll x, ll e, ll mod) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e >>= 1;
	}
	return res;
}