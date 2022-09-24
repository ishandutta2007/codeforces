#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 998244353;
const int INF = 1e5;
const int MaXN = 150;
const int N = 2e5 + 228;
const int LOG = 25;
const int FACT = 120;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
typedef uint64_t ull;
uniform_int_distribution<ull> nextRand(0, (1LL << 62) - 1);
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
    ll val = a * b - (ll)((ld)a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
ll gcd_eu(ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long val = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}
ll inv(ll a)
{
    return poww(a, MOD - 2);
}
int gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1 = 0, y1 = 0;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int cnt = 0;
string s;
vector<int> a, b;

int merge_sort(int l, int r) {
    if (r - l <= 1) return 1;
    int m = (r + l) / 2;
    if(!merge_sort(l, m)) return 0;
    if(!merge_sort(m, r)) return 0;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (cnt >= s.size()) {
         //   cout << cnt << " " << s.size() << "\n";
            return 0;
        }
        if (s[cnt] == '0') { //(a[i] < a[j]) {
            // log.append('0')
            b[k] = a[i];
            i++;
        } else {
            // log.append('1')
            b[k] = a[j];
            j++;
        }
        k++; cnt++;
    }
    while (i < m) {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j < r) {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int p = l; p < r; p++) {
        a[p] = b[p];
    }
    return 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int l = 1, r = s.size() + 1, len = -1;
    a.resize(r + 1);
    b.resize(r + 1);
    while(r - l > 1) {
        int m = (r + l) / 2;
        cnt = 0;
        for(int i = 0; i < m; i++) a[i] = i;
        b = a;
        if (merge_sort(0, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cnt = 0;
    len = l;
   // cout << l << "\n";
    for(int it = 0; it < 2; it++) {
        a.resize(len);
        b.resize(len);
        for(int i = 0; i < len; i++) {
            a[i] = b[i] = i;
        }
        cnt = 0;
        //cout << '\n';
        if (merge_sort(0, len)) {
         //   cout << cnt << " " << len << "\n";
            if (cnt == s.size()) {
                for (int i = 0; i < len; i++) {
                    b[a[i]] = i + 1;
                }
                cout << len << "\n";
                for(auto x : b) {
                    cout << x << " ";
                }
                return 0;
            }
        }
        len++;
    }
}