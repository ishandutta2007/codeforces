#pragma GCC optimize("Ofast")
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
ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MaXN = 150;
const int N = 2e5 + 1000;
const int LOG = 64;
const int FACT = 120;
ld ecr = 1e-8;
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
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll gcd_eu (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu (b%a, a, x1, y1);
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
    return poww(a , MOD - 2);
}

const unsigned ll FULL = -1;
const int pmod = 1017;
int phash[pmod];

struct kekset
{
    unsigned ll a[2];
    kekset()
    {
        none();
    }
    void none()
    {
        a[0] = a[1] = 0;
    }
    void full()
    {
        a[0] = FULL;
        a[1] = FULL;
    }
    bool empty()
    {
        return a[0] == 0 && a[1] == 0;
    }
    bool has(int pos)
    {
        if (pos < LOG)
        {
            return a[0] & (1ULL << pos);
        }
        else
        {
            pos -= LOG;
            return a[1] & (1ULL << pos);
        }
    }
    
    void unset(int pos)
    {
        if (pos < LOG)
        {
            a[0] &= FULL ^ (1ULL << pos);
        }
        else
        {
            pos -= LOG;
            a[1] &= FULL ^ (1ULL << pos);
        }
    }
    
    void set(int pos)
    {
        if (pos < LOG)
        {
            a[0] |= 1ULL << pos;
        }
        else
        {
            pos -= LOG;
            a[1] |= 1ULL << pos;
        }
    }
    
    int fb()
    {
        if (a[0] == 0)
        {
            if (a[1] == 0) return FACT;
            unsigned ll b = a[1] - (a[1] & (a[1] - 1));
            return phash[b % pmod] + LOG;
        }
        else
        {
            unsigned ll b = a[0] - (a[0] & (a[0] - 1));
            return phash[b % pmod];
        }
    }
    void sand(const kekset& to)
    {
        a[0] &= to.a[0];
        a[1] &= to.a[1];
    }
};
kekset gr[FACT], newas;
int space;
void dfs2(int i)
{
    kekset cur = gr[i];
    newas.unset(i);
    space++;
    while (true)
    {
        cur.sand(newas);
        int to = cur.fb();
        if (to >= FACT) return;
        dfs2(to);
    }
}
int to[FACT][FACT];
int fct = 1;
int solve(const vector<int>& perm)
{
    newas.full();
    for (int i = 0; i < fct; i++)
    {
        gr[i].none();
        for (int j = 0; j < perm.size(); j++)
        {
            gr[i].set(to[i][perm[j]]);
        }
    }
    space = 0;
    dfs2(0);
    return space;
}

vector<int> gp[FACT];
map<vector<int>, int> sot;

int shufl(const vector<int>& a, const vector<int>& b)
{
    vector<int> c(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        c[i] = a[b[i]];
    }
    return sot[c];
}
int a[N];
int fst[FACT];

int main()
{
    for (int i = 0; i < LOG; i++)
    {
        phash[(1ULL << i) % pmod] = i;
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        fct *= i;
    }
    vector<int> st(k);
    for(int i = 0; i < k; i++)
    {
        st[i] = i;
    }
    
    int i = 0;
    do
    {
        gp[i] = st;
        sot[st] = i++;
    } while (next_permutation(st.begin(), st.end()));
    
    for (int i = 0; i < fct; i++)
        for (int j = 0; j < fct; j++)
        {
            to[i][j] = shufl(gp[i], gp[j]);
        }
             
    for (int i = 0; i < n; i++)
    {
        vector<int> cur(k);
        for (int j = 0; j < k; j++)
        {
            cin >> cur[j];
            cur[j]--;
        }
        a[i] = sot[cur];
    }
    for (int i = 0; i < fct; i++) {
        fst[i] = n;
    }
    ll ans = 0;
    vector<int> cur;
    for (int i = n - 1; i >= 0; i--)
    {
        int prev = i;
        cur.clear();
        fst[a[i]] = i;
        cur.pb(a[i]);
        int cans = solve(cur);
        newas.full();
        newas.unset(a[i]);
        while (true)
        {
            int res = n;
            for (int j = 0; j < fct; j++)
            {
                if (newas.has(j) && fst[j] < res)
                {
                    res = fst[j];
                }
            }
            ans += 1LL * cans * (res - prev);
            prev = res;
            if (prev == n) break;
            cur.pb(a[res]);
            cans = solve(cur);
        }
    }
    cout << ans << "\n";
    return 0;
}