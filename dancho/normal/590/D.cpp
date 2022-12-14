#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k, s;

int q[155];

int dpr[155][12000];
int dpl[155][12000];

int main() {
    scanf("%d %d %d", &n, &k, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }
    memset(dpr, 63, sizeof(dpr));
    dpr[0][0] = 0;
    // for (int u = 0; u <= n; ++u) {
    //     dpr[u][0] = 0;
    // }
    for (int i = k; i < n; ++i) {
        for (int u = i - k + 1; u > 0; --u) {
            for (int sm = 11500; sm >= i; --sm) {
                dpr[u][sm] = min(dpr[u][sm], dpr[u - 1][sm - i] + q[i]);
                // if (dpr[u][sm] < 500) {
                //     printf("DPR %d %d -> %d\n", u, sm, dpr[u][sm]);
                // }
            }
        }
    }
    memset(dpl, 128, sizeof(dpl));
    dpl[0][0] = 0;
    // for (int u = 0; u <= n; ++u) {
    //     dpl[u][0] = 0;
    // }
    int S = 0;
    for (int i = 0; i < k; ++i) {
        S += q[i];
        for (int u = i + 1; u > 0; --u) {
            for (int sm = 11500; sm >= i; --sm) {
                // printf("H %d %d %d\n", i, u, sm);
                dpl[u][sm] = max(dpl[u][sm], dpl[u - 1][sm - i] + q[i]);
            }
        }
    }
    
    for (int u = 1; u < 153; ++u) {
        for (int i = 1; i < 11500; ++i) {
            dpr[u][i] = min(dpr[u][i], dpr[u][i - 1]);
        }
    }

    long long bch = 0;
    for (int u = 1; u < 153; ++u) {
        for (int sl = 0; sl < 11500; ++sl) {
            bch = min(bch, (long long) dpr[u][min(11400, s + sl)] - (long long) dpl[u][sl]);
        }
    }
    printf("%d\n", S + (int) bch);
    return 0;
}