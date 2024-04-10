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

const int maxn = 200010;
int n;
int a[maxn];
map<pi, int> tb;
int f[maxn];
int g[maxn];
int tot;

int check(int idx) {
	if (idx & 1) {
		if (a[idx] <= a[idx - 1]) {
			return 0;
		}
		if (idx < n - 1 && a[idx] <= a[idx + 1]) {
			return 0;
		}
	}
	else {
		if (idx && a[idx] >= a[idx - 1]) {
			return 0;
		}
		if (idx < n - 1 && a[idx] >= a[idx + 1]) {
			return 0;
		}
	}
	return 1;
}

ll work(int idx) {
	if (idx < 0 || idx >= n) return 0;
	if (f[idx]) return 0;
	f[idx] = 1;
	ll res = 0;
	FOR(i, 0, n) {
		if (i != idx && !tb.count(mp(i, idx))) {
			tb[mp(i, idx)]; tb[mp(idx, i)];
			swap(a[i], a[idx]);
			
			int flag = 1;
			
			if (!check(i)) flag = 0;
			if (i && !check(i - 1)) flag = 0;
			if (i < n - 1 && !check(i + 1)) flag = 0;
			if (!check(idx)) flag = 0;
			if (idx && !check(idx - 1)) flag = 0;
			if (idx < n - 1 && !check(idx + 1)) flag = 0;
			
			int r = 0;
			
			vi v; v.pb(i);
			if (i) v.pb(i - 1);
			if (i < n - 1) v.pb(i + 1);
			v.pb(idx); if (idx) v.pb(idx - 1);
			if (idx < n - 1) v.pb(idx + 1);
			sort(all(v)); uni(v);
			
			FOR(j, 0, sz(v)) {
				int u = v[j];
				if (g[u]) r++;
			}
			
			if (flag && r == tot) {
				res++;
			}
			
			swap(a[i], a[idx]);
		}
	}
	return res;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	int idx1 = -1, idx2 = -1;
	for (int i = 0; i < n - 1; i += 2) {
		if (a[i] >= a[i + 1]) {
			idx1 = i;
			g[i] = 1;
			tot++;
		}
	}
	for (int i = 1; i < n - 1; i += 2) {
		if (a[i] <= a[i + 1]) {
			idx2 = i;
			g[i] = 1;
			tot++;
		}
	}
	ll ans = work(idx1 - 1) + work(idx1) + work(idx1 + 1);
	ans += work(idx2 - 1) + work(idx2) + work(idx2 + 1);
	printf("%I64d\n", ans);
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