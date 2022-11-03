#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
#define forn(i, n) for (ll i = 0; i < (ll)n; i++)
#define fornm(i, n, m) for (ll i = n; i <= (ll)m; i++)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db double
#define re return
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;

int t;
vector <ll> a;

int main()
{
    //freopen("input.in", "r", stdin); //freopen("friends.out", "w", stdout);
    a.pb(1);
    for (int i = 1; i <= 30; i++)
        a.pb(pow(2, i));
    cin >> t;
    forn(sdfsdf, t)
    {
        ll n;
        cin >> n;
        ll ans = (1 + n)*(n / 2);
        if (n % 2 != 0)
            ans += n / 2 + 1;
        forn(i, a.size())
            if (a[i] <= n)
                ans -= a[i] * 2;
            else
                break;
        cout << ans << LN;
    }
}