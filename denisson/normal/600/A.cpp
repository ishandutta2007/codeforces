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
#define sz size
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e6 + 7;
const ll LINF = (ll)9e18 + 7;

vec <str> a, b;

bool pro(str s)
{
    //cout << s << LN;
    if (s.sz() == 0)
        re false;
    if (s[0] == '0' && s.sz() != 1)
        re false;
    forn(i, s.sz())
    {
        int q = s[i] - '0';
        if (!(q >=0 && q <= 9))
            re false;
    }
    re true;
}

int main()
{
    str s;
    getline(cin, s);
    s += ';';
    str s1 = "";
    forn(i, s.sz())
    {
        if (!(s[i] == ';' || s[i] == ','))
            s1 += s[i];
        else
        {
            if (pro(s1))
                a.pb(s1);
            else
                b.pb(s1);
            s1 = "";
        }
    }
    if (a.sz() == 0)
        cout << "-";
    else
    {
        char c = '"';
        cout << c;
        forn(i, a.sz())
        {
            cout << a[i];
            if (i != a.sz() - 1)
                cout << ",";
        }
        cout << c;
    }
    cout << LN;
    if (b.sz() == 0)
        cout << "-";
    else
    {
        char c = '"';
        cout << c;
        forn(i, b.sz())
        {
            cout << b[i];
            if (i != b.sz() - 1)
                cout << ",";
        }
        cout << c;
    }
}