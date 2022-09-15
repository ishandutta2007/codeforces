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
const int maxe = 25;
int n;
int p[maxn][maxe];
int q[maxn];
int vis[maxn];
vi cyc[maxn];

int find(int idx, int k) {
	int res = idx;
	FORd(i, maxe, 0) {
		if (k >= (1 << i)) {
			res = p[res][i];
			k -= 1 << i;
		}
	}
	return res;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 1, n + 1) scanf("%d", &p[i][0]);
	FOR(j, 1, maxe) FOR(i, 1, n + 1) p[i][j] = p[p[i][j - 1]][j - 1];		
	FOR(i, 1, n + 1) {
		if (!vis[i]) {
			int cur = i, cnt = 1;
			while (1) {
				vis[cur] = 1;
				cur = p[cur][0];
				if (cur == i) break;
				cnt++;
			}
			cyc[cnt].pb(i);
		}
	}
	FOR(i, 1, n + 1) {
		if (i & 1) {
			FOR(j, 0, sz(cyc[i])) {
				int beg = cyc[i][j];
				FOR(k, 0, i) {
					q[beg] = find(beg, (i + 1) >> 1);
					beg = p[beg][0];
				}
			}
		}
		else {
			if (sz(cyc[i]) & 1) {printf("-1"); return;}
			FOR(j, 0, sz(cyc[i]) >> 1) {
				int beg1 = cyc[i][j << 1];
				int beg2 = cyc[i][(j << 1) + 1];
				vi v1, v2;
				FOR(k, 0, i) {
					v1.pb(beg1); v2.pb(beg2);
					beg1 = p[beg1][0];
					beg2 = p[beg2][0];
				}
				FOR(k, 0, i) {
					q[v1[k]] = v2[k];
					q[v2[k]] = v1[(k + 1) % i];
				}
			}
		}
	}
	FOR(i, 1, n + 1) printf("%d ", q[i]);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}