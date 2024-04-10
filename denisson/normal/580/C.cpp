#include <bits/stdc++.h>
#include <Windows.h>
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
const int MAXN = 1e5 + 7;

int n, kk, ans = 0;
bool cat[MAXN];
bool was[MAXN];
vec < vec <int> > g;

void dfs(int k, int cat_k)
{
    was[k] = true;
    if (cat[k])
        cat_k++;
    else
        cat_k = 0;
    bool ff = true;
    forn(i, g[k].size())
        if (!was[g[k][i]])
        {
            ff = false;
            bool f = true;
            if (cat[g[k][i]])
            {
                if (cat_k + 1 > kk)
                    f = false;
            }
            if (f)
                dfs(g[k][i], cat_k);
        }
    if (cat_k <= kk && ff)
        ans++;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> kk;
    g.rs(n);
    forn(i, n)
        cin >> cat[i];
    forn(i, n - 1)
    {
        int z1; int z2;
        cin >> z1 >> z2;
        z1--; z2--;
        g[z1].pb(z2);
        g[z2].pb(z1);
    }
    dfs(0, 0);
    cout << ans;
}
//190660JM