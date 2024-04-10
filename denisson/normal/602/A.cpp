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
const int INF = (int)2e6 + 7;
const ll LINF = (ll)9e18 + 7;

int n, m, q1, q2;
vec <int> a, b;

ll p(int a, int k)
{
    if (k == 0)
        re 1;
    ll d = 1;
    forn(i, k)
        d *= a;
    re d;
}

ll pere(vec <int> a, int q)
{
    ll an = 0;
    for (int i = a.size() - 1; i >= 0; i--)
        an += a[i] *p(q, a.size() - i - 1);
    re an;
}

int main()
{
    cin >> n >> q1;
    forn(i, n)
    {
        int z;
        cin >> z;
        a.pb(z);
    }
    cin >> m >> q2;
    forn(i, m)
    {
        int z;
        cin >> z;
        b.pb(z);
    }
    ll d1 = pere(a, q1);
    ll d2 = pere(b, q2);
    if (d1 == d2)
        cout << "=";
    if (d1 > d2)
        cout << ">";
    if (d1 < d2)
        cout << "<";
}