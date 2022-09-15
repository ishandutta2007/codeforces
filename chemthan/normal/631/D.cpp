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
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200010;
int n, m;
string s, t;
int hashs[maxn * 13];
int hasht[maxn * 13];
int pw[maxn * 13];
int rp[maxn * 13];

string convert(ll k) {
	string res;
	while (k) {
		res += char('0' + k % 10);
		k /= 10;
	}
	while (sz(res) < 12) res += "0";
	reverse(all(res));
	return res;
}

int calcs(int l, int r) {
	if (!l) return hashs[r];
	return (ll) (hashs[r] - hashs[l - 1] + MOD) * rp[l] % MOD;
}

int calct(int l, int r) {
	if (!l) return hasht[r];
	return (ll) (hasht[r] - hasht[l - 1] + MOD) * rp[l] % MOD;
}

ll calc(string& s, int idx) {
	ll res = 0;
	FOR(i, idx, idx + 12) {
		res = res * 10 + s[i] - '0';
	}
	return res;
}

void solve() {
	pw[0] = 1; FOR(i, 1, maxn * 13) pw[i] = mult(pw[i - 1], 2311);
	rp[0] = 1; rp[1] = inv(pw[1]); FOR(i, 1, maxn * 13) rp[i] = mult(rp[i - 1], rp[1]);
	cin>>n>>m;
	vector<pair<char, ll> > vs;
	vector<pair<char, ll> > vv;
	FOR(i, 0, n) {
		string str; cin>>str;
		FOR(j, 0, sz(str)) {
			if (str[j] == '-') {
				char x = str[j + 1];
				ll y = 0;
				FOR(k, 0, j) {
					y = y * 10 + str[k] - '0';
				}
				vs.pb(mp(x, y));
				break;
			}
		}
	}
	int cur = -1;
	FOR(i, 0, sz(vs)) {
		if (vs[i].fi == cur) {
			vv.back().se += vs[i].se;
		}
		else {
			vv.pb(vs[i]);
			cur = vs[i].fi;
		}
	}
	FOR(i, 0, sz(vv)) {
		s += vv[i].fi + convert(vv[i].se);
	}
	vs.clear(); vv.clear();
	FOR(i, 0, m) {
		string str; cin>>str;
		FOR(j, 0, sz(str)) {
			if (str[j] == '-') {
				char x = str[j + 1];
				ll y = 0;
				FOR(k, 0, j) {
					y = y * 10 + str[k] - '0';
				}
				vs.pb(mp(x, y));
				break;
			}
		}
	}
	cur = -1;
	FOR(i, 0, sz(vs)) {
		if (vs[i].fi == cur) {
			vv.back().se += vs[i].se;
		}
		else {
			vv.pb(vs[i]);
			cur = vs[i].fi;
		}
	}
	FOR(i, 0, sz(vv)) {
		t += vv[i].fi + convert(vv[i].se);
	}
	FOR(i, 0, sz(s)) {
		if (!i) hashs[i] = s[i];
		else addmod(hashs[i], (hashs[i - 1] + (ll) pw[i] * s[i]) % MOD);
	}
	FOR(i, 0, sz(t)) {
		if (!i) hasht[i] = t[i];
		else addmod(hasht[i], (hasht[i - 1] + (ll) pw[i] * t[i]) % MOD);
	}
	ll ans = 0;
	FOR(i, 0, sz(s) - sz(t) + 1) {
		if (s[i] == t[0] && calc(s, i + 1) >= calc(t, 1)) {
			if (sz(t) == 13) {
				ans += calc(s, i + 1) - calc(t, 1) + 1;
			}
			else {
				if (calcs(i + 13, i + sz(t) - 14) == calct(13, sz(t) - 14)) {
					if (s[i + sz(t) - 13] == t[sz(t) - 13]) {
						if (calc(s, i + sz(t) - 12) >= calc(t, sz(t) - 12)) {
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans;
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}