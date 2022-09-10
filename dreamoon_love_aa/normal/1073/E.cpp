#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long LL;
LL l, r;
int K;
int d[20], dn;
LL dp[20][2][1024],dp2[20][2][1024];
void add_with_MOD(LL& x, LL v) {
    x = (x + v) % MOD;
}
LL solve(LL x) {
    if(!x) {
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    dn = -1;
    while (x) {
        d[++dn] = x % 10;
        x /= 10;
    }
    for(int i = 1; i < d[dn]; i++) {
        dp[dn][0][1<<i] = i;
        dp2[dn][0][1<<i] = 1;
    }
    dp[dn][1][1 << d[dn]] = d[dn];
    dp2[dn][1][1 << d[dn]] = 1;
    for(int i = dn; i > 0; i--) {
        for(int j = 1; j <= 9; j++) {
            add_with_MOD(dp[i - 1][0][1<<j], j);
            add_with_MOD(dp2[i - 1][0][1<<j], 1);
        }
        for(int bit_mask = 0; bit_mask < 1024; bit_mask++) {
            for(int j = 0; j <= 9; j++) {
                add_with_MOD(dp[i - 1][0][bit_mask | (1 << j)], dp[i][0][bit_mask] * 10 + j * dp2[i][0][bit_mask]);
                add_with_MOD(dp2[i - 1][0][bit_mask | (1 << j)], dp2[i][0][bit_mask]);
            }
            for(int j = 0; j < d[i - 1]; j++) {
                add_with_MOD(dp[i - 1][0][bit_mask | (1 << j)], dp[i][1][bit_mask] * 10 + j * dp2[i][1][bit_mask]);
                add_with_MOD(dp2[i - 1][0][bit_mask | (1 << j)], dp2[i][1][bit_mask]);
            }
            for(int j = d[i - 1]; j <= d[i - 1]; j++) {
                add_with_MOD(dp[i - 1][1][bit_mask | (1 << j)], dp[i][1][bit_mask] * 10 + j * dp2[i][1][bit_mask]);
                add_with_MOD(dp2[i - 1][1][bit_mask | (1 << j)], dp2[i][1][bit_mask]);
            }
        }
    }
    LL res = 0;
    for(int i = 0; i < 1024; i++) {
        int cnt = 0;
        for(int j = 0; j < 10; j++) {
            cnt += (i >> j) & 1;
        }
        if(cnt <= K) {
            add_with_MOD(res, dp[0][0][i]);
            add_with_MOD(res, dp[0][1][i]);
        }
    }
    return res;
}
int main(){
    cin >> l >> r >> K;
    LL an = solve(r) - solve(l - 1);
    an %= MOD;
    if(an < 0) an += MOD;
    cout << an << endl;
    return 0;
}