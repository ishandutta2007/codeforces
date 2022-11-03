#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
#define forn(i, n) for (ll i = 0; i < (ll)n; i++)
#define fornm(i, n, m) for (ll i = n; i <= (ll)m; i++)
#define mp make_pair
#define pb push_back
#define XX first
#define YY second
#define TASK "ladder"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 1;
const ll LINF = (ll)9e18 + 7;

int n, ans = 0;

int main()
{
    // freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
    cin >> n;
    bool f = true;
    int q1 = 0;
    forn(i, n)
    {
        int z;
        cin >> z;
        if (z == 1)
        {
            if (q1 >= 2 && !f)
                ans += q1;
            q1 = 0;
            f = false;
        }
        else
        {
            q1++;
        }
        if (f)
            ans++;
    }
    if (!f)
        ans += q1;
    cout << n - ans;
}