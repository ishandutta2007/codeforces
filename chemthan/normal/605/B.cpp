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
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
int n, m;
pi ans[maxn];
map<pi, int> tb;

void solve() {
	scanf("%d%d", &n, &m);
	vii x, y;
	FOR(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b);
		if (b) x.pb(mp(a, i));
		else y.pb(mp(a, i));
	}
	sort(all(x)); sort(all(y));
	FOR(i, 0, sz(x)) ans[x[i].se] = mp(0, i + 1);
	set<pi> st;
	FOR(i, 0, min(1000, sz(x))) FOR(j, 0, i) st.insert(mp(i, j));
	FORd(i, sz(y), 0) {
		if (!sz(st)) {printf("-1"); return;}
		int a = y[i].fi;
		int k = y[i].se;
		int d = upper_bound(all(x), mp(a + 1, -INF)) - x.begin();
		set<pi>::iterator it = st.upper_bound(mp(d, -INF));
		if (it == st.begin()) {printf("-1"); return;} it--;
		ans[k] = mp(it->fi + 1, it->se + 1); st.erase(it);
	}
	FOR(i, 0, m) {
		printf("%d %d\n", ans[i].fi + 1, ans[i].se + 1);
	}
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