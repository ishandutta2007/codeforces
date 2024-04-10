#include <cstdio>
#include <cstring>

int n, m;
int a[1024];
double prs[1024][1024];

int main() {
    memset(prs, 0, sizeof(prs));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] < a[j]) {
                prs[i][j] = 1.0;
            } else {
                prs[i][j] = 0.0;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l; --r;
        for (int j = 0; j < n; ++j) {
            if (j == l || j == r) {
                continue;
            }
            double jsm = 0.5 * (prs[j][l] + prs[j][r]);
            prs[j][l] = prs[j][r] = jsm;
            prs[l][j] = prs[r][j] = 1.0 - jsm;
        }
        prs[l][r] = prs[r][l] = 0.5;
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ans += prs[i][j];
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}