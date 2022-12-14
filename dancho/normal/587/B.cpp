#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1000000007;

long long n, l, k;
vector<vector<int> > dp;
vector<int> sdp;
long long a[1 << 20];
pair<long long, int> sa[1 << 20];
int nn[1 << 20];

int main() {
    scanf("%lld %lld %lld", &n, &l, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        sa[i] = make_pair(a[i], i);
    }
    sort(sa, sa + n);
    for (int i = 0; i < n;) {
        int no = i;
        while (no < n && sa[i].first == sa[no].first) {
            ++no;
        }
        for (int j = i; j < no; ++j) {
            nn[sa[j].second] = no - 1; 
        }
        i = no;
    }

    long long ans = 0;
    dp.assign(k, vector<int>(n));
    sdp.resize(n);
    for (long long i = 0; i < n; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            sdp[i] = dp[0][sa[i].second];
        } else {
            sdp[i] = sdp[i - 1] + dp[0][sa[i].second];
        }
        if (sdp[i] >= mod) {
            sdp[i] %= mod;
        }
    }

    for (long long j = 1; j < k; ++j) {
        for (long long i = 0; i < n; ++i) {
            // printf("ADD %lld %d %d\n", j, (int) i, sdp[nn[i]]);
            dp[j][i] = sdp[nn[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                sdp[i] = dp[j][sa[i].second];
            } else {
                sdp[i] = sdp[i - 1] + dp[j][sa[i].second];
            }
            if (sdp[i] >= mod) {
                sdp[i] %= mod;
            }
        }
    }
    ans = 0;
    for (int j = 0; j < k; ++j) {
        for (int i = 0; i < n; ++i) {
            long long mul = l / n;
            if (i < l % n) {
                ++mul;
            }
            mul -= j;
            if (mul > 0) {
                if (mul >= mod) {
                    mul %= mod;
                }
                ans += (long long) dp[j][i] * mul;
                // printf("DP %d %d -> %lld %d %lld\n", j, i, j * n + i, dp[j][i], mul);
            }
            if (ans >= mod) {
                ans %= mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}