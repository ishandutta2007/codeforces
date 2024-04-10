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
const int N = 100;
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
int a[N][N];
int mx[2][N][N];
int mpp[2][N][N];
int ans[N][N];
ll get_ans(const int &i ,const int &j)
{
    ll sum = 1;
    sum += max(mx[0][i][j] , mx[1][i][j]);
    sum += max(mpp[0][i][j] , mpp[1][i][j]);
    return sum;
}
void construct(const int &n , const int &m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans[i][j] = get_ans(i, j);
        }
    }
}
void constructt(int flag , int n , int m)
{
    for (int i = 0; i < m; i++)
    {
        pair<int, int> tp[n];
        for (int j = 0; j < n; j++)
        {
            if(!flag)
            {
                tp[j] = (mp(a[i][j], j));
            }
            else
            {
                tp[j] = (mp(a[j][i] , j));
            }
        }
        sort(tp, tp + n);
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int last = j;
            while (last < n && tp[last].fst == tp[j].fst)
            {
                last++;
            }
            for (int k = j; k < last; k++)
            {
                mx[flag][tp[k].snd][i] = cnt;
            }
            j = last;
            cnt++;
            j--;
        }
        cnt = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            int last = j;
            while (last >= 0 && tp[last].fst == tp[j].fst)
            {
                last--;
            }
            for (int k = last + 1; k < j + 1; k++)
            {
                mpp[flag][tp[k].snd][i] = cnt;
            }
            j = last;
            cnt++;
            j++;
        }
        
    }
}
int used[N][N];
void move01()
{
    cout << "next ";
    cout << 0 << " " << 1 << endl;
    int sz;
    cin >> sz;
    string useless;
    for(int i = 0; i < sz; i++)
    {
        cin >> useless;
    }
}
int n = 0, m = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (!used[0][1])
    {
        move01();
        cout << "next 0" << endl;
        int sz;
        vector<string> s;
        cin >> sz;
        for(int i = 0; i < sz; i++)
        {
            string p;
            cin >> p;
            s.pb(p);
        }
        for(int i = 0; i < sz; i++)
        {
            string p = s[i];
            for(auto c : p)
            {
                for(auto nxt : p)
                {
                    int a = c - '0';
                    int b = nxt - '0';
                    used[a][b] = 1;
                }
            }
        }
    }
    int sz = 0;
    while (sz != 1)
    {
        cout << "next ";
        for (int i = 0; i < 10; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        cin >> sz;
        if(sz == 1)
        {
            cout<< "done";
            cout << endl;
            break;
        }
        for (int i = 0; i < sz; i++)
        {
            string p;
            cin >> p;
        }
    }
    constructt(1, n, m);
    construct(n, m);
    constructt(0, m, n);
//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//        {
//            cout << ans[i][j] << " ";
//        }
//        cout << "\n";
//    }
    return 0;
}