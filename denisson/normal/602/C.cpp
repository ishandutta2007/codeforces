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
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
template<class T> bool in(T a, T x1, T x2) {return (a >= x1 && a <= x2);}

int n, m, k;
int dp[507];
bool a[3][507][507];
bool was[507];

void bfs(int k1)
{
    forn(i, n)
        dp[i] = INF;
    dp[k1] = 0;
    vec <int> que;
    int uk = 0;
    que.pb(k1);
    while (uk < que.sz())
    {
        int t = que[uk];
        uk++;
        was[t] = true;
        forn(i, n)
            if (a[k][t][i] && !was[i])
            {
                was[i] = true;
                dp[i] = dp[t] + 1;
                que.pb(i);
            }

    }
}

int main()
{
    cin >> n >> m;
    forn(i, m)
    {
       int z1, z2;
       cin >> z1 >> z2;
       z1--; z2--;
       a[1][z1][z2] = true;
       a[1][z2][z1] = true;
    }
    forn(i, n)
        forn(j, n)
            a[2][i][j] = !a[1][i][j];
    if (a[1][0][n-1])
        k = 2;
    else
        k = 1;
    bfs(0);
    if (dp[n-1] == INF)
        cout << -1;
    else
        cout << dp[n-1];
}