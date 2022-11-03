#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (ll i = n; i < (ll)m; i++)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define re return
#define tr true
#define fl false
#define XX first
#define YY second
#define db long double
#define in insert
#define an(f, s1, s2) if (f) cout << s1 << LN; else cout << s2 << LN;
#define all(a) a.begin(), a.end()
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 1;
const ll LINF = (ll)9e18 + 7;

int n;
vector < pair <int, int> > a;

int rast(int x1, int y1, int x2, int y2)
{
    re abs(x1-x2) * abs(y1-y2);
}

int main()
{
    //freopen("input.in", "r", stdin); //freopen("friends.out", "w", stdout);
    cin >> n;
    forn(i, n)
    {
        int x, y;
        cin >> x >> y;
        a.pb(mp(x, y));
    }
    sort(a.begin(), a.end());
    if (n == 1)
        cout << -1;
    else
    if (n == 2)
    {
        if (a[0].XX == a[1].XX || a[0].YY == a[1].YY)
            cout << -1;
        else
            cout << rast(a[0].XX, a[0].YY, a[1].XX, a[1].YY);
    }
    else
    if (n == 3)
        cout << max(rast(a[0].XX, a[0].YY, a[1].XX, a[1].YY), max(rast(a[0].XX, a[0].YY, a[2].XX, a[2].YY), rast(a[2].XX, a[2].YY, a[1].XX, a[1].YY)));
    else
        cout << rast(a[0].XX, a[0].YY, a[3].XX, a[3].YY);
}