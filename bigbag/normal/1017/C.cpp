#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int n, ans = inf, cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x = i + (n + i - 1) / i;
        if (x < ans) {
            ans = x;
            cnt = i;
        }
    }
    int cur = n - cnt + 1;
    int x = (n + cnt - 1) / cnt;
    while (x--) {
        int to = cur + cnt;
        int nxt = cur - cnt;
        cur = max(cur, 1);
        while (cur < to) {
            printf("%d ", cur);
            ++cur;
        }
        cur = nxt;
    }
    printf("\n");
    return 0;
}