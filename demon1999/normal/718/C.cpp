#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
const ll szz1 = 1024 * 64, szz = 1024 * 128, mod = ll(1e9) + 7;

int n, m, a;
pair<pll, pll> seg[2 * szz], psh[2 * szz];
string s;

pair<pll, pll> qq;


ll get_md(ll k) {
	re k % mod;
}

ll get_fib(pair<pll, pll> k) {
   re k.fi.se;
}

pair<pll, pll> multiply(pair<pll, pll> a, pair<pll, pll> b) {
	pair<pll, pll> ans = mp(mp(get_md(a.fi.fi * b.fi.fi + a.fi.se * b.se.fi),
							   get_md(a.fi.fi * b.fi.se + a.fi.se * b.se.se)), 
							mp(get_md(a.se.fi * b.fi.fi + a.se.se * b.se.fi),
							   get_md(a.se.fi * b.fi.se + a.se.se * b.se.se)));
	re ans;
}
pair<pll, pll> pow1(ll k) {
	//k %= (mod - 1);
	pair<pll, pll> ans = mp(mp(1, 0), mp(0, 1)); 
    pair<pll, pll> pp = mp(mp(1, 1), mp(1, 0));
    for (ll i = 0; (1 << i) <= k; i++) {
    	if (k & (1 << i))
    		ans = multiply(ans, pp);
    	pp = multiply(pp, pp);
    }
	re ans;
}

ll get_(int nu, int l, int r, int ql, int qr, pair<pll, pll> k) {
    //cout << nu << " " << l << " " << r << " " << k;
    if (r <= ql || l >= qr) {
		re 0;
	}	
	if (ql <= l && r <= qr) {
		re get_fib(multiply(seg[nu], k)) % mod;
	}
	k = multiply(psh[nu], k);
	int mid = (l + r) / 2;
	re (get_(2 * nu, l, mid, ql, qr, k) + get_(2 * nu + 1, mid, r, ql, qr, k)) % mod;
}

void add_(int nu, int l, int r, int ql, int qr, pair<pll, pll> k) {
	if (r <= ql || l >= qr) {
		re;
	}
	if (ql <= l && r <= qr) {
		psh[nu] = multiply(psh[nu], k);
		seg[nu] = multiply(seg[nu], k);
		re;
	}
	int mid = (l + r) / 2;
	add_(2 * nu, l, mid, ql, qr, k);
	add_(2 * nu + 1, mid, r, ql, qr, k);
	pair<pll, pll> seg1 = seg[2 * nu],
				   seg2 = seg[2 * nu + 1]; 
	seg[nu] = multiply(mp(mp(seg1.fi.fi + seg2.fi.fi, 
					seg1.fi.se + seg2.fi.se),
				 mp(seg1.se.fi + seg2.se.fi, 
					seg1.se.se + seg2.se.se)), psh[nu]);
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m;
	forn (i, n) {
		cin >> a;
		seg[i + szz] = pow1(a); 
	}
	forn (i, 2 * szz)
		psh[i] = pow1(0); 
	for (int i = szz - 1; i; i--) {
		seg[i] = mp(mp((seg[2 * i].fi.fi + seg[2 * i + 1].fi.fi) % mod,
			           (seg[2 * i].fi.se + seg[2 * i + 1].fi.se) % mod), 
					mp((seg[2 * i].se.fi + seg[2 * i + 1].se.fi) % mod,
			           (seg[2 * i].se.se + seg[2 * i + 1].se.se) % mod));
	}
	for (int i = 0; i < m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		l--;
		l += szz;
		r += szz;
		if (t == 1) {
			ll k;
			cin >> k;
			add_(1, szz, 2 * szz, l, r, pow1(k));
		}
		else {
			cout << get_(1, szz, 2 * szz, l, r, pow1(0)) << "\n";
		}
	}
	re 0;
}