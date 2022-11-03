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

const bool is_testing = 0;
const int p = 31;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 11;
const int MAXN = 2e5 + 7;

db rast;
int n;
vec<db> a;

bool check(db d)
{
    vec< pair<db, int> > q;
    forn(i, n)
    {
        q.pb(mp(max((db)0, a[i] - d), -1));
        q.pb(mp(min(rast, a[i] + d), 1));
    }
    sort(all(q));
    forn(i, q.size())
        if (q[i].YY == 1)
            q[i].YY = -1;
        else
            q[i].YY = 1;
    if (q[0].XX != 0)
        re 0;
    int k = 0;
    forn(i, q.size())
    {
        k += q[i].YY;
        if (k == 0)
            if (q[i].XX != rast)
                re 0;
    }
    re 1;

}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    srand(14123);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> rast;
    a.resize(n);
    forn(i, n)
        cin >> a[i];
    sort(all(a));
    db l = 0, r = 1e9 + 7;
    forn(asdfasdf, 120)
    {
        db m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(12) << l;

}
//190660JM