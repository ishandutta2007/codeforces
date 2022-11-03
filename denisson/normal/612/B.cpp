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
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

int n;
ll ans = 0;
vec < pair <int, int> > a;

bool comp(pair <int, int> a, pair <int, int> b)
{
    if (a.XX < b.XX)
        re true;
    if (a.XX > b.XX)
        re false;
    re false;
}

int main()
{
    //freopen("output.in", "r", stdin); //freopen("speeding.out", "w", stdout);
    //freopen("approximate.in", "r", stdin); freopen("approximate.out", "w", stdout);
    cin >> n;
    forn(i, n)
    {
        int z;
        cin >> z;
        a.pb(mp(z, i));
    }
    sort(all(a), comp);
    forn(i, a.size() - 1)
        ans += abs(a[i].YY - a[i + 1].YY);
    cout << ans;
}