#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define mod ((long)1e9 + 7)
#define maxn ((long)1e6 + 10)
#define maxpower (20)

namespace Solution {

int p[maxn] = {0};
void sieve() {
    for (long i = 2; i < maxn; ++i)
        if (p[i] == 0) {
            p[i] = i;
            for (long f = i * i; f < maxn; f += i)
                p[f] = i;
        }
}

ve<vi> dp;
void preprocess() {
    dp.resize(maxn, vi(maxpower, 2));
    dp[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        dp[i][0] = 1;
        for (int f = 1; f < maxpower; ++f) 
            dp[i][f] = ((long)dp[i - 1][f] + (long)dp[i][f - 1]) % mod;
    }
}

long f(int r, int n) {
    map<int, int> fcnt;
    long ans = 1;
    for (; n > 1; n /= p[n]) fcnt[p[n]]++;
    for (ii i : fcnt) {
        ans = (ans * dp[r][i.yy]) % mod;
    }
    return ans;
}

int main() {
    sieve();
    preprocess();
    int t; cin >> t;
    while (t--) {
        int n, r;
        cin >> r >> n;
        cout << f(r, n) << '\n';
    }

    return 0;
}}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Solution::main();
}