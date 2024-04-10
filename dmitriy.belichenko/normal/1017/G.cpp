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
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
const int MaXN = 26;
const int MN = 1e5 + 5;
const int maxlog = 18;
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
ll calc( ll i,  ll n)
{
    ll j = i;
    ll t = 0;
    while (j <= n)
    {
        t += n / j;
        j *= i;
    }
    return t;
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
int N, Q, pr[MN], ch[MN], wei[MN];
int fir[MN], pref[MN], suff[MN], cur = 0, cntr = 0;
pair<ll , ll> T[MN * 4];
bool t[MN * 4];
vector<int> g[MN];
void dfs(int v, int d)
{
    wei[v] = 1;
    for (int w : g[v])
    {
        dfs(w, d + 1);
        wei[v] += wei[w];
    }
}

void hld(int v)
{
    if (fir[cntr] == -1) fir[cntr] = v;
    ch[v] = cntr;
    pref[v] = ++cur;
    int maxInd = -1;
    for (int w : g[v])
    {
        if (maxInd == -1 || wei[maxInd] < wei[w]) maxInd = w;
    }
    if (maxInd != -1) hld(maxInd);
    for (int w : g[v])
    {
        if (w == maxInd) continue;
        cntr++;
        hld(w);
    }
    suff[v] = cur;
}

pair<ll, ll> merge(const pair<ll, ll>  &a, const pair<ll, ll>  &b)
{
    return {max(a.fst + b.snd, b.first), a.second + b.second};
}

void build(int cur, int cL, int cR)
{
    if (cL == cR)
    {
        T[cur] = {-1, -1};
        t[cur] = 0;
        return;
    }
    int m = cL + (cR - cL) / 2;
    build(cur * 2, cL, m);
    build(cur * 2 + 1, m + 1, cR);
    T[cur] = merge(T[cur * 2], T[cur * 2 + 1]);
}

void clac(int cur, int cL, int cR)
{
    if (t[cur])
    {
        int m = cL + (cR - cL) / 2;
        T[cur * 2] = {-1, -(m - cL + 1)};
        T[cur * 2 + 1] = {-1, -(cR - m)};
        t[cur * 2] = t[cur * 2 + 1] = 1;
        t[cur] = 0;
    }
}

void upd(int cur, int cL, int cR, int l, int r)
{
    if (cL > r || cR < l) return;
    if (cL != cR) clac(cur, cL, cR);
    if (cL >= l && cR <= r)
    {
        T[cur] = {-1, -(cR - cL + 1)};
        t[cur] = 1;
        return;
    }
    int m = cL + (cR - cL) / 2;
    upd(cur * 2, cL, m, l, r);
    upd(cur * 2 + 1, m + 1, cR, l, r);
    T[cur] = merge(T[cur * 2], T[cur * 2 + 1]);
}

void inc(int cur, int cL, int cR, int ind, ll val)
{
    if (cL > ind || cR < ind) return;
    if (cL != cR) clac(cur, cL, cR);
    if (cL == cR) {
        T[cur].first += val;
        T[cur].second += val;
        return;
    }
    int m = cL + (cR - cL) / 2;
    inc(cur * 2, cL, m, ind, val);
    inc(cur * 2 + 1, m + 1, cR, ind, val);
    T[cur] = merge(T[cur * 2], T[cur * 2 + 1]);
}

pair<ll, ll>  query(int cur, int cL, int cR, int l, int r)
{
    if (cL != cR) clac(cur, cL, cR);
    if (cL > r || cR < l) return {-INF, 0};
    if (cL >= l && cR <= r) return T[cur];
    int m = cL + (cR - cL) / 2;
    return merge(query(cur * 2, cL, m, l, r), query(cur * 2 + 1, m + 1, cR, l, r));
}

ll up(int v)
{
    pair<ll, ll>  ret = {-INF, 0};
    while (v != 0)
    {
        ret = merge(query(1, 1, N, pref[fir[ch[v]]], pref[v]), ret);
        v = pr[fir[ch[v]]];
    }
    return ret.fst;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    int t, v;
    pr[1] = 0;
    for(int i = 2; i <= N ; i++)
    {
        cin >> pr[i];
        g[pr[i]].pb(i);
    }
    for(int i = 0; i < N; i++) fir[i] = -1;
    dfs(1, 0);
    hld(1);
    build(1, 1, N);
    for(int i = 0; i < Q; i++)
    {
        string ans = "black";
        cin >> t >> v;
        if (t == 1) inc(1, 1, N, pref[v], 1);
        else if (t == 2)
        {
            upd(1, 1, N, pref[v], suff[v]);
            if (pr[v] != 0)
            {
                ll x = up(pr[v]);
                if (x > 0) inc(1, 1, N, pref[v], -x);
            }
        }
        else
        {
            if(up(v) < 0)
            {
                ans = "white";
            }
            cout << ans << "\n";
        }
    }
    return 0;
}