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

int n, m, ans = 0, u1, u2;
bool f = false;
bool was[107];
vec < vec < pair <int, int> > > g;

void dfs(int k, int color)
{
    was[k] = true;
    if (k == u2)
        f = true;
    forn(i, g[k].size())
        if (g[k][i].YY == color && !was[g[k][i].XX])
            dfs(g[k][i].XX, color);
}

int main()
{
 /*   ios_base::sync_with_stdio(0);
    cin.tie(NULL);    */
    //freopen("output.in", "r", stdin); //freopen("speeding.out", "w", stdout);
    //freopen("suck.in", "r", stdin); //freopen("suck.out", "w", stdout);
    cin >> n >> m;
    g.resize(n);
    forn(i, m)
    {
        int z1, z2, z3;
        cin >> z1 >> z2 >> z3;
        z1--; z2--;
        g[z1].pb(mp(z2, z3));
        g[z2].pb(mp(z1, z3));
    }
    int q;
    cin >> q;
    forn(sdfsfdasdf, q)
    {
        cin >> u1 >> u2;
        u1--; u2--;
        ans = 0;
        for (int color = 1; color <= m; color++)
        {
        forn(i, 105)
            was[i] = false;
        f = false;
            dfs(u1, color);
            if (f)
                ans++;
        }
        cout << ans << LN;
    }
}