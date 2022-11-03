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
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 1;
const ll LINF = (ll)9e18 + 7;

int n, m, a[207][207];


int main()
{
    //freopen("friends.in", "r", stdin); freopen("friends.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2*m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2*m; j += 2)
        {
            if (a[i][j] == 1 || a[i][j + 1] == 1)
                ans++;
        }
    cout << ans;
}