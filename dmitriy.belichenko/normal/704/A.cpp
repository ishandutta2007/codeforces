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

set<int> q;
const int N = 3e5 + 5;
vector<int> g[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, query;
    cin >> n >> query;
    int cnt = 0;
    while(query--) {
        int u, v;
        cin >> u >> v;
        if (u == 3) {
            while (!q.empty()) {
                auto x = *q.begin();
                if (x > v) break;
                else q.erase(x);
            }
        }
        if (u == 1) {
            q.insert(++cnt);
            g[v].push_back(cnt);
        }
        if (u == 2) {
            auto &vec = g[v];
            for (auto x : vec) q.erase(x);
            vec.clear();
        }
        cout << q.size() << "\n";
    }


}