#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 17, inf = 1011111111;

int n, k, a[6], cnt[6], f[max_n];

bool get_bit(int x, int pos) {
    return (bool) (x & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[j]);
            x *= 2;
            x += a[j];
        }
        f[x] = 1;
    }
    int mx = (1 << k);
    for (int i = 1; i < (1 << mx); ++i) {
        int ok = 1;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < mx; ++j) {
            if (get_bit(i, j) && (!f[j])) {
                ok = 0;
                break;
            }
        }
        int all = 0;
        for (int j = 0; j < mx; ++j) {
            if (get_bit(i, j)) {
                ++all;
                for (int q = 0; q < k; ++q) {
                    cnt[q] += get_bit(j, q);
                }
            }
        }
        for (int j = 0; j < k; ++j) {
            cnt[j] = all - cnt[j];
            if (2 * cnt[j] < all) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}