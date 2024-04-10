#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int t, b, a[max_n], cnt[max_n];

void wa() {
    printf("-1\n");
    exit(0);
}

bool ok(int n, int m, int x, int y) {
    --x;
    --y;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int d = abs(x - i) + abs(y - j);
            ++cnt[d];
            if (cnt[d] > a[d]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
        b = max(b, x);
    }
    if (a[0] != 1) {
        wa();
    }
    int x;
    for (int i = 1; ; ++i) {
        if (a[i] != 4 * i) {
            x = i;
            break;
        }
    }
    for (int n = 1; n <= t; ++n) {
        if (t % n == 0) {
            int m = t / n;
            int y = n + m - x - b;
            if (ok(n, m, x, y)) {
                printf("%d %d\n%d %d\n", n, m, x, y);
                return 0;
            }
        }
    }
    wa();
    return 0;
}