#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

int n, k;
int a[1 << 20];
int sg[1 << 20];

int mp(int k) {
    if (k % 2 == 1) {
        return 0;
    }
    return 1 + mp(k / 2);
}

int main() {
    scanf("%d %d", &n, &k);
    k %= 2;
    sg[0] = 0;
    sg[1] = 1;
    bool vis[64];
    for (int i = 2; i < 1000000; ++i) {
        memset(vis, 0, sizeof(vis));
        if (i % 2 == 0) {
            if (k % 2 == 0) {
                vis[0] = 1;
            } else {
                vis[sg[i / 2]] = 1;
            }
        }
        vis[sg[i - 1]] = 1;
        for (int j = 0; j <= 4; ++j) {
            if (!vis[j]) {
                sg[i] = j;
                break;
            }
        }
    }

    set<int> special;
    long long b = 24;
    while (b <= 1000000000) {
        special.insert(b);
        b *= 4LL;
    }

    // // return 0;
    // for (int i = 0; i < n; ++i) {
    //     // if (sg[i] == 0 && (i % 2) == 0) {
    //     //     printf("ANOM %d %d\n", i, sg[i]);
    //     // }
    //     // if (sg[i] == 1 && (i % 2) == 1) {
    //     //     printf("AAAA %d %d\n", i, sg[i]);
    //     // }
    //     // printf("A %d %d\n", i, sg[i]);
    // }
    // for (int i = 0; i < n; ++i) {
    //     // if (sg[i] == 0 && (i % 2) == 0) {
    //     //     printf("ANOM %d %d\n", i, sg[i]);
    //     // } else if (sg[i] == 1 && (i % 2) == 1) {
    //     //     printf("AAAA %d %d\n", i, sg[i]);
    //     // }
    //     // All odd are 0
    //     if (sg[i] == 0) {
    //         // printf("A %d %d\n", i, sg[i]);
    //     }
    //     if (sg[i] == 2) {
    //         if (mp(i) % 2 == 1) {
    //             printf("A %d %d %d\n", i, sg[i], mp(i));
    //         }
    //     }
    // }
    int x = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < 1000000) {
            x ^= sg[a[i]];
        } else {
            if (k % 2 == 0) {
                if (a[i] % 2 == 0) {
                    x ^= 1;
                }
            } else {
                if (a[i] % 2 == 1) {
                    continue;
                }
                if (special.find(a[i]) != special.end()) {
                    x ^= 2;
                } else if (mp(a[i]) % 2 == 0) {
                    x ^= 2;
                } else {
                    x ^= 1;
                }
            }
        }
    }
    if (x) {
        printf("Kevin\n");
    } else {
        printf("Nicky\n");
    }
    return 0;
}