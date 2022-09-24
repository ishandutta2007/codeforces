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
#include <functional>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
#define mt make_tuple
const double PI = acos(-1);
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 30;
template<class A, class B>
ll sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;
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
map <int , int> f[N];
void add(int v , int l , int r)
{
    for(int i ; l < N ; l += l & -l)
    {
        f[v][l] = max(f[v][l] , r);
    }
    return;
}
int get(int v , int x)
{
    int mx = 0;
    for(int i ; x ; x -= x & -x)
    {
        mx = max(mx , f[v][x]);
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        u--;
        v--;
        int x = get(u , w++ );
        add(v , w , x + 1);
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ans = max(ans , get(i , N - 1));
    }
    cout << ans;
    return 0;
}