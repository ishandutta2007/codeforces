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

const int MAXN = 1000010;
bool flag[MAXN];
int sp[MAXN];
void Sieve() {
	for (int i = 2; i < MAXN; i += 2) sp[i] = 2;
	for (int i = 3; i < MAXN; i += 2) if (!flag[i]) {
		sp[i] = i;
		for (int j = i; 1LL * i * j < MAXN; j += 2) if (!flag[i * j]) {
			flag[i * j] = 1;
			sp[i * j] = i;
		}
	}
}

const int maxn = 1000010;
vii fac[maxn];
vi dvs[maxn];
int num[maxn];
int cnt[maxn];
int f[maxn];
int g[maxn];
int sum[maxn];

void go(int idx, int pos, int cur) {
	if (pos == sz(fac[idx])) return;
	FOR(i, 0, fac[idx][pos].se + 1) {
		go(idx, pos + 1, cur);
		if (i) dvs[idx].pb(cur);
		cur *= fac[idx][pos].fi;
	}
}

int binomial(int a, int b) {
	if (a > b) return 0;
	if (!a || a == b) return 1;
	return mult(f[b], mult(g[a], g[b - a]));
}

void solve() {
	f[0] = 1; FOR(i, 1, maxn) f[i] = mult(f[i - 1], i);
	FOR(i, 0, maxn) g[i] = inv(f[i]);
	Sieve();
	FOR(i, 1, maxn) {
		int t = i;
		num[i] = 1;
		while (t > 1) {
			int k = sp[t], cnt = 0;
			while (sp[t] == k) {
				cnt++;
				t /= sp[t];
			}
			fac[i].pb(mp(k, cnt));
			if (cnt > 1) num[i] = 0;
			else num[i] *= -1;
		}
		dvs[i].pb(1); go(i, 0, 1);
	}
	FOR(i, 1, maxn) {
		FOR(j, 0, sz(dvs[i])) {
			int x = dvs[i][j];
			int y = i / x;
			addmod(sum[i], mult(num[y] + MOD, x));
		}
	}
	int n, k, q; scanf("%d%d%d", &n, &k, &q);
	int ans = 0;
	FOR(_, 0, n + q) {
		int a; scanf("%d", &a);
		FOR(i, 0, sz(dvs[a])) {
			int x = dvs[a][i];
			addmod(ans, mult(sum[x], binomial(k - 1, cnt[x])));
		}
		if (_ >= n) {
			printf("%d\n", ans);
		}
		FOR(i, 0, sz(dvs[a])) {
			int x = dvs[a][i];
			cnt[x]++;
		}
	}
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