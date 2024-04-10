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
const int maxn = 1 << maxlog;
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
int n, m, w, cl, ce, del , x;
int x1, x2, y2 , cur;
set<int> p , q;
void norm(int &x1 , int &y1 , int &x2 , int &y2)
{
    if (x1 > x2)
    {
        swap(x1, x2);
    }
    if (y1 > y2)
    {
        swap(y1, y2);
    }
    x2 = max(x1 , x2);
    y2 = max(y1 , y2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m >> cl >> ce >> del;
    poww(n , MOD);
    for (int i = 0; i < cl; i++)
    {
        cin >> x;
        p.insert(x);
    }
    for (int i = 0; i < ce; i++)
    {
        cin >> x;
        q.insert(x);
    }
    int y1;
    int qr;
    cin >> qr;
    while (qr--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 2e9;
        if (x1 == x2)
        {
            cout << abs(y1 - y2) << "\n";
            continue;
        }
        norm(x1 , y1 , x2 , y2);
        auto now = p.lower_bound(y1);
        
        if (now != p.end())
        {
            cur = *now;
            ans = min(ans, abs(x2 - x1) + abs(y1 - cur) + abs(y2 - cur));
            if (now != p.begin())
            {
                --now;
                cur = *now;
                ans = min(ans, x2 - x1 + abs(y1 - cur) + abs(y2 - cur));
            }
        }
        else
        {
            
            if (now != p.begin())
            {
                --now;
                cur = *now;
                ans = min(ans, x2 - x1 + abs(y1 - cur) + abs(y2 - cur));
            }
        }
        now = q.lower_bound(y1);
        if (now != q.end())
        {
            cur = *now;
            ans = min(ans, abs(y1 - cur) + abs(y2 - cur) + abs(x2 - x1 + del - 1) / del);
            if (now != q.begin())
            {
                --now;
                cur = *now;
                ans = min(ans, abs(y1 - cur) + abs(y2 - cur) + abs(x2 - x1 + del - 1) / del);
            }
        }
        else
        {
            if (now != q.begin())
            {
                --now;
                cur = *now;
                ans = min(ans, abs(y1 - cur) + abs(y2 - cur) + abs(x2 - x1 + del - 1) / del);
            }
        }
        ans = max(ans , 0);
        cout << ans << "\n";
    }
    

}