#include <cstdio>
#include <cstring>

const long long mod = 1000000007;

int n;
long long x[1 << 20];
long long y[1 << 20];
long long d[1 << 20];
long long sx[1 << 20];
long long sy[1 << 20];
long long sd[1 << 20];
long long ssd[1 << 20];

long long cirsm(int s, int v, long long sa[] = sd) {
    long long ar = 0;
    if (s > 0 && v > s) {
        ar = sa[v - 1] - sa[s - 1];
    } else if (s == 0) {
        ar = sa[v - 1];
    } else {
        ar = sa[n + v - 1] - sa[s - 1];
    }
    return ar;
}

// returns area from s to v
//
long long area(int s, int v) {
    long long ar = cirsm(s, v);
    ar += (x[s] - x[v]) * (y[s] + y[v]);
    return ar;
}

// returns sum of ssd
//
long long sumsd2(int s, int v) {
    // Write for s = 0 
    long long ar = 0;
    if (s == 0) {
        ar = ssd[v - 1];
    } else if (s < v) {
        long long rm = (long long) (v - s) * (sd[s - 1] % mod);
        rm = rm % mod;
        if (rm < 0) {
            rm += mod;
        }
        ar = (mod + ssd[v - 1] - ssd[s - 1] + mod - rm) % mod;
    } else {
        v += n;
        long long rm = (long long) (v - s) * (sd[s - 1] % mod);
        rm = rm % mod;
        if (rm < 0) {
            rm += mod;
        }
        ar = (mod + ssd[v - 1] - ssd[s - 1] + mod - rm) % mod;
    }
    return ar;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        long long xx, yy;
        scanf("%lld %lld", &xx, &yy);
        x[i + n] = x[i] = xx;
        y[i + n] = y[i] = yy;
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (i + 1 < 2 * n) {
            d[i] = (x[i + 1] - x[i]) * (y[i + 1] + y[i]);
            // printf("DD %d %lld\n", i, d[i]);
        } else {
            d[i] = d[i - n];
        }
        if (i == 0) {
            sx[i] = x[i];
            sy[i] = y[i];
            sd[i] = d[i];
            ssd[i] = sd[i] % mod;
            if (ssd[i] < 0) {
                ssd[i] += mod;
            }
        } else {
            sx[i] = sx[i - 1] + x[i];
            sy[i] = sy[i - 1] + y[i];
            sd[i] = sd[i - 1] + d[i];
            ssd[i] = ssd[i - 1] + sd[i];
            ssd[i] %= mod;
            if (ssd[i] < 0) {
                ssd[i] += mod;
            }
        }
    }
    long long S = sd[n - 1];
    long long ans = 0;
    int k = 1;
    int v = 0;
    long long dsm = 0;
    while (k < n && 2 * area(0, k + 1) < S) {
        ++k;
        dsm += (x[k] - x[0]) * (y[k] + y[0]);
        dsm %= mod;
        if (dsm < 0) {
            dsm += mod;
        }
    }
    for (int i = 0; i < n; ++i) {
        long long lt = cirsm(i, k) % mod;
        if (lt < 0) {
            lt += mod;
        }
        long long gt = cirsm(k, i) % mod;
        if (gt < 0) {
            gt += mod;
        }
        long long cnt = (k - 1 - i);
        if (cnt < 0) {
            cnt += n;
        }
        long long aa = 0;
        aa = cnt * (cirsm(i + 1, k) % mod) - sumsd2(i + 1, k);
        aa %= mod;
        if (aa < 0) {
            aa += mod;
        }
        if (cnt) {
            long long ch = cnt * (gt - lt + mod) + aa + aa + 2LL * dsm;
            ch %= mod;
            ans += ch;
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
        }

        if (i + 1 >= n) {
            break;
        }
        if (k != (i + 1) % n) {
            int j = (i + 2) % n;
            dsm -= (x[j] - x[i]) * (y[j] + y[i]);
            dsm %= mod;
            if (dsm < 0) {
                dsm += mod;
            }
        }
        long long ndi = k - i - 2;
        if (ndi < 0) {
            ndi += n;
        }
        // printf("AFTER RM %d %d : %lld [%lld]\n", i, j, dsm, ndi);
        if (k != (i + 1) % n && k != (i + 2) % n) {
            long long c = (x[i + 1] * y[i + 1] - x[i] * y[i]) % mod;
            dsm = dsm - c * ndi;
            dsm %= mod;

            // printf("AA %lld\n", dsm);
            
            long long xsm = cirsm(i + 3, k + 1, sx) % mod;
            dsm += xsm * (y[i + 1] - y[i]);
            long long ysm = cirsm(i + 3, k + 1, sy) % mod;
            dsm -= ysm * (x[i + 1] - x[i]);
            dsm %= mod;
            if (dsm < 0) {
                dsm += mod;
            }
        }
        // printf("BEF %d %d %lld\n", i, k, (long long) dsm);
        if ((i + 1) == k) {
            k = (i + 2) % n;
        }
        // printf("GO %d %d %lld\n", i, k, (long long) dsm);
        while ((unsigned long long) 2LL * (unsigned long long) area(i + 1, (k + 1) % n) < S) {
            // printf("? %d %d -> %lld %lld\n", i, k, area(i + 1, (k + 1) % n), S);
            k = (k + 1) % n;
            dsm += (x[k] - x[i + 1]) * (y[k] + y[i + 1]);
            dsm %= mod;
            if (dsm < 0) {
                dsm += mod;
            }
        }
    }
    ans += mod;
    ans %= mod;
    printf("%lld\n", (long long) ans);
    return 0;
}