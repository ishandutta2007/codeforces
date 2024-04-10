#include <cstdio>
#include <cstring>

const int mod = 1000000007;

const int maxlen = 5020;

const int alphabet = 256;

int p[maxlen], cnt[maxlen], c[maxlen];
int pn[maxlen], cn[maxlen];
int mh;
int pr[17][maxlen];

int lcp(int n, int i, int j) {
    // printf("LCP %d %d\n", i, j);
    int k = mh;
    int ret = 0;
    while (k >= 0) {
        // printf("S %d %d :: %d %d ; %d %d\n", k, mh, i, pr[k][i], j, pr[k][j]);
        while (k >= 0 && pr[k][i] != pr[k][j]) {
            --k;
        }
        if (k >= 0) {
            ret += (1 << k);
            i = (i + (1 << k)) % n;
            j = (j + (1 << k)) % n;
        }
    }
    return ret;
}

void suffArr(char *s, int n) {
    // printf("WTF %s %d\n", s, n);

    memset (cnt, 0, alphabet * sizeof(int));
    for (int i=0; i<n; ++i)
        ++cnt[s[i]];
    for (int i=1; i<alphabet; ++i)
        cnt[i] += cnt[i-1];
    for (int i=0; i<n; ++i) {
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]]) {
            ++classes;
        }
        c[p[i]] = classes-1;
    }
    memcpy(pr[0], c, n * sizeof(int));
    for (int h=0; (1<<h)<n; ++h) {
        for (int i=0; i<n; ++i) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        memset (cnt, 0, classes * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[c[pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i) {
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i) {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) {
                ++classes;
            }
            cn[p[i]] = classes-1;
        }
        memcpy (c, cn, n * sizeof(int));
        mh = h + 1;
        memcpy(pr[h + 1], c, n * sizeof(int));
    }
}

int n;
char s[5020];

long long dp[5020][5020];
long long sdp[5020][5020];

int main() {
    scanf("%d", &n);
    scanf("%s", s);

    s[n] = '$';
    suffArr(s, n + 1);
    
    memset(dp, 0, sizeof(dp));
    memset(sdp, 0, sizeof(sdp));
    for (int ri = n - 1; ri >= 0; --ri) {
        int k = ri + 1;
        for (int le = ri; le >= 0; --le) {
            // printf("A %d %d\n", ri, le);
            if (s[le] == '0') {
                continue;
            }
            if (ri == n - 1) {
                dp[le][ri] = 1;
                continue;
            }
            if (s[ri + 1] == '0') {
                dp[le][ri] = 0;
                continue;
            }
            int l;
            bool ok = false;
            while (!ok && k < n) {
                // printf("WTF %d %d\n", ok, k);
                if (ri - le + 1 < k - ri) {
                    ok = true;
                } else if (ri - le + 1 == k - ri) {
                    // same length
                    //
                    l = lcp(n + 1, le, ri + 1);
                    if (l < k - ri) {
                        if (s[le + l] < s[ri + 1 + l]) {
                            ok = true;
                        }
                    }
                }
                if (!ok) {
                    ++k;
                }
            }
            // printf("   KK %d %d -> %d\n", le, ri, k);
            if (k < n) {
                dp[le][ri] = sdp[ri + 1][k];
            }
        }
        sdp[ri][n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            // printf("A? %d %d\n", ri, i);
            // printf("DP %d %d -> %lld\n", ri, i, dp[ri][i]);
            sdp[ri][i] = sdp[ri][i + 1] + dp[ri][i];
            if (sdp[ri][i] >= mod) {
                sdp[ri][i] %= mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        // printf("DP %d %d %lld\n", 0, i, dp[0][i]);
        ans += dp[0][i];
        if (ans >= mod) {
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}