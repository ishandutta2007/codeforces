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
const int N = 1e6 + 7;
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
ld pref[N];
ld a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q , n = 0;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            n++;
            a[n - 1] = pref[n - 1] = x;
            if (n > 1)
                pref[n - 1] += pref[n - 2];
        }
        else
        {
            ld lp = a[n - 1] , div = 1;
            int l = 0, r = n - 1;
            while (r - l > 1)
            {
                int mid = (r + l) / 2;
                ll sum = pref[mid] + a[n - 1];
                if (a[mid] * (mid) > sum - 2 * a[mid])
                    r = mid;
                else
                    l = mid;
            }
            if (pref[l] * div - 2 * lp <= l * lp)
            {
                lp = pref[l] + a[n - 1];
                div = l + 2;
            }
            cout << setprecision(6) << fixed <<  a[n - 1] - lp / (ld)div << "\n";
        }
    }
    return 0;
}