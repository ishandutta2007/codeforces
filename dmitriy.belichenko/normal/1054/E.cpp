#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
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
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
const int MaXN = 26;
const int N = 3e5 + 15;
const int maxlog = 18;
ld ecr = 1e-8;
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
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
ll calc( ll i,  ll n)
{
    ll j = i;
    ll t = 0;
    while (j <= n)
    {
        t += n / j;
        j *= i;
    }
    return t;
}
ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll gcd_eu (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long val = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}
vector<pair<pair<int, int>, pair<int, int>>> dcp;
vector<pair<pair<int, int>, pair<int, int>>> cp;
vector<pair<pair<int, int>, pair<int, int>>> fin;
string st[400][400];
string en[400][400];
int a1[N] , a0[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> st[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> en[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            string cur = st[i][j];
            reverse(cur.begin(), cur.end());
            for(auto c : cur)
            {
                if(c == '0')
                {
                    if(i == 0)
                    {
                        int nxt = j + 1;
                        if(nxt >= m)
                        {
                            nxt -= m;
                        }
                        dcp.pb(mp(mp(i , j) , mp(0 , nxt)));
                        a0[nxt]++;
                        continue;
                    }
                        dcp.pb(mp(mp(i , j) , mp(0 , j)));
                        a0[j]++;
                }
                if(c == '1')
                {
                    if(i == n - 1)
                    {
                        int nxt = j + 1;
                        if(nxt >= m)
                        {
                            nxt -= m;
                        }
                        dcp.pb(mp(mp(i , j) , mp(n - 1 , nxt)));
                        a1[nxt]++;
                        continue;
                    }
                    dcp.pb(mp(mp(i , j) , mp(n - 1 , j)));
                    a1[j]++;
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(i == 0) continue;
        for(int a = 0; a < a0[i]; a++)
        {
            dcp.pb(mp(mp(0 , i) , mp(0 , 0)));
        }
        for(int a = 0; a < a1[i]; a++)
        {
            dcp.pb(mp(mp(n - 1 , i) , mp(n - 1 , 0)));
        }
    }
    for(auto i : dcp)
    {
        fin.pb(i);
    }
//    for(auto i : fin)
//    {
//        cout << i.fst.fst + 1 << " " << i.fst.snd + 1 << " " << i.snd.fst + 1 << " " << i.snd.snd + 1 << "\n";
//    }
//    cout << "\n";
    dcp.clear();
    // --- to end
    for(int i = 0; i < N; i++)
    {
        a1[i] = a0[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            string cur = en[i][j];
           // reverse(cur.begin(), cur.end());
            for(auto c : cur)
            {
                if(c == '0')
                {
                    if(i == 0)
                    {
                        int nxt = j + 1;
                        if(nxt >= m)
                        {
                            nxt -= m;
                        }
                        dcp.pb(mp(mp(i , j) , mp(0 , nxt)));
                        a0[nxt]++;
                        continue;
                    }
                    dcp.pb(mp(mp(i , j) , mp(0 , j)));
                    a0[j]++;
                }
                if(c == '1')
                {
                    if(i == n - 1)
                    {
                        int nxt = j + 1;
                        if(nxt >= m)
                        {
                            nxt -= m;
                        }
                        dcp.pb(mp(mp(i , j) , mp(n - 1 , nxt)));
                        a1[nxt]++;
                        continue;
                    }
                    dcp.pb(mp(mp(i , j) , mp(n - 1 , j)));
                    a1[j]++;
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(i == 0) continue;
        for(int a = 0; a < a0[i]; a++)
        {
            dcp.pb(mp(mp(0 , i) , mp(0 , 0)));
        }
        for(int a = 0; a < a1[i]; a++)
        {
            dcp.pb(mp(mp(n - 1 , i) , mp(n - 1 , 0)));
        }
    }
    reverse(dcp.begin(), dcp.end());
    for(auto i : dcp)
    {
        pair<pair<int, int>, pair<int, int>> cur = i;
        swap(cur.fst.fst , cur.snd.fst);
        swap(cur.fst.snd , cur.snd.snd);
        fin.pb(cur);
    }
    cout << fin.size() << "\n";
    for(auto i : fin)
    {
        cout << i.fst.fst + 1 << " " << i.fst.snd + 1 << " " << i.snd.fst + 1 << " " << i.snd.snd + 1 << "\n";
    }
    return 0;
}