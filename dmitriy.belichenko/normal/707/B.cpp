
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
const int N = 2e5 + 5;
int MOD = 1e9 + 7;
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
bool isprime(int n)
{
    for(int i = 2; i * i <= n; i++ )
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
set<int> a;
map<pair<int, int> , int> mn;
int main()
{
    ios_base::sync_with_stdio(0);
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int u , v , c;
        cin >> u >> v >> c;
        if(mn.count(mp(u , v))) mn[mp(u , v)] = min(c ,  mn[mp(u , v)]);
        else
             mn[mp(u , v)] = c;
            
    }
    int ans = 1e9 + 3;
    for(int i = 0; i < k; i++)
    {
        int p;
        cin >> p;
        a.insert(p);
    }
    for(auto i : mn)
    {
        if(a.count(i.first.first) && !a.count(i.first.second))
        {
            ans = min(ans , i.second);
        }
        if(!a.count(i.first.first) && a.count(i.first.second))
        {
            ans = min(ans , i.second);
        }
    }
    if(ans < 1e9 + 3)
    {
        cout << ans << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
    return 0;
}