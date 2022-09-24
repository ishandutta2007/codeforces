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
int solve(int x)
{
    int u;
    cout << x << endl;
    cin >> u;
    if(u == 0)
    {
        exit(0);
    }
    return u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    swap(n , m);
    for(int i = 0; i < n; i++)
    {
        a[i] = solve(1);
    }
    int l = 0;
    int r = m;
    for(int i = 0; l < r + 1; i++ , i %= n)
    {
        int u;
        int mid = (r + l) / 2;
        u = solve(mid);
        if((u == 1 && a[i] == 1) ||(u * a[i] == 1) )
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return 0;
}