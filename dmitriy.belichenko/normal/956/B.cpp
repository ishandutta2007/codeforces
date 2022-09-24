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
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n , m;
    cin >> n >> m;
    ll ans = 0 , res = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cur = 0;
    ll c , d;
    // x1 y > y1 x -> x y
    for(int i = 0; i < n - 2; i++)
    {
        cur = max(cur , i);
        res = max(res , 1LL);
        while(a[cur + 1] - a[i] - 1 < m  && cur + 1 < n) cur++;
      //  cout << cur << "\n";
        // cout << a[cur] - a[I + 1] << "\n";
        if( (a[cur] - a[i + 1]) * res > ans * (a[cur] - a[i]))
        {
            res = (a[cur] - a[i]);
            ans = (a[cur] - a[i + 1]);
        }
        
    }
    if(ans)
    {
        ld p =  (ld)ans / (ld) res;
        cout << setprecision(10) << fixed << p << "\n";
    }
    else cout << -1 << "\n";
    return 0;
}