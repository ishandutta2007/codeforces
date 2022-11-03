#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
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
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const bool is_testing = 0;

int n, l, x, y;
int a[100007];
vec<int> ans;
map <int, bool> was;

bool ok (int x)
{
    re (x > 0 && x < l);
}

int main()
{
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    if (is_testing)
    {
    }
    cin >> n >> l >> x >> y;
    forn(i, n)
        cin >> a[i];
    forn(i, n)
        was[a[i]] = 1;
    bool f1 = 0, f2 = 0;
    forn(i, n)
    {
        if (was[a[i] + x])
            f1 = 1;
        if (was[a[i] + y])
            f2 = 1;
    }
    if (!f1)
        ans.pb(x);
    if (!f2)
        ans.pb(y);
    if (ans.size() == 2)
    {
        forn(i, n)
        {
            if (was[a[i] + x + y])
            {
                ans.clear();
                ans.pb(a[i] + x);
                break;
            }
            if (was[a[i] + x - y] && ok(a[i] + x))
            {
                ans.clear();
                ans.pb(a[i] + x);
                break;
            }
            if (was[a[i] + y - x] && ok(a[i] + y))
            {
                ans.clear();
                ans.pb(a[i] + y);
                break;
            }
            
            if (was[a[i] + x - y] && ok(a[i] - y))
            {
                ans.clear();
                ans.pb(a[i] - y);
                break;
            }
            if (was[a[i] + y - x] && ok(a[i] - x))
            {
                ans.clear();
                ans.pb(a[i] - x);
                break;
            }
        }
    }
    cout << ans.size() << LN;
    forn(i, ans.size())
        cout << ans[i] << ' ';
}