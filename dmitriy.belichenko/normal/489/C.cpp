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
int d[N];
vector<int> g[N];
int cnt[N];
vector<int> ot[N];
vector<pair<int, int>> ans;
bool used[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int m , s;
    cin >> m >> s;
    if(s == 0 && m == 1)
    {
        cout << 0 << " " << 0 << "\n";
        return 0;
    }
    if(s == 0)
    {
        cout << -1 << " " << -1 << "\n";
        return 0;
    }
    if(s > 9 * m)
    {
        cout << -1 << " " << -1 << "\n";
        return 0;
    }
    if(s <= 9)
    {
        if(m >= 2)
        {
            cout << 1;
            for(int i = 0; i < m - 2; i++) cout << 0;
            cout << s - 1;
        }
        else
        cout << s;
        cout << " " << s;
        for(int i = 0; i < m - 1; i++) cout << 0;
        cout << "\n";
        return 0;
    }
    vector<int> a(m , 0) , b(m , 0);
    for(int i = 0; i < m; i++)
    {
        if(s >= 9)
        {
            a[i] = 9;
            s -= 9;
            b[i] = a[i];
        }
        else
        {
            a[i] = s;
            s = 0;
            b[i] = a[i];
            break;
        }
        
    }
    sort(b.begin(), b.end());
    int cnt = 0;
    while (b[cnt] == 0)
    {
        cnt++;
    }
    if(cnt)
    {
        b[0] = 1;
        b[cnt]--;
    }
    for(int i = 0; i < m; i++) cout << b[i];
    cout << " ";
    for(int i = 0; i < m; i++) cout << a[i];
    cout << "\n";

    return 0;
}