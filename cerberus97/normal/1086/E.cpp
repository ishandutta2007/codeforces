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

const int N = 2e3 + 10, mod = 998244353;

using ordered_set =
struct BIT {
	int n;
	vector<int> bit;
	BIT(int n) : n(n), bit(n + 1, 0) {}
	int read(int idx) {
        idx--;
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
	void insert(int p) {
		if (read(p) == read(p + 1)) {
			update(p, 1);
		}
	}
	void erase(int p) {
		if (read(p) < read(p + 1)) {
			update(p, -1);
		}
	}
	int order_of_key(int v) {
		return read(v);
	}
	int find(int v) {
		return read(v + 1) - read(v);
	}
	int size() {
		return read(n + 1);
	}
};

ll perm_rank(int* p, int n);
ll der_rank(int *p, int *q, int n);
ll pwr(ll x, ll e);

int p[N][N];
ll fact[N], f[N][N], d[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> p[i][j];
		}
	}
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	for (int i = 0; i <= n; ++i) {
		f[i][0] = fact[i];
		for (int j = 1; j <= i; ++j) {
			f[i][j] = (j - 1) * f[i - 1][j - 2] + (i - j) * f[i - 1][j - 1];
			f[i][j] %= mod;
		}
		d[i] = f[i][i];
	}	
	ll ans = perm_rank(p[1], n) * pwr(d[n], n - 1);
	ans %= mod;
	for (int i = 1; i < n; ++i) {
		ans += der_rank(p[i], p[i + 1], n) * pwr(d[n], n - i - 1);
		ans %= mod;
	}
	cout << ans << endl;
}

ll perm_rank(int* p, int n) {
	ordered_set s(n);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		s.insert(p[i]);
		ll temp = (p[i] - 1) - s.order_of_key(p[i]);
		ans += temp * fact[n - i];
		ans %= mod;
	}
	return ans;
}

ll der_rank(int *p, int *q, int n) {
	ordered_set s(n), t(n);
	for (int i = 1; i <= n; ++i) {
		t.insert(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		s.insert(q[i]);
		ll tot = (q[i] - 1) - s.order_of_key(q[i]);
		if (p[i] < q[i] and !s.find(p[i])) {
			--tot;
		}
		t.erase(p[i]);
		ll c1 = t.order_of_key(q[i]);
		ans += c1 * f[n - i][t.size() - 1];
		ans += (tot - c1) * f[n - i][t.size()];
		ans %= mod;
		t.erase(q[i]);
	}
	return ans;
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