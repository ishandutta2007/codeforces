#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define sq(a) ((a)*(a))

#define MOO(i,a,b) for (int i=a; i<b; i++)
#define M00(i,a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define per(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a,b) for (int i=a; i<b; i++)

#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << endl, 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << endl;
#define _<< " _ " <<

#define int long long

template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }

typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ld,ld> pld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;

const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 1e9+7;

int POW(int b, int e) {
	int r = 1;
	while(e) {
		if(e % 2 == 1) {
			r *= b;
			r %= MOD;
		}
		e /= 2;
		b *= b;
		b %= MOD;
	}
	return r;
}
int gcd(int a, int b) {
	if(b > a) return gcd(b,a);
	if(b == 0) return a;
	return gcd(b, a % b);
}
int INV(int a) {
	return POW(a, MOD-2);
}
//Constants and Variables here


int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n; cin >> n;
	vi l(n), r(n);
	M00(i, n) cin >> l[i] >> r[i];
	
	int P = 32;
	vi ans(P);
	M00(z, P) {
		int L = 1ll << z;
		vector<pi> upd;
		int last = -1;
		int s = 0;
		M00(i, n) {
			if(r[i] - l[i] + 1 >= L) {
				s++;
			} else {
				int ll = l[i] % L;
				int rr = r[i] % L;
				if(ll <= rr) {
					upd.pb(mp(ll, 1));
					upd.pb(mp(rr+1, -1));
				} else {
					upd.pb(mp(rr+1, -1));
					upd.pb(mp(ll, 1));
					s++;
				}
			}
		}
		sort(all(upd));
		M00(i, upd.size()) {
			if(last != upd[i].f) {
				ckmax(ans[z], s);
			}
			last = upd[i].f;
			s += upd[i].s;
		}
		ckmax(ans[z], s);
	}
	int q; cin >> q;
	M00(i, q) {
		int w; cin >> w;
		M00(j, P) {
			if(w & (1ll << j)) {
				cout << ans[j] << endl;
				break;
			}
		}
	}
}