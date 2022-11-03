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
const int MOD2 = 1e9 + 11;
const int MAXN = 6e5 + 7;

int n, m;
bool ans = false;
char a[50][50];
unsigned int color[50][50];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool ok(int i, int j)
{
    re(i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int i, int j, int k1, int k2)
{
    //cout << i + 1 << ' ' << j + 1<<LN;
    color[i][j] = 1;
    forn(q, 4)
    {
        int i1 = i + dx[q];
        int j1 = j + dy[q];
        if (ok(i1, j1) && a[i1][j1] == a[i][j])
        if (!(k1 == i1 && k2 == j1))
        {
            if (color[i1][j1] == 1)
            {
                ans = true;
                return;
            }
            else
            if (color[i1][j1] == 0)
                dfs(i1, j1, i, j);
        }
    }
    color[i][j] = 2;
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
    forn(i, n)
        forn(j, m)
            cin >> a[i][j];
    forn(i, n)
        forn(j, m)
            if (!color[i][j])
                dfs(i, j, -1, -1);
    ans ? cout << "Yes" : cout << "No";
}
//190660JM