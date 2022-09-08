#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int mx = *max_element(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (i < n && a[i] == mx) {
            ++i;
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}