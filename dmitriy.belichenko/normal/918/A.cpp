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
ll p[N];
ll mx = 0 , ans = 0;
set<int> fib;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a = 1;
    int b = 1;
    int c;
    for(int i = 0; i < 30; i++)
    {
        c = a + b;
        a = b;
        b = c;
        fib.insert(a);
        fib.insert(b);
    }
    for(int i = 0; i < n; i++)
    {
        if(fib.count(i + 1)) cout << 'O';
        else cout << 'o';
    }
}