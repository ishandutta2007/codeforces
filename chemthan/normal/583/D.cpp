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

const int maxn = 110;
int n, t;
int a[maxn];
int f[maxn][maxn];

struct matrix {
    int x[maxn][maxn];
    matrix() {ms(x, 0);}
};

matrix mul(matrix A, matrix B) {
    matrix res;
    FOR(i, 0, n) FOR(j, 0, n) {
        res.x[i][j] = -INF;
        FOR(k, 0, n) res.x[i][j] = max(res.x[i][j], A.x[i][k] + B.x[k][j]);
    }
    return res;
}

matrix ex(matrix A, int k) {
    matrix res = A, tmp = A; k--;
    while (k) {
        if (k & 1) res = mul(res, tmp);
        tmp = mul(tmp, tmp);
        k >>= 1;
    }
    return res;
}

void solve() {
    ms(f, 0);
    scanf("%d%d", &n, &t);
    FOR(i, 0, n) scanf("%d", a + i);
    FOR(i, 0, n) FOR(j, 0, n) {
        if (a[i] > a[j]) f[i][j] = -INF;
        else {
            f[i][j] = 1;
            FOR(k, 0, j) if (a[k] <= a[j]) f[i][j] = max(f[i][j], f[i][k] + 1);
        }
    }
    matrix res; FOR(i, 0, n) FOR(j, 0, n) res.x[i][j] = f[i][j];
    res = ex(res, t);
    int ans = 0;
    FOR(i, 0, n) FOR(j, 0, n) ans = max(ans, res.x[i][j]);
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