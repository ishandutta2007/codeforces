#include<bits/stdc++.h>
using namespace std;
long long pw(long long x, long long y) {
    if(y == 0) return 1;
    if(y == 1) return x;
    long long v = pw(x, y / 2);
    if(y & 1) {
        return v * v % 1000000007 * x % 1000000007;
    }
    return v * v % 1000000007;
}
long long C[251][251];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i <= 250; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % 1000000007;
        }
    }
    if(k == 1) puts("1");
    else {
        long long an = 0;
        for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) {
            int cnt = (i + j) * n - i * j;
            an = (an + (1 - (i + j) % 2 * 2) * pw(k - 1, cnt) * pw(k, n * n - cnt) % 1000000007 * C[n][i] % 1000000007 * C[n][j]) % 1000000007;
        }
        if(an < 0) an += 1000000007;
        printf("%lld\n", an);
    }
    return 0;
}