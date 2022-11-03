#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
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
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;

int n;
vec <int> dp;

int main()
{
    cin >> n;
    dp.resize(n);
    forn(i, n)
    {
        int z;
        cin >> z;
        z--;
        if (z > 0)
            dp[z] = dp[z - 1] + 1;
        else
            dp[0] = 1;
            //cout << z << LN;
    }
    int ans = 0;
    forn(i, dp.size())
        ans = max(ans, dp[i]);
        //cout << dp[i] << LN;
    cout << n - ans;
}