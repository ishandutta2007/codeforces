#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], b[max_n], t[max_n];
int pos = -1;

void solve1() {
    if (pos == -1) {
        return;
    }
    for (int i = pos + 1; i < n; ++i) {
        if (b[i] != b[i - 1] + 1) {
            return;
        }
    }
    int x = b[n - 1] + 1;
    for (int i = 0; i < pos; ++i) {
        if (b[i] && b[i] <= x) {
            return;
        }
        ++x;
    }
    printf("%d\n", pos);
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        if (b[i] == 1) {
            pos = i;
        }
    }
    solve1();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            t[b[i]] = i + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, t[i] - i + 1);
    }
    printf("%d\n", ans + n);
    return 0;
}