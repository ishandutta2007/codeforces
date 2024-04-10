#include <cstdio>
#include <cstring>

bool isp(int x) {
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int lp;
int pr[32];
int ld[30 << 20];

int go(int la, int k) {
    int u = la / k;

    if (k <= 72) {
        lp = 0;
        for (int i = 2; i < k; ++i) {
            if (isp(i)) {
                // printf("PR %d\n", i);
                pr[lp++] = i;
            }
        }
        long long tot = u;
        // printf("ST %d %d %lld\n", la, k, tot);
        for (int ma = 1; ma < (1 << lp); ++ma) {
            int si = __builtin_popcount(ma);
            if (si & 1) {
                si = -1;
            } else {
                si = 1;
            }
            long long pro = 1;
            for (int i = 0; i < lp; ++i) {
                if (ma & (1 <<i )) {
                    pro *= pr[i];
                }
            }
            pro = u / pro;
            // printf("CH %d -> %lld\n", ma, pro * si);
            tot += pro * si;
            // printf("RRS %lld\n", tot);
        }
        return (int) tot;
    } else {
        memset(ld, 0, sizeof(ld));
        int tot = 0;
        if (u > 0) {
            tot = 1;
        }
        for (int i = 2; i <= u; ++i) {
            if (i * i <= u || i == k) {
                if (!ld[i]) {
                    for (int j = i; j <= u; j += i) {
                        if (!ld[j]) {
                            ld[j] = i;
                        }
                    }
                }
            }
            if (ld[i] >= k || (!ld[i] && i >= k)) {
                ++tot;
            }
        }
        return tot;
    }
}

int main() {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    if (!isp(k)) {
        printf("0\n");
        return 0;
    }

    // printf("A %d B %d\n", go(a - 1, k), go(b, k));
    printf("%d\n", go(b, k) - go(a - 1, k));
    return 0;
}