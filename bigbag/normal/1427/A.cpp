#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int t, n, a[max_n];

bool check() {
    int x = 0;
    for (int i = 0; i < n; ++i) {
        x += a[i];
        if (!x) {
            return false;
        }
    }
    return true;
}

void write() {
    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
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
        sort(a, a + n);
        if (check()) {
            write();
        } else {
            reverse(a, a + n);
            if (check()) {
                write();
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}