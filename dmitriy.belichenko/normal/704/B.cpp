#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(239);
const int len = 101;
const int MOD = 1e9 + 7;
template<class A, class B>
void sum(A &a, B b) {
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}
long long mult(long long a, long long b) {
    long long val = a * b - (long long)((long double)a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
vector<long long> x,a,b,c,d;
int son[5005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s, e;
    cin >> n >> s >> e;
    s--, e--;
    son[s] = e;
    x.resize(n);
    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);
    for(auto &p : x) cin >> p;
    for(auto &p : a) cin >> p;
    for(auto &p : b) cin >> p;
    for(auto &p : c) cin >> p;
    for(auto &p : d) cin >> p;
    for (int i = 0; i < n; i++) {
        a[i] += x[i];
        c[i] += x[i];
        b[i] -= x[i];
        d[i] -= x[i];
    }
    auto dist = [] (int x, int y) {
        if (x < y) return a[y] + d[x];
        else return b[y] + c[x];
    };
    long long cur = dist(s, e);
    for (int i = n - 1; i >= 0; i--) {
        if (i == s) continue;
        if (i == e) continue;
        long long len = 1e18;
        int index = -228;
        for (int j = s; j != e; j = son[j]) { // 
            long long distance = dist(j, i) + dist(i, son[j]);
            long long neg_dist = dist(j, son[j]);
            if (len > distance - neg_dist) {
                len = distance - neg_dist;
                index = j;
            }
        }
        cur += len;
        son[i] = son[index];
        son[index] = i;
    }
    cout << cur << "\n";


}