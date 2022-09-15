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

const int maxn = 100010;
int n, m;

ll st[4 * maxn];
ll lz[4 * maxn];
void updatelz(int node, int L, int R) {
	if (lz[node]) {
		st[node] += (ll) (R - L + 1) * lz[node];
		if (L < R) {
			lz[node << 1] += lz[node];
			lz[(node << 1) + 1] += lz[node];
		}
		lz[node] = 0;
	}
}
void update(int node, int l, int r, int L, int R, int x) {
	updatelz(node, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		st[node] += (ll) (R - L + 1) * x;
		if (L < R) {
			lz[node << 1] += x;
			lz[(node << 1) + 1] += x;
		}
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, x);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, x);
	st[node] = st[node << 1] + st[(node << 1) + 1];
}
ll query(int node, int l, int r, int L, int R) {
	updatelz(node, L, R);
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[node];
	return query(node << 1, l, r, L, (L + R) >> 1) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
}

void solve() {
	scanf("%d%d", &n, &m);
	set<pi> st; FOR(i, 0, n) st.insert(mp(i, i));
	while (m--) {
		int op, l, r; scanf("%d%d%d", &op, &l, &r); l--; r--;
		if (op == 1) {
			int x; scanf("%d", &x); x--;
			set<pi>::iterator it1 = st.lower_bound(mp(l, -2 * INF));
			set<pi>::iterator it2 = st.upper_bound(mp(r, +2 * INF));
			int cur = l, color = it1->se;
			if (it1->fi > l) {it1--; color = it1->se; it1++;}
			vii del;
			for (set<pi>::iterator it = it1; it != it2; it++) {
				int nxt = it->fi;
				update(1, cur, nxt - 1, 0, n - 1, abs(color - x));
				cur = nxt; color = it->se;
				del.pb(*it);
			}
			update(1, cur, r, 0, n - 1, abs(color - x));
			FOR(i, 0, sz(del)) st.erase(del[i]);
			st.insert(mp(l, x));
			if (it2 == st.end() || it2->fi > r + 1) st.insert(mp(r + 1, color));
		}
		else {
			printf("%I64d\n", query(1, l, r, 0, n - 1));
		}
	}
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