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

const int max_n = 100111, max_x = 1033, inf = 1011111111;

int n, k, x, cnt[2][max_x];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &x);
    int q1 = 0, q2 = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ++cnt[q1][a];
    }
    for (int i = 0; i < k; ++i) {
        memset(cnt[q2], 0, sizeof(cnt[q2]));
        int pos = 0;
        for (int j = 0; j < max_x; ++j) {
            int a = cnt[q1][j] / 2;
            int b = cnt[q1][j] - a;
            if ((pos & 1) == 0) {
                swap(a, b);
            }
            cnt[q2][j] += b;
            cnt[q2][j ^ x] += a;
            pos += cnt[q1][j];
        }
        swap(q1, q2);
    }
    int mn = inf, mx = -inf;
    for (int i = 0; i < max_x; ++i) {
        if (cnt[q1][i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    printf("%d %d\n", mx, mn);
    return 0;
}