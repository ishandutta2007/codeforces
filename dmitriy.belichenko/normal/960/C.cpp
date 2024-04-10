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
const int MAXN = 10000;
ll mxr = 1000000000000000000;
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
ll sm = 0;
int lg = 0;
int r = 0;
ll a[N + 5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x , n;
    cin >> x >> n;
    n = n + 1;
    int cnt = 0;
    while(x > 0)
    {
        lg++;
        if(x % 2 != 0)
        {
            for(int i = 0; i + 1 < lg; i++)
            {
                a[cnt++] = sm;
                if(cnt > N)
                {
                    cout << -1;
                    return 0;
                }
            }
            sm = sm + n;
        }
        r += x % 2;
        x /= 2;
        if(sm > mxr)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    for(int i = 0; i < r; i++)
    {
        a[cnt++] = sm;
        if(cnt > N)
        {
            cout << -1;
            return 0;
        }
        sm = sm + n;
    }
    if(a[N] == 0)
    {
        cout << cnt << "\n";
        for(int i = 0; i < cnt; i++)
        {
            cout << a[i] + 1 << " ";
        }
    }
    else cout << -1 << "\n";
    return 0;
}