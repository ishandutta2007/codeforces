#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

int compare(pi a, pi b) {
	return (ll) a.fi * b.se > (ll) a.se * b.fi;
}

void solve() {
	int n; cin>>n;
	vii v(n);
	ll ttime = 0;
	FOR(i, 0, n) cin>>v[i].fi;
	FOR(i, 0, n) cin>>v[i].se, ttime += v[i].se;
	sort(all(v), compare);
	ld l = 0, r = 1;
	FOR(_, 0, 30) {
		ld m = (l + r) / 2;
		ll t = 0;
		int cur = 0;
		vector<pair<int, pair<ld, ld> > > vx;
		FOR(i, 1, n + 1) {
			if (i == n || (ll) v[i].fi * v[i - 1].se != (ll) v[i].se * v[i - 1].fi) {
				ll tot = 0;
				FOR(j, cur, i) {
					tot += v[j].se;
				}
				FOR(j, cur, i) {
					ld dmin = v[j].fi * (1 - m * (t + tot) / ttime);
					ld dmax = v[j].fi * (1 - m * (t + v[j].se) / ttime);
					vx.pb(mp(v[j].fi, mp(dmin, dmax)));
				}
				cur = i;
				t += tot;
			}
		}
		sort(all(vx));
		int ok = 1;
		ld dmax = 0;
		FOR(i, 0, n) {
			if (vx[i].se.fi < dmax) {
				ok = 0;
				break;
			}
			ld tmp = vx[i].se.se;
			int cur = i++;
			while (i < n && vx[i].fi == vx[cur].fi) {
				if (vx[cur].se.fi < dmax) {
					ok = 0;
					break;
				}
				setmax(tmp, vx[i].se.se);
				i++;
			}
			setmax(dmax, tmp);
			i--;
		}
		if (ok) l = m; else r = m;
	}
	cout<<prec(9)<<l<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}