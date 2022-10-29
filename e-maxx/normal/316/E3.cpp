#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 4 * 210 * 1000;
const int MOD = INF;


int n, m, a[MAXN];


bool read() {
    if (!(cin >> n >> m))
        return false;
    forn(i, n)
        scanf("%d", &a[i]);
    return true;
}


int fib[MAXN], fibsum[MAXN];

void precalc() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    
    fibsum[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        fibsum[i] = (fibsum[i - 1] + fib[i]) % MOD;
}


struct item {
    int sum0, sum1, len;

    item() {}
    item (int sum0, int sum1, int len) : sum0(sum0), sum1(sum1), len(len) {}
};

inline int64 get_fib(int n) {
    if (n < 0)
        return 0;
    return fib[n];
}

inline item operator+ (const item& a, const item& b) {
    if (a.len == 0)
        return b;
    if (b.len == 0)
        return a;
    return item((a.sum0 + b.sum0 * 1ll * get_fib(a.len - 2) + b.sum1 * 1ll * get_fib(a.len - 1)) % MOD,
                (a.sum1 + b.sum0 * 1ll * get_fib(a.len - 1) + b.sum1 * 1ll * get_fib(a.len)) % MOD,
                a.len + b.len);
}


int tadd[MAXN];
item t[MAXN];

void build(int v, int l, int r) {
    tadd[v] = 0;
    if (l == r)
        t[v] = item(a[l], a[r], 1);
    else {
        int m = (l + r) >> 1;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

inline void relax(int v, int tl, int tr) {
    if (tadd[v]) {
        int len = tr - tl + 1;
        t[v].sum0 = (t[v].sum0 + tadd[v] * 1ll * fibsum[len - 1]) % MOD;
        t[v].sum1 = (t[v].sum1 + tadd[v] * 1ll * fibsum[len] - tadd[v]) % MOD;

        if (tl != tr) {
            tadd[v * 2] = (tadd[v * 2] + tadd[v]) % MOD;
            tadd[v * 2 + 1] = (tadd[v * 2 + 1] + tadd[v]) % MOD;
        }
        tadd[v] = 0;
    }
}

void update(int v, int tl, int tr, int pos, int val) {
    relax(v, tl, tr);

    if (tl == tr)
        t[v] = item(val, val, 1);
    else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        relax(v * 2, tl, tm);
        relax(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

item get_sum(int v, int tl, int tr, int l, int r) {
    relax(v, tl, tr);

    if (l > r)
        return item(0, 0, 0);
    if (tl == l && r == tr)
        return t[v];
    
    int tm = (tl + tr) >> 1;
    item a = get_sum(v * 2, tl, tm, l, min(r, tm));
    item b = get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return a + b;
}

void increment(int v, int tl, int tr, int l, int r, int val) {
    relax(v, tl, tr);

    if (l > r)
        return;
    if (tl == l && r == tr) {
        tadd[v] = (tadd[v] + val) % MOD;
        return;
    }

    int tm = (tl + tr) >> 1;
    increment(v * 2, tl, tm, l, min(r, tm), val);
    increment(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);

    relax(v * 2, tl, tm);
    relax(v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
}


void solve() {
    build(1, 0, n - 1);

    forn(i, m) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int x, v;
            scanf("%d%d", &x, &v);
            --x;
            update(1, 0, n - 1, x, v);
        }
        else if (tp == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            --l, --r;
            printf("%d\n", get_sum(1, 0, n - 1, l, r).sum0);
        }
        else if (tp == 3) {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            --l, --r;
            increment(1, 0, n - 1, l, r, d);
        }
        else
            throw;
    }
}


int main(int argc, char* argv[]) {
    precalc();

#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
    while (read())
        solve();
#else
    if (!read())
        throw;
    solve();
#endif
}