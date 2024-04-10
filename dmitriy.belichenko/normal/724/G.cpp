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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 62;
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
bool used[N] , nl[N];
vector<ll> xr;
ll dp1[MAXN + 100] , dp2[MAXN + 100] , val[N];
vector<pair<ll, ll>> g[N];
bitset<MAXN> t;
ll ans = 0;
ll st[100];
void relax()
{
    for(int j = 0; j < MAXN; j++)
    {
        dp1[j] = 0;
        dp2[j] = 0;
        t[j] = 1;
    }
    xr.clear();
  //  cout << xr.size() << "\n";
}
ll dfs(ll u)
{
    used[u] = 1;
    ll p = 1;
    for(ll i = 0; i < MAXN;  i++)
    {
        bool t = (val[u] & (1LL <<  i));
        if(t) dp1[i]++;
        else dp2[i]++;

    }
//    cout << u << ": " << "\n";
//    for(int i = 0; i < MAXN; i++)
//    {
//        cout << dp1[i] << " ";
//    }
//    cout << "\n";
//    for(int i = 0; i < MAXN; i++)
//    {
//        cout << dp2[i] << " ";
//    }
    for(auto v : g[u])
    {
        ll cur = v.snd;
        if(used[v.first])
        {
            xr.pb(val[v.first] ^ val[u] ^ cur);
            //cout << cur ^ val[u] ^ val[v] << " " << val[u] << " " << val[v.fst] << " " << "\n";
        }
        if(!used[v.fst])
        {
            val[v.first] = (val[u] ^ cur);
            p += dfs(v.fst);
        }

    }
    return p;
}
void calc(int sz , int p)
{
    for (ll i = 0; i < MAXN; i++)
    {
        int plus;
        if (t[i])
        {
            plus = mult(st[sz], dp1[i] );
            plus = mult(plus, dp2[i] );
        }
        else
        {
            
            plus = mult(st[sz - 1], (((ll) p * (p - 1) / 2) % MOD));
        }
        plus = mult(plus, st[i]);
        sum(ans, plus);
        //ans += plus;
        if (ans >= MOD)
        {
            ans -= MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n , m;
    cin >> n >> m;
    st[0] = 1;
    for(int i = 1; i < 62; i++)
    {
        st[i] = mult(st[i - 1], 2);
    }
    for(int i = 0; i < m; i++)
    {
        ll u , v , t;
        cin >> u >> v >> t;
        u--;
        v--;
        g[u].pb(mp(v, t));
        g[v].pb(mp(u, t));
    }
    for(int u = 0; u < n; u++)
    {
        if(used[u]) continue;
        relax();
        val[u] = 0 ;
        ll p = dfs(u);
        ll k = xr.size();
        ll sz = 0;
       //  cout << p << " " << k << "\n";
   
        for (ll i = 0; i < xr.size(); i++)
        {
            if (xr[i])
            {
                sz++;
                ll cnt = 0;
                while ((xr[i] & (1ll <<  cnt))== 0) cnt++;
                for (int j = cnt; j < MAXN; j++)
                {
                    ll mask = xr[i] & (1ll << j);
                    if (xr[i] & mask) t[j] = 0;
                }
                for (ll j = i + 1; j < xr.size(); j++)
                {
                    ll mask = (1ll << cnt);
                    if (xr[j] & mask) xr[j] ^= xr[i];
                }
            }
        }
        
        calc(sz, p);
    //    cout << p << " " << sz << " " << k << "\n";
    //    for(int j = 0; j < k; j++) cout << xr[j] << " ";
    }
//    cout << "\n";
    cout << ans << "\n";
    return 0;
}