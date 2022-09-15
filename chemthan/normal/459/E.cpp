#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 300010;
int n, m;
int d[maxn];
int e[maxn];

void solve() {
	scanf("%d%d", &n, &m);
	vector<pair<int, pi> > edges;
	FOR(i, 0, m) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w); u--; v--;
		edges.pb(mp(w, mp(u, v)));
	}
	sort(all(edges));
	int ans = 0, cur = 0;
	FOR(i, 0, sz(edges)) {
		int w = edges[i].fi;
		int u = edges[i].se.fi;
		int v = edges[i].se.se;
		vi t;
		while (cur < sz(edges) && edges[cur].fi < w) {
			int _u = edges[cur].se.fi;
			int _v = edges[cur].se.se;
			e[_v] = max(e[_v], d[_u] + 1);
			t.pb(_v);
			cur++;
		}
		FOR(i, 0, sz(t)) d[t[i]] = e[t[i]];
		ans = max(ans, 1 + d[u]);
	}
	printf("%d", ans);
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