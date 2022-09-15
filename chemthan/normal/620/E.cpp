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

const int maxn = 400010;
const int maxc = 61;
int n, q;
vi adj[maxn];
int c[maxn];
int tin[maxn];
int tou[maxn];
int tms;

bitset<maxc> st[8 * maxn], null;
int lz[8 * maxn];
void updatelz(int node, int L, int R) {
	if (~lz[node]) {
		st[node].reset();
		st[node][lz[node]] = 1;
		if (L < R) {
			lz[node << 1] = lz[node];
			lz[(node << 1) + 1] = lz[node];
		}
		lz[node] = -1;
	}	
}	
void update(int node, int l, int r, int L, int R, int c) {
	updatelz(node, L, R);
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
    	lz[node] = c;
    	updatelz(node, L, R);
    	return;
    }
    update(node << 1, l, r, L, (L + R) >> 1, c);
    update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, c);
    st[node] = st[node << 1] | st[(node << 1) + 1];
}
bitset<maxc> query(int node, int l, int r, int L, int R) {
	updatelz(node, L, R);
    if (l > R || r < L) return null;
    if (l <= L && r >= R) return st[node];
    return query(node << 1, l, r, L, (L + R) >> 1) | query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
}

void dfs(int u, int p = -1) {
    tin[u] = tms++;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (v != p) dfs(v, u);
    }
    tou[u] = tms++;
}

void solve() {
	ms(lz, -1);
    scanf("%d%d", &n, &q);
    FOR(i, 0, n) {scanf("%d", c + i); c[i]--;}
    FOR(i, 0, n - 1) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(0);
    FOR(i, 0, n) {
    	update(1, tin[i], tin[i], 0, (n << 1) - 1, c[i]);
    }
    while (q--) {
        int k, u; scanf("%d%d", &k, &u); u--;
        if (k == 1) {
        	int c; scanf("%d", &c); c--;
            update(1, tin[u], tou[u] - 1, 0, (n << 1) - 1, c);
            update(1, tin[u], tou[u] - 1, 0, (n << 1) - 1, c);
        }
        else {
        	printf("%d\n", query(1, tin[u], tou[u] - 1, 0, (n << 1) - 1).count());
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