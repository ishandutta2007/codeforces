#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <iostream>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
#define mt make_tuple
const double PI = acos(-1);
const int N = 200;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 30;
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
int to_i(char c)
{
    return c - 'a';
}
ll mult(ll a, ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
ll poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
bool a[N][N][MAXN];
char g[N][N];
 int n , m;
bool dfs(int u , int v , char c)
{
    if(a[u][v][c]) return 1;
    for(int i = 0; i < n; i++)
    {
        if(g[u][i] < c) continue;
        if(!dfs(v, i, g[u][i])) return a[u][v][c] = true;
    }
    return a[u][v][c] = false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
   
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        char t;
        cin >> t;
        g[u][v] = t;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dfs(i , j , 'a')) cout << 'A';
            else cout << 'B';
        }
        cout << "\n";
    }
}