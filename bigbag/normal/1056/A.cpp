#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, m, cnt[max_n], a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        while (m--) {
            int x;
            scanf("%d", &x);
            ++cnt[x];
        }
    }
    for (int i = 1; i < max_n; ++i) {
        if (cnt[i] == n) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}