#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, cnt[max_n], p[max_n], is_leaf[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        is_leaf[i] = true;
    }
    for (int i = 1; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
        is_leaf[p[i]] = false;
    }
    for (int i = 0; i < n; ++i) {
        if (is_leaf[i]) {
            cnt[i] = 1;
        }
    }
    for (int i = n - 1; i > 0; --i) {
        cnt[p[i]] += cnt[i];
    }
    sort(cnt, cnt + n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", cnt[i]);
    }
    return 0;
}