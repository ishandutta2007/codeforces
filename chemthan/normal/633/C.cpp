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

struct HashModule {
	int mod;
	vector<int> h, pw, rp;
	int inv(int n) {
		int r = n, t = n, k = mod - 3;
		while (k) {
			if (k & 1) r = (long long) r * t % mod;
			t = (long long) t * t % mod;
			k >>= 1;
		}
		return r;
	}
	void init(string s, int base, int p) {
		mod = p;
		h.resize(s.size()); pw.resize(s.size()); rp.resize(s.size());
		pw[0] = 1;
		for (int i = 1; i < s.size(); i++) {
			pw[i] = (long long) pw[i - 1] * base % mod;
		}
		rp[0] = 1; rp[1] = inv(base);
		for (int i = 1; i < s.size(); i++) {
			rp[i] = (long long) rp[i - 1] * rp[1] % mod;
		}
		for (int i = 0; i < s.size(); i++) {
			if (!i) {
				h[i] = s[i];
			}
			else {
				h[i] = h[i - 1] + (long long) s[i] * pw[i] % mod;
				if (h[i] >= mod) {
					h[i] -= mod;
				}
			}
		}
	}
	int query(int l, int r) {
		if (!l) return h[r];
		return (long long) (h[r] - h[l - 1] + mod) * rp[l] % mod;
	}
};
struct DoubleHash {
	HashModule hm1, hm2;
	void init(string s, int base1, int mod1, int base2, int mod2) {
		hm1.init(s, base1, mod1);
		hm2.init(s, base2, mod2);
	}
	pair<int, int> query(int l, int r) {
		return make_pair(hm1.query(l, r), hm2.query(l, r));
	}
};

const int maxn = 10010;
const int maxm = 100010;
int n, m;
string s;
string t[maxm];
int f[maxn];
DoubleHash dhashs, dhasht[maxm];
map<pi, int> tb;
string ans;

int go(int pos) {
	if (pos == n) {
		return n;
	}
	int& res = f[pos];
	if (~res) return res;
	res = INF;
	FOR(i, pos, min(pos + 1010, n)) {
		pi r = dhashs.query(pos, i);
		if (tb.count(r)) {
			if (go(i + 1) < INF) {
				return res = tb[r];
			}
		}
	}
	return res;
}

void trace(int pos) {
	if (pos == n) {
		return;
	}
	int nxt = f[pos];
	ans += t[nxt] + " ";
	trace(pos + sz(t[nxt]));
}

void solve() {
	cin>>n>>s>>m;
	dhashs.init(s, 2311, (int) 1e9 + 7, 1992, (int) 1e8 + 7);
	FOR(i, 0, m) {
		cin>>t[i];
		string str = t[i];
		FOR(j, 0, sz(str)) {
			if (str[j] >= 'A' && str[j] <= 'Z') str[j] += 'a' - 'A';
		}
		reverse(all(str));
		dhasht[i].init(str, 2311, (int) 1e9 + 7, 1992, (int) 1e8 + 7);
		tb[dhasht[i].query(0, sz(str) - 1)] = i;
	}
	ms(f, -1);
	go(0); trace(0);
	FOR(i, 0, sz(ans) - 1) cout<<ans[i];
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