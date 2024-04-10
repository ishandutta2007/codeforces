#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a[max_n], b[max_n];

bool ok() {
    for (int i = 0; i < n; ++i) {
        if (b[i] < 0) {
            return false;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            int pos = i;
            while (pos < n && b[pos]) {
                if (b[pos] != b[i]) {
                    return false;
                }
                ++pos;
            }
            while (pos < n) {
                if (b[pos]) {
                    return false;
                }
                ++pos;
            }
            return true;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
            b[i] -= a[i];
        }
        if (ok()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}