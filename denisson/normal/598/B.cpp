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

str s;
int n;

int main()
{
    //freopen("input.in", "r", stdin); //freopen("friends.out", "w", stdout);
    cin >> s >> n;
    forn(asdfasdf, n)
    {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        int q = 0;
        if (l < r)
            q = d % (r - l + 1);
        str s1 = "";
        for (int i = 0; i < l; i++)
            s1 += s[i];
        for (int i = r - q + 1; i <= r; i++)
            s1 += s[i];
        for (int i = l; i <= r - q; i++)
            s1 += s[i];
        for (int i = r + 1; i < s.size(); i++)
            s1 += s[i];
        s = s1;
    }
    cout << s;
}