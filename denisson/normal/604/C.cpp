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
#define vec vector
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

int n, k = 1, ans = 0, k1 = 0;
vec <int> a;
str s;

int main()
{
    cin >> n;
    cin >> s;
    if (n <= 3)
    {
        cout << n;
        exit(0);
    }
    s += ' ';
    forn(i, s.size() - 1)
        if (s[i] == s[i+1])
            k++;
        else
        {
            //cout << i + 1 << ' ' << k << LN;
            a.pb(k);
            k = 1;
        }
    if(a[0] > 1)
        ans = 1;
    forn(i, a.size())
        if (a[i] > 2)
            ans = 2;
    bool f1 = false, f2 = false;
    forn(i, a.size())
    if (a[i] == 1)
    {
        if (i - 1 >= 0)
            if (a[i-1] > 1)
                f1 = true;
        if (i + 1 <= a.size() - 1)
            if (a[i+1] > 1)
                f2 = true;
    }
    else
    {
        if (i + 1 <= a.size() - 1)
            if (a[i+1] > 1)
                ans = 2;
        int k = 0;
        if (f1)
            k++;
        if (f2)
            k++;
        ans = max(ans, k);
    }
    cout << a.size() + ans;
}