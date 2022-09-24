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
vector<ll> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll p , k;
    cin >> p >> k;
    int iter = 0;
    if(p == 0)
    {
        cout << "1\n0";
        return 0;
    }
    while(iter++ < 1e5 && (p >= k || p < 0))
    {
        ll val = p / (-k);
        while( p + val * k < 0) val++;
        f.pb( p  + val * k);
        p = val;
    }
    if(p != 0) f.pb(p);
    cout << f.size() << "\n";
    //reverse(f.begin(), <#_BidirectionalIterator __last#>)
        for(int i = 0; i < f.size(); i++)
        {
            cout << f[i] << " ";
        }
          return 0;
}