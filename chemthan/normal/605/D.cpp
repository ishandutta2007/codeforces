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
int n;
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
map<int, int> dc;
vii v[maxn << 1];
int lev[maxn];
int p[maxn];

pi st[8 * maxn];
void update(int node, int i, int L, int R, pi val) {
	if (i < L || i > R) return;
	if (L == R) {st[node] = val; return;}
	update(node << 1, i, L, (L + R) >> 1, val);
	update((node << 1) + 1, i, ((L + R) >> 1) + 1, R, val);
	st[node] = min(st[node << 1], st[(node << 1) + 1]);
}
pi query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return mp(INF, INF);
	if (l <= L && r >= R) return st[node];
	return min(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

int compare(pi a, pi b) {
	return a > b;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
		dc[a[i]]; dc[c[i]];
	}
	int cnt = 0;
	FORall(it, dc) it->se = cnt++;
	FOR(i, 0, n) {
		a[i] = dc[a[i]];
		c[i] = dc[c[i]];
		v[a[i]].pb(mp(b[i], i));
	}
	FOR(i, 0, cnt) {
		v[i].pb(mp(INF, INF));
		sort(all(v[i]), compare);
		update(1, i, 0, cnt - 1, v[i].back());
		v[i].pop_back();
	}
	queue<pair<pi, int> > q; q.push(mp(mp(0, 0), n));
	while (sz(q)) {
		int x = q.front().fi.fi;
		int y = q.front().fi.se;
		int z = q.front().se;
		q.pop();
		while (1) {
			pi r = query(1, 0, x, 0, cnt - 1);
			if (r.fi <= y) {
				int k = r.se;
				lev[k] = lev[z] + 1; p[k] = z;
				if (k == n - 1) {
					printf("%d\n", lev[k]);
					vi ans;
					while (k != n) {
						ans.pb(k);
						k = p[k];
					}
					reverse(all(ans));
					FOR(i, 0, sz(ans)) printf("%d ", ans[i] + 1);
					return;
				}
				q.push(mp(mp(c[k], d[k]), k));
				update(1, a[k], 0, cnt - 1, v[a[k]].back());
				v[a[k]].pop_back();
			}
			else break;
		}
	}
	printf("-1");
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