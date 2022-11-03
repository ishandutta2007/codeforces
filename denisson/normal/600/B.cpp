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

int n, m;
vec <int> a, b;

int main()
{
    cin >> n >> m;
    forn(i, n)
    {
        int z;
        cin >> z;
        a.pb(z);
    }
    forn(i, m)
    {
        int z;
        cin >> z;
        b.pb(z);
    }
    sort(all(a));
    forn(i, m)
    {
        vector<int>::iterator q = upper_bound(a.begin(), a.end(), b[i]);
        cout << q - a.begin() << ' ';
    }
}