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
#define integ __int128
#define ld long double
#define mt make_tuple
const double PI = acos(-1);
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MAXN = 26;
const ll MOD = 1e18 + 9;
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
    long long c = 1ll * (a % MOD) * (b % MOD);
    return c % MOD;
}
ll poww(ll a, long long b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
int a[N];
int b[N];
vector<int> c;
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n >> k;
    int gc = k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        gc = gcd(gc , a[i] % k);
    }
    int ans = k / gc;
    cout << ans << "\n";
    int x = 0;
    while(x < k)
    {
        x += gc;
        cout << x - gc << " ";
    }
    return 0;
}