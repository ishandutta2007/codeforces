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
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 200010;
int n;
int a[maxn];
ld sum[maxn];

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n) scanf("%d", a + i);
    ld ans = 1e18;
    ld l = -1e9, r = 1e9;
    FOR(_, 0, 100) {
        ld mid = (l + r) / 2;
        ld d1 = 0, d2 = 0, dmin = 1e18, dmax = -1e18;
        sum[0] = 0;
        FOR(i, 1, n + 1) {
            sum[i] = sum[i - 1] + a[i - 1] + mid;
            dmin = min(dmin, sum[i] - d2);
            dmax = max(dmax, sum[i] - d1);
            d1 = min(d1, sum[i]);
            d2 = max(d2, sum[i]);
        }
        if (dmax + dmin <= 0) l = mid; else r = mid;
        ans = min(ans, max(fabs(dmax), fabs(dmin)));
    }
    cout<<fixed<<setprecision(9)<<ans;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}