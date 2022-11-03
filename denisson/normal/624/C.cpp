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
const int MAXN = 1e5 + 8;

int n, m, k;
int color[507];
int sizeg[507];
bool was[507];
vec < vec<int> > g;

void dfs(int q)
{
    was[q] = true;
    color[q] = k;
    sizeg[k]++;
    forn(i, g[q].size())
        if(!was[g[q][i]] && color[g[q][i]] != -1)
            dfs(g[q][i]);
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
    cin >> n >> m;
    g.resize(n);
    forn(i, m)
    {
        int z1, z2;
        cin >> z1 >> z2;
        z1--; z2--;
        g[z1].pb(z2);
        g[z2].pb(z1);
    }
    forn(i, n)
        if (g[i].size() == n - 1)
            color[i] = -1, sizeg[0]++;
    k = 0;
    forn(i, n)
        if (color[i] != -1 && !was[i])
        {
            k++;
            dfs(i);
        }
    if (k > 2)
        cout << "No", exit(0);
    if (k == 0)
    {
        if (m != n * (n-1) / 2)
            cout << "No", exit(0);
        cout << "Yes" << LN;
        forn(i, n)
            cout << 'b';
    }
    if (k == 1)
    {
        int q1 = sizeg[0];
        int q2 = sizeg[1];
        if (m != q1 * (n - 1) - q1 + 1 + q2 * (q2 - 1) / 2)
            cout << "No", exit(0);
        cout << "Yes" << LN;
        forn(i, n)
            if (color[i] == -1)
                cout << 'b';
            else
                cout << 'a';
    }
    if (k == 2)
    {
        int q1 = sizeg[0];
        int q2 = sizeg[1];
        int q3 = sizeg[2];
        int t = 0;
        for (int i = 0; i < q1; i++)
            t += n - 1 - i;
        if (m != t + q2 * (q2 - 1) / 2 + q3 * (q3 - 1) / 2)
            cout << "No", exit(0);
        cout << "Yes" << LN;
        forn(i, n)
            if (color[i] == -1)
                cout << 'b';
            else
                if (color[i] == 1)
                cout << 'a';
            else
                cout << 'c';
    }
}
//190660JM