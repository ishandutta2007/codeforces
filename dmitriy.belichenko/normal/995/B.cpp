#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <valarray>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ld long double
#define mt make_tuple
#define fst firs
const double PI = acos(-1);
const int N = 5e6 + 17;
ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int MAXN = 26;
const int maxlog = 18;
ld eps = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
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
ll mult(ll a, ll b)
{
    ll res = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (res < 0)
    {
        res += MOD;
    }
    if (res >= MOD)
    {
        res -= MOD;
    }
    return res;
}
ll gcd (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = mult(a, res);
        a = mult(a, a);
        b >>= 1;
    }
    return res % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}
ll a[N];
bool used[105];
int fs(int u)
{
    return add(u , 1);
}
int sn(int u)
{
    return add(u , MOD - 1);
}
int v;
vector<int> ans;
bool flag = 0;
void dfs(int cur ,int last)
{
    //cout << cur << " " << v << " " <<  last << "\n";
    if(ans.size() > 200) return;
    if(cur == v)
    {
        flag = 1;
        return;
    }
    ans.pb(last);
   // cout << cur << "\n";
    if(last == 3)
    {
        cur = inv(cur);
        if(!flag) dfs(cur , 1);
        if(!flag) dfs(cur , 2);
    }
    if(last == 2)
    {
        cur = sn(cur);
        if(!flag) dfs(cur , 2);
        if(!flag) dfs(cur, 3);
    }
    if(last == 1)
    {
        cur = fs(cur);
        if(!flag) dfs(cur , 1);
        if(!flag) dfs(cur , 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int u  , p;
   // cin >> u >> v >> p;
    v = 1;
//    MOD = p;
//    int cur = u;
//    int last = -1;
//    dfs(u , 1);
//    if(ans.size() <= 200)
//    {
//        cout << ans.size() << "\n";
//        for(int i = 0; i < ans.size(); i++)
//        {
//            cout << ans[i] << " ";
//        }
//        return 0;
//    }
//    ans.clear();
//    dfs(u , 2);
//    if(ans.size() <= 200)
//    {
//        cout << ans.size() << "\n";
//        for(int i = 0; i < ans.size(); i++)
//        {
//            cout << ans[i] << " ";
//        }
//        return 0;
//    }
//    ans.clear();
//    dfs(u , 3);
//    if(ans.size() <= 200)
//    {
//        cout << ans.size() << "\n";
//        for(int i = 0; i < ans.size(); i++)
//        {
//            cout << ans[i] << " ";
//        }
//        return 0;
//    }
//    ans.clear();
  //  cout << N - (1 << 18);
    dfs(1 , 1);
    dfs(1 , 2);
    dfs(1 , 3);
    ll ans = 0;
    int n;
    cin>>n;
    vector<int> v(2*n);
    for (int i=0; i<2*n; i++)
    {
        cin>>v[i];
    }
  
    for (int i=0; i<2*n;i++)
    {
        if (!used[v[i]])
        {
            used[v[i]] = true;
            int pos = i+1;
            for (int j=i+1; j<2*n; j++)
            {
                if (v[j] == v[i])
                {
                    pos = j;
                    break;
                }
            }
            while (pos!=i+1)
            {
                swap(v[pos-1],v[pos]);
                pos--;
                ans++;
            }
        }
    }
    cout<<ans;
    
    return 0;
}