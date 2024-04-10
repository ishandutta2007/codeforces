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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    ld x = m;
    ld ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        c.pb(a[i]);
    }
    for(int i = 0; i  < n;i++)
    {
        cin >> b[i];
        c.pb(b[i]);
    }
    for(int i = 0; i < 2 * n; i++)
    {
        if(c[i] == 1)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    random_shuffle(c.begin(), c.end());
    for(int i = 0; i < c.size(); i++)
    {
        x = x + (x / (c[i] - 1));
    }
    x -= m;
    cout << setprecision(8) << fixed << x;
    return 0;
}