#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

const int maxn = 300;
int n, k;
char s[maxn];
bool a[3][maxn];
bool ans;
bool vis[3][maxn][2 * maxn];

void dfs(int u, int v, int t) {
    if (vis[u][v][t]) return;
    vis[u][v][t] = 1;
    if (ans) return;
    if (v == n - 1) {ans = 1; return;}
    if (a[u][v + 1 + 2 * t] && a[u][v + 1 + 2 * (t + 1) - 1] && a[u][v + 1 + 2 * (t + 1)]) dfs(u, v + 1, t + 1);
    if (u && a[u][v + 1 + 2 * t] && a[u - 1][v + 1 + 2 * t] && a[u - 1][v + 1 + 2 * (t + 1) - 1] && a[u - 1][v + 1 + 2 * (t + 1)]) dfs(u - 1, v + 1, t + 1);
    if (u < 2 && a[u][v + 1 + 2 * t] && a[u + 1][v + 1 + 2 * t] && a[u + 1][v + 1 + 2 * (t + 1) - 1] && a[u + 1][v + 1 + 2 * (t + 1)]) dfs(u + 1, v + 1, t + 1);
}

void solve() {
    int T; scanf("%d", &T);
    while (T--) {
        ms(a, 1); pi start; ans = 0; ms(vis, 0);
        scanf("%d%d", &n, &k);
        FOR(i, 0, 3) {
            scanf("%s", s);
            FOR(j, 0, n) {
                if (s[j] == 's') start = make_pair(i, j);
                a[i][j] = (s[j] == '.') || (s[j] == 's');
            }
        }
        dfs(start.first, start.second, 0);
        ans ? printf("YES\n") :printf("NO\n");
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