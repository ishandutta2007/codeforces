#pragma GCC optimize("Ofast")
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
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MaXN = 105;
const int N = 1e6 + 1000;
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
#define int ll
int a[N], b[N], rs[N];
pair<int, int> c[N];
vector<int> g[N];
bool used[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m , n, sz;
    ll ans = 0;
    cin >> m >> n;
    sz = n * 2;
    int cnt = n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i] = mp(a[i] , i);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        int ind = i + n;
        c[ind] = mp(b[i], ind);
    }
    //   n  2     
    // ind < n --> g_cnt + i , cnt = cnt + 1
    // ind > n - 1 --> g_(cnt - 1) + i, cnt = cnt - 1;
    sort(c , c + sz);
//    for(int i = 0; i < sz; i++)
//        cout << c[i].fst << " " << c[i].snd << "\n";
    

    for(int i = 0; i < sz; i++)
    {
        int ind = cnt;
        if(c[i].snd <= n - 1)
        {
            g[cnt].pb(i);
            used[cnt] = 1;
            cnt = cnt + 1;
            continue;
        }
        used[cnt - 1] = 1;
        g[cnt - 1].pb(i);
        cnt--;
    }
    
//    for(int i = 0; i < sz; i++)
//    {
//        if(g[i].size())
//        {
//            cout << i << ": ";
//            for(auto J : g[i])
//                cout << J << " ";
//        }
//        cout << "\n";
//    }

    for(int i = 0; i < sz; i++)
    {
        if(used[i])
        {
           // cout << i << "\n";
            size_t X = g[i].size();
            int fs = g[i][0], ls = g[i][X - 1];
            ll sm = 0, SM = m;
            SM += c[fs].fst;
            SM -= c[ls].fst;
            // chet / nechet
            for(int j = 0; j < X; j++)
            {
                int indNx = g[i][j + 1];
                int indCur = g[i][j];
                sm += c[indNx].fst;
                sm -= c[indCur].fst;
                j = j + 1;
            }
            for(int j = 1; j < X - 1; j++)
            {
                int indNx = g[i][j + 1];
                int indCur = g[i][j];
                SM += c[indNx].fst;
                SM -= c[indCur].fst;
                j = j + 1;
            }
            //cout << sm << " " << SM << "\n";
            ll vl = min(sm , SM);
            ans += vl;
            for(int j = 0; j < X; j++)
            {
                int to = g[i][j], ind = c[to].snd;
                int ad = 1;
                if(j & 1) ad = -1;
                if(ind < n)
                {
                    if(sm < SM)
                    {
                        int ix = g[i][j + ad];
                        rs[ind] = c[ix].snd;
                        //cout << ind << " ";
                    }
                    else
                    {
                        // cout << "CHET: " << sm << " " << "\n";
                        // cout << "NECHET: " << SM << " " << "\n";
                        // cout << "________________________\n";
                        if(j == X - 1)
                        {
                            rs[ind] = c[fs].snd;
                            // cout << ind << "X - 1" << "\n";
                        }
                        else
                        if(j > 0)
                        {
                            int ix = g[i][j - ad];
                            rs[ind] = c[ix].snd;
                        }
                        else rs[ind] = c[ls].snd;
                    }
                }
            }

        }
    }
    for(int i = 0; i < n; i++)
        rs[i] -= (n - 1);
    cout << ans << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << rs[i] << " ";
    }
    return 0;
}