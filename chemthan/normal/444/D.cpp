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

const int maxn = 60010;
const int maxq = 100010;
int n, q;
string s;
vii d[maxn];
vi pos[10 * maxn];
vector<pair<pair<string, string>, int> > query;
int ans[maxq];
int tb[10 * maxn];

int hash(string s) {
	int res = 0;
	FOR(i, 0, sz(s)) res = res * 27 + s[i] - 'a' + 1;
	return res;
}

int calc(int pos1, int pos2, int len1, int len2) {
	return max(pos1 + len1, pos2 + len2) - min(pos1, pos2);
}

void solve() {
	cin>>s>>q; n = sz(s);
	int m = n / sqrt(q);
	FOR(i, 0, n) FOR(j, 1, min(4, n - i) + 1) {
		int k = hash(s.substr(i, j));
		d[i].pb(mp(k, j)); pos[k].pb(i);
	}
	FOR(i, 0, q) {
		string u, v; cin>>u>>v;
		int p = hash(u), q = hash(v);
		if (sz(pos[p]) < sz(pos[q])) {swap(u, v); swap(p, q);}
		if (!sz(pos[q])) {ans[i] = -1; continue;}
		if (sz(pos[p]) < m) {
			ans[i] = INF;
			int cur = 0;
			FOR(j, 0, sz(pos[p])) {
				while (cur + 1 < sz(pos[q]) && pos[q][cur + 1] <= pos[p][j]) cur++;
				ans[i] = min(ans[i], calc(pos[p][j], pos[q][cur], sz(u), sz(v)));
				if (cur + 1 < sz(pos[q])) ans[i] = min(ans[i], calc(pos[p][j], pos[q][cur + 1], sz(u), sz(v)));
			}
			if (ans[i] == INF) ans[i] = -1;
		}
		else {
			query.pb(mp(mp(u, v), i));
		}
	}
	sort(all(query)); query.pb(mp(mp("", ""), 0));
	int cur = 0; FOR(i, 0, 10 * maxn) tb[i] = INF;
	FOR(i, 0, sz(query) - 1) {
		if (query[i].fi.fi != query[i + 1].fi.fi) {
			vi his;
			int p = hash(query[i].fi.fi), idx = 0;
			FOR(j, 0, n) {
				while (idx + 1 < sz(pos[p]) && pos[p][idx + 1] <= j) idx++;
				FOR(k, 0, sz(d[j])) {
					tb[d[j][k].fi] = min(tb[d[j][k].fi], calc(pos[p][idx], j, sz(query[i].fi.fi), d[j][k].se));
					if (idx + 1 < sz(pos[p])) tb[d[j][k].fi] = min(tb[d[j][k].fi], calc(pos[p][idx + 1], j, sz(query[i].fi.fi), d[j][k].se));
					his.pb(d[j][k].fi);
				}
			}
			FOR(j, cur, i + 1) {
				int k = hash(query[j].fi.se);
				int idx = query[j].se;
				ans[idx] = tb[k];
				if (ans[idx] == INF) ans[idx] = -1;
			}
			FOR(j, 0, sz(his)) tb[his[j]] = INF;
			cur = i + 1;
		}
	}
	FOR(i, 0, q) printf("%d\n", ans[i]);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}