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
struct MT{
        int n{};
        int m{};
        int mt[len][len]{};
        MT() {
            for (auto & i : mt) {
                for (int & j : i) j = 0;
            }
        }
};
MT mult(const MT &left, const MT &right) {
    MT res;
    res.n = left.n;
    res.m = right.m;
    for (int i = 0; i < res.n; i++) {
        for (int k = 0; k < left.m; k++) {
            for (int j = 0; j < right.m; j++) {
                sum(res.mt[i][j], mult(left.mt[i][k], right.mt[k][j]));
            }
        }
    }
    return res;
}
MT E, trans;
MT powmod(const MT m, int n) {
    if (!n) return E;
    auto left = powmod(m, n / 2);
    auto sqr = mult(left, left);
    if (n & 1) return mult(sqr, m);
    return sqr;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < len; i++)  {
       E.mt[i][i] = 1;
       E.n = E.m = 101;
    }
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &p : a) {
        cin >> p;
        int l = len - p - 1;
        trans.mt[l][len - 2]++;
        trans.mt[l][len - 1]++;
    }
    trans.mt[len - 1][len - 1] = 1;
    for (int i = 1; i < len - 1; i++) {
        trans.mt[i][i - 1] = 1;
    }
    trans.n = len;
    trans.m = len;
    MT init;

    trans = powmod(trans, x);

    init.mt[0][len - 2] = 1;
    init.mt[0][len - 1] = 1;

    init.n = 1;
    init.m = len;
    init = mult(init, trans);

    cout << init.mt[0][len - 1] << "\n";

}