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

const int maxn = 100010;
int n;
int a[maxn];
vi g[maxn];
vi res[maxn];

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n) scanf("%d", a + i);
    vi sq;
    FOR(i, 0, n) {
        int k = lower_bound(sq.begin(), sq.end(), a[i]) - sq.begin();
        if (k == sz(sq)) sq.push_back(a[i]); else sq[k] = a[i];
        g[k].push_back(i);
    }
    res[sz(sq) - 1] = g[sz(sq) - 1];
    FORd(i, sz(sq) - 1, 0) {
        int cur = sz(res[i + 1]) - 1, dmax = 0;
        FORd(j, sz(g[i]), 0) {
            int k = g[i][j];
            while (cur >= 0 && res[i + 1][cur] > k) {
                dmax = max(dmax, a[res[i + 1][cur]]);
                cur--;
            }
            if (a[k] < dmax) res[i].push_back(k);
        }
        reverse(res[i].begin(), res[i].end());
    }
    int ans[maxn]; FOR(i, 0, n) ans[i] = 1;
    FOR(i, 0, sz(sq)) {
        if (sz(res[i]) == 1) ans[res[i][0]] = 3;
        else {
            FOR(j, 0, sz(res[i])) ans[res[i][j]] = 2;
        }
    }
    FOR(i, 0, n) printf("%d", ans[i]);
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