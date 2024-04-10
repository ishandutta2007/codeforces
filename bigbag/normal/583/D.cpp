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

const int max_n = 111, inf = 1111111111;

struct tree {
    int maxs[4 * 333];
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            maxs[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        maxs[v] = max(maxs[2 * v], maxs[2 * v + 1]);
    }
    int get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return maxs[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, t, a[max_n], last[333], sum[333];
tree dp1, dp2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(last, -1, sizeof(last));
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        last[a[i]] = i;
        ++sum[a[i]];
    }
    if (t < 1000) {
        dp1.update(1, 0, 300, a[0], 1);
        for (int i = 1; i < n * t; ++i) {
            dp1.update(1, 0, 300, a[i % n], dp1.get_max(1, 0, 300, 0, a[i % n]) + 1);
        }
        printf("%d\n", dp1.get_max(1, 0, 300, 0, 300));
        return 0;
    }
    dp1.update(1, 0, 300, a[0], 1);
    for (int i = 1; i < n * 111; ++i) {
        dp1.update(1, 0, 300, a[i % n], dp1.get_max(1, 0, 300, 0, a[i % n]) + 1);
    }
    int ans = 0;
    for (int x = 0; x <= 300; ++x) {
        if (last[x] != -1) {
            for (int j = 0; j <= 300; ++j) {
                dp2.update(1, 0, 300, j, -inf);
            }
            int cnt = t - 111 - 111;
            dp2.update(1, 0, 300, x, dp1.get_max(1, 0, 300, x, x) + cnt * sum[x]);
            for (int i = last[x] + 1; i < n * 112; ++i) {
                dp2.update(1, 0, 300, a[i % n], dp2.get_max(1, 0, 300, 0, a[i % n]) + 1);
            }
            ans = max(ans, dp2.get_max(1, 0, 300, 0, 300));
        }
    }
    printf("%d\n", ans);
    return 0;
}