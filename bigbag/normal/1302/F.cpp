#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n], pr[max_n], suf[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        pr[i] = a[i] | pr[i - 1];
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = a[i] | suf[i + 1];
    }
    int ans = -1, pos = 1;
    for (int i = 1; i <= n; ++i) {
        int x = pr[i - 1] | suf[i + 1];
        int val = a[i] - (a[i] & x);
        if (val > ans) {
            ans = val;
            pos = i;
        }
    }
    printf("%d ", a[pos]);
    for (int i = 1; i <= n; ++i) {
        if (i != pos) {
            printf("%d ", a[i]);
        }
    }
    puts("");
    return 0;
}