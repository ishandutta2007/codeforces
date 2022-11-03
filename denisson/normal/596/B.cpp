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
ll ans = 0, k = 0;

int main()
{
    //freopen("input.in", "r", stdin); //freopen("friends.out", "w", stdout);
    cin >> n;
    forn(i, n)
    {
        int z;
        cin >> z;
        ans += abs(z - k);
        k = z;
    }
    cout << ans;
}