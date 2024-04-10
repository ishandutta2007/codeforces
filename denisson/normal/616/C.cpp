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

const int MAXN = 100007;

int n, m, k = 1, kk = 1;
char a[1007][1007];
int t[1000007];
int was[1007][1007];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};


void bfs(int x,int y)
{
    kk++;
    was[x][y] = k;
    forn(i, 4)
    if (x + dx[i] > -1 && x + dx[i] < n && y + dy[i] > -1 && y + dy[i] < m && a[x + dx[i]][y + dy[i]] != '*' && was[x + dx[i]][y + dy[i]] == 0)
    {
        bfs(x + dx[i], y + dy[i]);
    }
}

int main()
{
  /*  ios_base::sync_with_stdio(0);
    cin.tie(NULL);  */
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    cin >> n >> m;
    forn(i, n)
        scanf("%s", a[i]);
    forn(i, n)
        forn(j, m)
            if (was[i][j] == 0 && a[i][j] != '*')
            {
                kk = 0;
                bfs(i, j);
                t[k] = kk;
                k++;
            }
    forn(i, n)
    {
        forn(j, m)
            if (a[i][j] == '.')
            {
                printf("%c", a[i][j]);
            }
            else
            {
                set<int> ss;
                int u = 1;
                if (i - 1 >= 0)
                {
                    u += t[was[i-1][j]];
                    ss.in(was[i-1][j]);
                }
                if (i + 1 < n)
                {
                    int y = ss.size();
                    ss.in(was[i+1][j]);
                    if (ss.size() != y)
                        u += t[was[i+1][j]];
                }
                if (j - 1 >= 0)
                {
                    int y = ss.size();
                    ss.in(was[i][j-1]);
                    if (ss.size() != y)
                        u += t[was[i][j-1]];
                }
                if (j + 1 < m)
                {

                    int y = ss.size();
                    ss.in(was[i][j+1]);
                    if (ss.size() != y)
                        u += t[was[i][j+1]];
                }
                printf("%d", u % 10);
            }
        printf("\n");
    }
}