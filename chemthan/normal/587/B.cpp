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
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 1000010;
ll n, l, k;
int a[maxn];
int r[maxn];
vi v;
ll sum[maxn];

ull mod_mul(ull a, ull b, ull p) {
	if (b == 1) return a % p;
	ull x = mod_mul(a, b >> 1, p);
	if ((b & 1) == 0) return (x << 1) % p;
	else return (((x << 1) % p) + a) % p;
}

void solve() {
    scanf("%I64d%I64d%I64d", &n, &l, &k);
    FOR(i, 0, n) {scanf("%d", a + i); r[i] = i;}
    int m = l % n; FOR(i, 0, m) v.push_back(a[i]);
    sort(a, a + n); sort(v.begin(), v.end());
    FORd(i, n - 1, 0) {
        int cur = i;
        while (cur < n - 1 && a[cur] == a[cur + 1]) cur = r[cur + 1];
        r[i] = cur;
    }
    ll f[n + 10][k + 10]; ms(f, 0);
    FOR(i, 0, n) sum[i] = i + 1;
    FOR(i, 0, n) f[i][1] = 1;
    FOR(j, 1, k) {
        FOR(i, 0, n) f[i][j + 1] = sum[r[i]];
        FOR(i, 0, n) {
            if (!i) sum[i] = f[i][j + 1];
            else sum[i] = (sum[i - 1] + f[i][j + 1]) % mod;
        }
    }
    ll ans = sz(v);
    FOR(j, 1, min(l / n, k) + 1) FOR(i, 0, n) {
        ans = (ans + mod_mul(f[i][j], (l / n - j + 1), mod)) % mod;
        if (j < k) {
            int d = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            ans = (ans + (sz(v) - d) * f[i][j]) % mod;
        }
    }
    cout<<ans;
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