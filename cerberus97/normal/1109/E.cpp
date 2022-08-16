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

const int N = 1e5 + 10, P = 10, E = 2e6 + 10;

vector<int> bad_primes;
ll pre_pwr[P][E];
int k, mod;

ll extended_euclid(ll v, ll b, ll &x, ll &y);
ll mod_inverse(ll v, ll n);

struct num_t {
	ll rest, sum;
	ll exponent[P];
	num_t(int val = 1) {
		sum = rest = val;
		memset(exponent, 0, sizeof(exponent));
		if (val <= 1) {
			return;
		}
		for (int i = 0; i < k; ++i) {
			while (rest % bad_primes[i] == 0) {
				++exponent[i];
				rest /= bad_primes[i];
			}
		}
	}
	void operator*=(const num_t &b) {
		sum *= b.sum;
		sum %= mod;
		rest *= b.rest;
		rest %= mod;
		for (int i = 0; i < k; ++i) {
			exponent[i] += b.exponent[i];
		}
	}
	void operator/=(const num_t &b) {
		sum = 1;
		for (int i = 0; i < k; ++i) {
			exponent[i] -= b.exponent[i];
			sum *= pre_pwr[i][exponent[i]];
			sum %= mod;
		}
		rest *= mod_inverse(b.rest, mod);
		rest %= mod;
		sum *= rest;
		sum %= mod;
	}
	// Don't multiply after addition
	num_t operator+(const num_t &b) {
		num_t ans(0);
		ans.sum = (sum + b.sum) % mod;
		return ans;
	}
};

ll a[N];
num_t tree[4 * N], lazy[4 * N];

void build_tree(int i, int l, int r);
void mul_upd(int i, int l, int r, int ql, int qr, num_t &x);
void div_upd(int i, int l, int r, int p, num_t &x);
ll query(int i, int l, int r, int ql, int qr);
void propagate(int i, int lc, int rc);

int main() {
	fast_cin();
	// sieve();
	int n;
	cin >> n >> mod;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		// mul_upd(1, 1, n, i, i, a[i]);
	}
	int sq = sqrt(mod), mod_cpy = mod;
	for (int i = 2; i <= sq; ++i) {
		if (mod_cpy % i == 0) {
			bad_primes.pb(i);
			while (mod_cpy % i == 0) {
				mod_cpy /= i;
			}
		}
	}
	if (mod_cpy > 1) {
		bad_primes.pb(mod_cpy);
	}
	k = bad_primes.size();
	// cout << k << endl;
	for (int i = 0; i < k; ++i) {
		pre_pwr[i][0] = 1;
		for (int j = 1; j < E; ++j) {
			pre_pwr[i][j] = (pre_pwr[i][j - 1] * bad_primes[i]) % mod;
		}
	}
	build_tree(1, 1, n);
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			num_t y(x);
			mul_upd(1, 1, n, l, r, y);
		} else if (t == 2) {
			int p, x;
			cin >> p >> x;
			num_t y(x);
			div_upd(1, 1, n, p, y);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) % mod << '\n';
		}
	}
}

void build_tree(int i, int l, int r) {
	lazy[i] = num_t(1);
	if (l == r) {
		tree[i] = num_t(a[l]);
		return;
	}
	int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
	build_tree(lc, l, mid);
	build_tree(rc, mid + 1, r);
	tree[i] = tree[lc] + tree[rc];
}

void mul_upd(int i, int l, int r, int ql, int qr, num_t &x) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		lazy[i] *= x;
		tree[i] *= x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		mul_upd(lc, l, mid, ql, qr, x);
		mul_upd(rc, mid + 1, r, ql, qr, x);
		tree[i] = tree[lc] + tree[rc];
	}
}

void div_upd(int i, int l, int r, int p, num_t &x) {
	if (l > p or p > r) {
		return;
	} else if (l == r) {
		tree[i] /= x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		div_upd(lc, l, mid, p, x);
		div_upd(rc, mid + 1, r, p, x);
		tree[i] = tree[lc] + tree[rc];
	}
}

ll query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i].sum;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
	}
}

void propagate(int i, int lc, int rc) {
	lazy[lc] *= lazy[i];
	tree[lc] *= lazy[i];
	lazy[rc] *= lazy[i];
	tree[rc] *= lazy[i];
	lazy[i] = num_t(1);
}


// returns d = gcd(a,b); finds x,y such that d = ax + by
ll extended_euclid(ll v, ll b, ll &x, ll &y) {  
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = v/b;
    ll t = b; b = v%b; v = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return v;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
ll mod_inverse(ll v, ll n) {
  ll x, y;
  ll d = extended_euclid(v, n, x, y);
  if (d > 1) return -1;
  return ((x % n) + n) % n;
}