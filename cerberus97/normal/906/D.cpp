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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, M = 200;

int n, m;
int phi[M], w[N], nxt1[N];

int query(int l, int r, int i);
ll get_phi(int i);
bool is_greater(int l, int r, int x);
ll fastModExp(ll x, ll e, ll mod);

int main() {
	fast_cin();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}

	phi[1] = m;
	for (int i = 2; phi[i - 1] >= 1; ++i) {
		phi[i] = get_phi(phi[i - 1]);
		// cout << phi[i] << endl;
	}

	nxt1[n + 1] = n + 1;
	for (int i = n; i >= 1; --i) {
		if (w[i] == 1) {
			nxt1[i] = i;
		} else {
			nxt1[i] = nxt1[i + 1];
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r, 1) << endl;
	}
}

int query(int l, int r, int i) {
	if (l > r) {
		return 1;
	} else if (phi[i] == 1) {
		return 0;
	}

	ll temp = query(l + 1, r, i + 1);
	ll ans  = fastModExp(w[l], temp, phi[i]);
	if (is_greater(l + 1, r, phi[i + 1])) {
		ans *= fastModExp(w[l], phi[i + 1], phi[i]);
		ans %= phi[i];
	}

	return ans;
}

bool is_greater(int l, int r, int x) {
	r = min(r, nxt1[l] - 1);
	if (l > r) {
		return 1 >= x;
	} else if (w[l] >= x) {
		return true;
	}

	if (r - l + 1 > 5) {
		return true;
	}

	ll ans = 1;
	for (int i = r; i >= l; --i) {
		ll temp = w[i];
		for (int j = 0; j < ans; ++j) {
			if (temp >= x) {
				return true;
			} else {
				temp *= w[i];
			}
		}

		ans = temp;
	}

	return false;
}

ll get_phi(int i) {
	if (i == 1) {
		return 0;
	}

	ll ans = i, sq = sqrt(i);
	for (int p = 2; p <= sq; ++p) {
		if (i % p == 0) {
			ans *= (p - 1);
			ans /= p;
			while (i % p == 0) {
				i /= p;
			}

		}
	}

	if (i > 1) {
		ans *= (i - 1);
		ans /= i;
	}

	return ans;
}

ll fastModExp(ll x, ll e, ll mod) {
	ll ans = 1;
	x %= mod;
	while (e) {
		if (e & 1) {
			ans = (ans * x) % mod;
		}

		x = (x * x) % mod;
		e >>= 1;
	}

	return ans;
}