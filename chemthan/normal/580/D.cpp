#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 20;
int n, m, k;
int a[maxn];
int d[maxn][maxn];
ll f[maxn][1 << maxn];

int popcount(int k) {
    int res = 0;
    while (k) {if (k & 1) res++; k >>= 1;}
    return res;
}

ll cal(int cur, int mask) {
    if (popcount(mask) == m) return 0;
    if (f[cur][mask] != -1) return f[cur][mask];
    ll res = 0;
    FOR(i, 0, n) if (!(mask & (1 << i))) {
        res = max(res, cal(i, mask | (1 << i)) + a[i] + d[cur][i]);
    }
    return f[cur][mask] = res;
}

void solve() {
    ms(f, -1);
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 0, n) scanf("%d", a + i);
    FOR(i, 0, k) {
        int x, y, c; scanf("%d%d%d", &x, &y, &c); x--; y--; d[x][y] = c;
    }
    ll ans = 0;
    FOR(i, 0, n) ans = max(ans, cal(i, 1 << i) + a[i]);
    printf("%I64d", ans);
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