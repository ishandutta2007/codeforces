#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//

#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)

//
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const bool is_testing = false;
const int p = 31;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 8;

int n, x0, y0, ans = 0;
bool was[1007];
vec < pair<db, db> > a;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> x0 >> y0;
    a.resize(n);
    forn(i, n)
        cin >> a[i].XX >> a[i].YY;
    forn(i, n)
        if (!was[i])
        {
            ans++;
            was[i] = true;
            forn(j, n)
                if (!was[j])
                {
                    int x1, x2, x3, y1, y2, y3;
                    x1 = x0;
                    y1 = y0;
                    x2 = a[i].XX;
                    y2 = a[i].YY;
                    x3 = a[j].XX;
                    y3 = a[j].YY;
                    if ( ( x2 - x1 ) * ( y3 - y1 ) == (x3 - x1) * (y2 - y1) )
                            was[j] = true;
                }
        }
    cout << ans;
}
//190660JM