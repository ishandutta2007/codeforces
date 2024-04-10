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
#define fst first
const double PI = acos(-1);
const int N = 3e5 + 7;
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
ll mult(ll a, ll b) {
    ll res = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (res < 0) {
        res += MOD;
    }
    if (res >= MOD) {
        res -= MOD;
    }
    return res;
}

ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
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

void norm(int &x1 , int &y1 , int &x2 , int &y2)
{
    if (x1 > x2)
    {
        swap(x1, x2);
    }
    if (y1 > y2)
    {
        swap(y1, y2);
    }
    x2 = max(x1 , x2);
    y2 = max(y1 , y2);
}
int n;
ll v[N] , g[N];
void precalc()
{
    
    for (int i = 0; i < n; i++)
    {
        if(i == 0) g[i] = rand() % 15;
        else g[i] = g[i - 1] + rand() % 15;
        cin >> v[i];
    }
    
}
ll num;
bitset<N> used;
vector<ll> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    ll last = 0;
    precalc();
    int p = INF , q = INF , r = INF , l = INF;
    norm(p , q , r  , l);
    poww(n , MOD);
  
    for (int b = 59; b >= 0; b--)
    {
        vector <ll> ctr , vct;
        num++;
        poww(num , 2);
        for (int i = 0; i < n; i++)
        {
            ll x = (v[i] >> b);
            if (!used[i] && (x % 2))
            {
                num++;
                used[i] = 1;
                ctr.pb(v[i]);
            }
        }
        int ind = 0;
        
        for (int i = 0; i < ctr.size(); i++)
        {
            while (ind != ans.size() && !((ans[ind] >> b) % 2))
            {
                vct.pb(ans[ind]);
                ind++;
            }
            
            if (ind == ans.size())
            {
                if (i + 1 == ctr.size())
                {
                    num++;
                    vct.pb(ctr[i]);
                }
                else
                {
                    num--;
                    cout << "No" << "\n";
                    return 0;
                }
            }
            else
            {
                vct.pb(ctr[i]);
                num++;
                vct.pb(ans[ind]);
                ind++;
            }
        }
        
        while (ind != ans.size())
        {
            num++;
            vct.pb(ans[ind]);
            ind++;
        }
        ans.clear();
        for(int i = 0; i < vct.size(); i++)
        ans.pb(vct[i]);
    }
    ll pr = ans.size();
    cout << "Yes" << "\n";
    for (int i = 0; i < pr; i++)
    {
        num++;
        last ^= ans[i];
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}