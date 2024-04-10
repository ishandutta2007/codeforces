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

const int maxn = 200010;
int n;
int cnt[maxn];
int pro[maxn];

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n) {
        int a; scanf("%d", &a);
        cnt[a]++;
    }
    int flag = 1, k = 1, d = 1, l = 1;
    vi v;
    FOR(i, 0, maxn) if (cnt[i]) {
        v.pb(cnt[i]);
        if ((cnt[i] & 1) && flag) {
            flag = 0;
            l = (ll) l * ((cnt[i] + 1) >> 1) % (MOD - 1);
        }
        else l = (ll) l * (cnt[i] + 1) % (MOD - 1);
        k = (ll) k * fpow(i, cnt[i]) % MOD;
        d = (ll) d * fpow(i, cnt[i] >> 1) % MOD;
    }
    if (!flag) {
        printf("%d", fpow(k, l));
    }
    else {
        int t = 1;
        FORd(i, sz(v), 0) {
            t = (ll) t * (v[i] + 1) % (MOD - 1);
            pro[i] = t;
        }
        t = 0;
        FOR(i, 0, sz(v) - 1) {
            t = (t + (ll) (v[i] / 2) * pro[i + 1]) % (MOD - 1);
        }
        t = (t + v.back() / 2) % (MOD - 1);
        printf("%d", (ll) fpow(k, t) * d % MOD);
    }
}

int main() {
//  ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}