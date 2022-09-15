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

const int maxn = 1010;
int n, m;
int a[maxn][maxn];
int id[maxn][maxn];
char s[maxn];

int dj[maxn * maxn];
int sz[maxn * maxn];
void init() {
	FOR(i, 0, maxn * maxn) {
		dj[i] = i;
		sz[i] = 1;
	}
}
int find(int u) {
	return dj[u] == u ? u : dj[u] = find(dj[u]);
}
void join(int u, int v) {
	int p = find(u);
	int q = find(v);
	if (p == q) return;
	sz[q] += sz[p];
	dj[p] = q;
}

void solve() {
	scanf("%d%d", &n, &m);
	int cnt = 0;
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, m) {
			a[i][j] = s[j] == '.';
			id[i][j] = cnt++;
		}
	}
	init();
	FOR(i, 0, n) {
		FOR(j, 0, m) if (a[i][j]) {
			int u = id[i][j];
			if (i && a[i - 1][j]) {
				int v = id[i - 1][j];
				join(u, v);
			}
			if (i < n - 1 && a[i + 1][j]) {
				int v = id[i + 1][j];
				join(u, v);
			}
			if (j && a[i][j - 1]) {
				int v = id[i][j - 1];
				join(u, v);
			}
			if (j < m - 1 && a[i][j + 1]) {
				int v = id[i][j + 1];
				join(u, v);
			}
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, m) if (!a[i][j]) {
			vi v;
			if (i && a[i - 1][j]) {
				v.pb(find(id[i - 1][j]));
			}
			if (i < n - 1 && a[i + 1][j]) {
				v.pb(find(id[i + 1][j]));
			}
			if (j && a[i][j - 1]) {
				v.pb(find(id[i][j - 1]));
			}
			if (j < m - 1 && a[i][j + 1]) {
				v.pb(find(id[i][j + 1]));
			}
			sort(all(v)); uni(v);
			int ans = 0; FOR(k, 0, sz(v)) ans += sz[v[k]];
			printf("%d", (ans + 1) % 10);
		}
		else printf(".");
		printf("\n");
	}
}

int main() {
//  ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}