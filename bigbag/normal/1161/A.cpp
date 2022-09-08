#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int n, k, ans, first[max_n], last[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    memset(first, -1, sizeof(first));
    memset(last, -1, sizeof(last));
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        if (first[x] == -1) {
            first[x] = i;
        }
        last[x] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = max(1, i - 1); j <= min(i + 1, n); ++j) {
            if (first[i] == -1 || last[j] < first[i]) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}