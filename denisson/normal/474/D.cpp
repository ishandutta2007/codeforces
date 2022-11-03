#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const bool is_testing = 0;
const ll MOD = 1e9 + 7;

int t, k;
ll dp[100007];
ll pref[100007];

void add(ll &a, ll &b)
{
    a = (a + b + MOD) % MOD;
}

int main()
{
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    if (is_testing)
    {
    }
    cin >> t >> k;
    dp[0] = 1;

    form(i, 1, 100000)
    {
        dp[i] = dp[i - 1];
        if (i - k >= 0)
            add(dp[i], dp[i - k]);
    }
    form(i, 1, 100000)
        pref[i] = pref[i - 1], add(pref[i], dp[i]);
    forn(asdfasdf, t)
    {
        int l, r;
        cin >> l >> r;
        ll ans = pref[r] - pref[l - 1];
        ans = (ans + MOD) % MOD;
        cout << ans << LN;
    }

}