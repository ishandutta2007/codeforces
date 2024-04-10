#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
#define forn(i, n) for (ll i = 0; i < (ll)n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db double
#define re return
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;

int n, k, s[100007];

int main()
{
    cin >> n >> k;
    forn(i, n)
        cin >> s[i];
    if (n == k * 2)
    {
        int ans  = -INF;
        forn(i, n / 2)
            ans = max(ans, s[i] + s[n - 1 - i]);
        cout << ans;
    }
    else
    if (n <= k)
    {
        int ans  = -INF;
        forn(i, n)
            ans = max(ans, s[i]);
        cout << ans;
    }
    else
    {
        int q1 = k - (n % k);
        int ans = -INF;
        for (int i = n - 1; i > n - 1 - q1; i--)
            ans = max(ans, s[i]);
        forn(i, (n - q1) / 2)
            ans = max(ans, s[i] + s[n - 1- q1 - i]);
        cout << ans;
    }

}