#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, q;
int a[100020];
int dep[100020];
int lt[1 << 18];
int big[100020][18];

int qbig(int s, int t) {
    if (s > t) {
        swap(s, t);
    }
    int le = t - s + 1;
    int ln = lt[le];
    int k = t + 1 - (1 << ln);
    // printf("%d %d %d : %d %d\n", s, k, ln, big[s][ln], big[k][ln]);
    // fflush(stdout);
    if (dep[ big[s][ln] ] > dep[ big[k][ln] ]) {
        return big[s][ln];
    } else {
        return big[k][ln];
    }
}

void precalc() {
    lt[0] = 0;
    for (int i = 1; i < 18; ++i) {
        lt[1 << i] = i;
    }
    for (int i = 1; i < (1 << 18); ++i) {
        lt[i] = max(lt[i - 1], lt[i]);
    }
    memset(big, -1, sizeof(big));
    for (int i = 0; i + 1 < n; ++i) {
        int ni = i;
        big[ni][0] = i;
        // if (big[ni][0] == -1 || dep[big[ni][0]] > dep[tour[i]]) {
        //     big[ni][0] = tour[i];
        // }
    }
    // int mxi = (int) tour.size() / lim;
    for (int st = 1; st < 18; ++st) {
        for (int i = 0; i + (1 << st) <= n - 1; ++i) {
            int ne = i + (1 << (st - 1));
            if (dep[ big[i][st - 1] ] > dep[big[ne][st - 1]]) {
                big[i][st] = big[i][st - 1];
            } else {
                big[i][st] = big[ne][st - 1];
            }
        }
    }
}

long long sm;

void solve(int l, int r) {
    if (l > r) {
        return;
    }
    int m = qbig(l, r);
    // printf("QQ %d %d -> %d %lld\n", l, r, m, sm);
    sm += (long long) dep[m] * (long long) (m - l + 1) * (long long) (r - m + 1);
    // printf("QQ %d %d -> %d %lld\n", l, r, m, sm);
    solve(l, m - 1);
    solve(m + 1, r);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        dep[i] = a[i + 1] - a[i];
        if (dep[i] < 0) {
            dep[i] = -dep[i];
        }
        // printf("DEP %d %d\n", i, dep[i]);
    }

    precalc();
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l == r) {
            printf("0\n");
            continue;
        }

        sm = 0;
        --l;
        --r;
        --r;
        solve(l, r);
        printf("%lld\n", sm);
    }
    return 0;
}