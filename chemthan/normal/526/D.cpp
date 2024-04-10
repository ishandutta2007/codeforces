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
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 1000010;
int n, k;
char s[maxn];
int p[maxn];
int rp[maxn];
int hash[maxn];
int d[maxn];

int calc(int l, int r) {
	if (!l) return hash[r];
	return (ll) (hash[r] - hash[l - 1] + MOD) * rp[l] % MOD;
}

void solve() {
	p[0] = 1; FOR(i, 1, maxn) p[i] = 2311LL * p[i - 1] % MOD;
	rp[0] = 1; rp[1] = fpow(2311LL, MOD - 2); FOR(i, 2, maxn) rp[i] = (ll) rp[1] * rp[i - 1] % MOD;
	scanf("%d%d%s", &n, &k, s);
	FOR(i, 0, n) {
		if (!i) hash[i] = s[i];
		else hash[i] = (hash[i - 1] + (ll) p[i] * s[i]) % MOD;
	}
	FOR(i, 1, n + 1) {
		int j, cnt = 0;
		for (j = 0; j + i - 1 < n; j += i) {
			if (calc(j, j + i - 1) != calc(0, i - 1)) break;
			if (++cnt == k) break;
		}
		j += i;
		if (cnt == k) {
			d[j - 1]++;
			d[j]--;
			int l = 0, r = min(i - 1, n - j - 1);
			while (l < r) {
				int m = (l + r + 1) >> 1;
				if (calc(0, m) == calc(j, j + m)) l = m; else r = m - 1;
			}
			if (calc(0, l) == calc(j, j + l)) {
				d[j]++;
				d[j + l + 1]--;
			}
		}
	}
	FOR(i, 1, n) d[i] += d[i - 1];
	FOR(i, 0, n) printf("%d", d[i] > 0);
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