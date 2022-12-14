#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, t;
int a[128];

int fo[128][128][2];
int ba[128][128][2];

int gof(int p, int s, int f) {
    if (fo[p][s][f] != -1) {
        return fo[p][s][f];
    }
    fo[p][s][f] = 1 - f;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= a[p]) {
            if (s > 0 && i >= p) {
                fo[p][s][f] = max(fo[p][s][f], 1-f + gof(i, s - 1, 0));
            } else if (i < p) {
                if (a[i] == a[p]) {
                    fo[p][s][f] = max(fo[p][s][f], 1-f + gof(i, s, f));
                } else {
                    fo[p][s][f] = max(fo[p][s][f], 1-f + gof(i, s, 0));
                }
            }
        }
    }
    return fo[p][s][f];
}

int gob(int p, int s, int f) {
    if (ba[p][s][f] != -1) {
        return ba[p][s][f];
    }
    ba[p][s][f] = 1 - f;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= a[p]) {
            if (s > 0 && i <= p) {
                ba[p][s][f] = max(ba[p][s][f], 1-f + gob(i, s - 1, 0));
            } else if (i > p) {
                if (a[i] == a[p]) {
                ba[p][s][f] = max(ba[p][s][f], 1-f + gob(i, s, f));
                } else {
                ba[p][s][f] = max(ba[p][s][f], 1-f + gob(i, s, 0));
                }
            }
        }
    }
    // printf("BA %d %d %d -> %d\n", p, s, f, ba[p][s][f]);
    return ba[p][s][f];
}


int main() {
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    memset(fo, -1, sizeof(fo));
    memset(ba, -1, sizeof(ba));
    int ans = 1;
    for (int v = 0; v < n; ++v) {
        int cn = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a[v]) {
                ++cn;
            }
        }
        for (int f = 0; f + 1 <= t && f < 110; ++f) {
            for (int b = 0; b + f + 1 <= t && b < 110; ++b) {
                int ne = cn * (t - 1 - f - b) + gof(v, f, 1)
                    + gob(v, b, 0);
                ans = max(ans, cn * (t - 1 - f - b) + gof(v, f, 1)
                            + gob(v, b, 0));
                // if (ans == ne) {
                //     printf("%d: %d %d %d\n", ne, v, f, b);
                //     printf("A %d %d\n", gof(v, f, 1), gob(v, b, 0));
                // }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}