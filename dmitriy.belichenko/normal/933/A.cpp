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
const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
int gcd(int a, int b)
{
    if (b == 0) return a;
    if (a == 0) return b;
    if (a % b == 0) return b;
    else  return gcd(b % a, a);
}
ll mult(ll a, ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a, long long b)
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
int pref[N] , suff[N];
int d[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    pref[0] = 0;
    for(int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + (a[i - 1] == 1);
    }
    suff[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + (a[i + 1] == 2);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        d[0] = -3;
        for (int p = 1; p <= n; ++p)
            d[p] = 0;
        for(int j = i; j < n; j++)
        {
            int curlen = pref[i] + suff[j];
            int k = int (upper_bound (d , d + n + 1, -a[j]) - d);
            //  cout << i << " " << j << " " << k << "\n";
            if (d[k-1] <= -a[j] && -a[j] <= d[k])
                d[k] = -a[j];
            int sz = lower_bound(d, d + n + 1, 0) - d - 1;
            //            cout << pref[i] << " " << suff[j] << " " << sz << "\n";
            //            cout << "_____________________\n";
            ans = max(curlen + sz, ans);
        }
        
    }
    
    cout << ans << "\n";
}