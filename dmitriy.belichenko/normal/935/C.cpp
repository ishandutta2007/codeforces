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
using namespace std;
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
bool check(int a , int n)
{
    int cnt = 0;
    while(a > 0)
    {
        cnt += a % 10;
        if(a % 10 > n || a % 10 == 0) return false;
        a /= 10;
    }
    return (cnt % n == 0);
}
ld eps = 1e-12;
int main()
{
    ld R , x1 , y1 , x2 , y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    x1 += eps;
    y2 += eps;
    ld p =sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if(p >= R)
    {
        cout << x1 << " " << y1 << " " << R <<"\n";
        return 0;
    }
    ld seg = R + p;
    ld ansR = seg / 2;
    ld xv = (-x2 + x1) / p * (ansR - p) + x1;
    ld yv = (-y2 + y1) / p * (ansR - p) + y1;
    cout << setprecision(6) << fixed << xv << " " << yv << " " << ansR << "\n";
}