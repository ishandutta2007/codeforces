#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, x, a[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    if (*max_element(cnt, cnt + max_n) >= 2) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        --cnt[a[i]];
        if (cnt[a[i] & x]) {
            puts("1");
            return 0;
        }
        ++cnt[a[i]];
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i] & x];
    }
    if (*max_element(cnt, cnt + max_n) >= 2) {
        puts("2");
        return 0;
    }
    puts("-1");
    return 0;
}