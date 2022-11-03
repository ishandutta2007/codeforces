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

int n, k;
vec < pair <int, int> > a, anso;

bool comp(pair <int, int> a, pair <int, int> b)
{
    if (a.XX < b.XX)
        re true;
    if (a.XX > b.XX)
        re false;
    if (a.XX == b.XX && a.YY == 1 && b.YY == -1)
        re true;
    if (a.XX == b.XX && a.YY == -1 && b.YY == 1)
        re false;
    if (a.XX == b.XX && a.YY == b.YY)
        re false;
}

int main()
{
    //freopen("output.in", "r", stdin); //freopen("speeding.out", "w", stdout);
    //freopen("approximate.in", "r", stdin); freopen("approximate.out", "w", stdout);
    cin >> n >> k;
    forn(i, n)
    {
        int z1, z2;
        scanf("%d %d", &z1, &z2);
        //cin >> z1 >> z2;
        a.pb(mp(z1, 1));
        a.pb(mp(z2, -1));
    }
    sort(all(a), comp);
    //forn(i, a.size())
    //    cout << a[i].XX << ' ' << a[i].YY << LN;
    int k1 = 0, ans = -INF;
    forn(i, a.size())
    {
        k1 += a[i].YY;
        if (k1 >= k)
        {
            if (ans == -INF)
                ans = a[i].XX;
        }
        else
        {
            if (ans != -INF)
            {
                //cout << ans << ' ' << a[i].XX << LN;
                anso.pb(mp(ans, a[i].XX));
                ans = -INF;
            }
        }
    }
    cout << anso.size() << LN;
    forn(i, anso.size())
        printf("%d %d\n", anso[i].XX, anso[i].YY);
        //cout << anso[i].XX << ' ' << anso[i].YY << LN;
}