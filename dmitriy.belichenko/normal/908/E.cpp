#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 3000;
const int MOD = 1e9 + 7;
ll sum(ll a , ll b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

ll mult( ll a , ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

vector<int> g[N];
int n , m;
ll stt[N][N];
string a[N];
bitset<2000> used;
vector<int> topsort;
void dfs(int u)
{
    used[u] = 1;
   // cout << u << " ";
    for(auto v : g[u])
    {
        if(!used[v]) dfs(v);
    }
    topsort.pb(u);
}
long long ans = 1;
void precalc()
{
    stt[0][0] = ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            stt[i + 1][j] = sum(stt[i + 1][j], mult(stt[i][j], j));
            stt[i + 1][j + 1 ] = sum(stt[i + 1][j + 1], stt[i][j]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    swap(n , m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    precalc();
    for(int i = 0; i < m; i++)
    {
        for(int j = i + 1; j < m; j++)
        {
            bool flag = 0;
    //         cout << i << " " << j << "\n";
            for(int k = 0; k < n; k++ )
            {
                if(a[k][j] != a[k][i]) flag = 1;
               
            }
            if(!flag)
            {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }

     //  cout << stt[0][0] << " ";
    for (int u = 0; u < m; u++)
    {
        // cout << j << " ";
        dfs(u);
        int p = topsort.size();
        if(!p) continue;
        int res = 0;
        for (int i = 0; i < topsort.size() + 1; i++)
        {
            res =  1LL * sum(res, stt[topsort.size() ][i]) % MOD;
        }
        ans = mult(ans, res);
        topsort.clear();
    }
    cout << ans << "\n";
    return 0;
}