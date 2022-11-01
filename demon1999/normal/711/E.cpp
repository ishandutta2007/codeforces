#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define mp1(a, b, c, d) mp(mp(a, b), mp(c, d))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll inf = ll(1e9) + 7, mod = 1000003;

ll n, k;

ll pow1(ll a, ll st) {
	if (st == 0) re 1;
	if (st == 1) re a % mod;
	ll ans = pow1(a, st / 2);
	re (((ans * ans) % mod) * pow1(a, st % 2)) % mod;
}

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> k;
	ll cc = 1;
	forn (i, n) {
		cc *= 2LL;
		if (cc >= max(1000003LL, k)) {
			break;
		}
	}
	if (k > cc) {
		cout << "1 1\n";
		re 0;
	}
	if (cc >= 1000003) {
		//assert(0);
		ll ost = 0, p1 = n % (mod - 1);
		ll kk = 2LL;
		for (int i = 1; i <= 60; i++) {
			p1 += (k - 1LL) / kk;
			p1 %= (mod - 1);
			kk *= 2LL;
		}
		if (k < 1000003) {
			ll ost1 = pow1(2, n);
			ost = 1LL;
			forn (i, k) {
				ost *= ost1;
				ost %= mod;
				ost1 = (ost1 - 1LL + mod) % mod;
			}
		}
		//cout << ((p1 - n) % (mod - 1) + mod - 1) % (mod - 1) << "\n";
		ll st = (n % (mod - 1)) * (k % (mod - 1));
		ll cp = pow1(2, p1);
		ost = (ost * pow1(cp, mod - 2)) % mod;
		ll cq = (((pow1(2, st)) % mod) * pow1(cp, mod - 2)) % mod;
		cout << (((cq - ost) % mod) + mod) % mod << " " << cq << "\n";
		re 0;
	}
	ll c1 = 1LL, p1 = 0;
	for (ll i = cc - k + 1LL; i <= cc; i++) {
		ll q = i;
		while (q % 2 == 0) {
			p1++;
			q /= 2;
		}
		c1 *= q;
		c1 %= mod;
	}
	ll a = ((pow1(2, n * k - p1) - c1) % mod + mod) % mod,
		b = pow1(2, n * k - p1);
	cout << a << " " << b << endl;
	re 0;
}