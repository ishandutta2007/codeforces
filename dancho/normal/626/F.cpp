#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int mod = 1000000007;

int n, k;
int a[512];
int dp[202][102][2020];

long long getDP(int p, int no, int cs) {
    if (no < 0) {
        return 0;
    }
    if (no > 100) {
        return 0;
    }
    if (p >= n) {
        if (no == 0 && cs >= 0 && cs <= k) {
            return 1;
        }
        return 0;
    }
    int ncs = cs + no * a[p] + 1010;
    if (ncs < 0 || ncs >= 2020) {
        return 0;
    }
    if (dp[p][no][ncs] != -1) {
        return dp[p][no][ncs];
    }
    long long sl = 0;
    sl += 1LL * getDP(p + 1, no, cs) * (no + 1LL);
    if (sl >= mod) {
        sl %= mod;
    }
    sl += 1LL * getDP(p + 1, no + 1, cs - a[p]);
    if (sl >= mod) {
        sl %= mod;
    }
    sl += 1LL * getDP(p + 1, no - 1, cs + a[p]) * 1LL * no;
    if (sl >= mod) {
        sl %= mod;
    }
    return (dp[p][no][ncs] = sl);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    a[n] = 0;
    
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", getDP(0, 0, 0));
    return 0;
}