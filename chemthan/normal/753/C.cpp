#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

void ask(string s, int& x, int& y) {
	cout << s << "\n";
	cout.flush();
	#ifdef _LOCAL_
		string t = "9863";
		x = 0, y = 0;
		int cnt1[10] = {}, cnt2[10] = {};
		FOR(i, 0, 4) {
			if (s[i] == t[i]) {
				x++;
			}
			else {
				cnt1[s[i] - '0']++;
				cnt2[t[i] - '0']++;
			}
		}
		FOR(i, 0, 10) y += min(cnt1[i], cnt2[i]);
	#else
		cin >> x >> y;
	#endif
}

void upd(string s, string t, int&x, int& y) {
	int cnt1[10] = {}, cnt2[10] = {};
	x = y = 0;
	FOR(i, 0, 4) {
		if (s[i] == t[i]) {
			x++;
		}
		else {
			cnt1[s[i] - '0']++;
			cnt2[t[i] - '0']++;
		}
	}
	FOR(i, 0, 10) y += min(cnt1[i], cnt2[i]);
}

string get(set<string>& s) {
	pair<int, string> best = mp(-INF, "");
	FORall(it1, s) {
		string s1 = *it1;
		int mn = INF;
		FORall(it2, s) {
			string s2 = *it2;
			int x, y; upd(s1, s2, x, y);
			int tot = 0;
			FORall(it3, s) {
				string s3 = *it3;
				int x2, y2; upd(s1, s3, x2, y2);
				if (x != x2 || y != y2) {
					tot++;
				}
			}
			chkmin(mn, tot);
		}
		chkmax(best, mp(mn, s1));
	}
	return best.se;
}

void solve() {
	set<string> st;
	FOR(i, 0, 10) FOR(j, 0, 10) FOR(k, 0, 10) FOR(l, 0, 10) {
		if (i - j && i - k && i - l && j - k && j - l && k - l) {
			string s = "";
			s += char('0' + i);
			s += char('0' + j);
			s += char('0' + k);
			s += char('0' + l);
			st.insert(s);
		}
	}
	while (1) {
		string s = sz(st) > 100 ? *st.begin() : get(st);
		st.erase(s);
		int x, y;
		ask(s, x, y);
		if (x == 4) return;
		vector<string> rem;
		FORall(it, st) {
			string t = *it;
			int tx, ty;
			upd(s, t, tx, ty);
			if (x != tx || y != ty) {
				rem.pb(t);
			}
		}
		FOR(i, 0, sz(rem)) st.erase(rem[i]);
	}
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