#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
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
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

int n, dp[1000007], a[1000007], ans = 0;

int main()
{
    //freopen("output.in", "r", stdin); //freopen("speeding.out", "w", stdout);
    //freopen("approximate.in", "r", stdin); freopen("approximate.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    read(n);
    forn(i, n)
    {
        int z1, z2;
        read2(z1, z2);
        a[z1] = z2;
    }
    dp[0] = 0;
    if (a[0] != 0)
        dp[0] = 1;
    ans = max(ans, dp[0]);
    for (int i = 1; i <= 1000000; i++)
    {
        if (a[i] != 0)
        {
            if (i - a[i] - 1 < 0)
                dp[i] = 1;
            else
                dp[i] = dp[i - a[i] - 1] + 1;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
        ans = max(ans, dp[i]);
    }
    cout << n - ans;
}