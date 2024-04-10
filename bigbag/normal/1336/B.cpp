#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111;
const long long inf = 9000111222000111222LL;

int t, n[3], a[3][max_n], x[3];

long long sqr(int x) {
    return 1LL * x * x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n[0], &n[1], &n[2]);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n[i]; ++j) {
                scanf("%d", &a[i][j]);
            }
            sort(a[i], a[i] + n[i]);
        }
        long long ans = inf;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n[i]; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i == k) {
                        continue;
                    }
                    int t = 3 ^ i ^ k;
                    x[i] = a[i][j];
                    x[k] = lower_bound(a[k], a[k] + n[k], a[i][j]) - a[k];
                    if (x[k] == n[k]) {
                        --x[k];
                    }
                    x[t] = upper_bound(a[t], a[t] + n[t], a[i][j]) - a[t] - 1;
                    if (x[t] < 0) {
                        ++x[t];
                    }
                    x[k] = a[k][x[k]];
                    x[t] = a[t][x[t]];
                    long long res = sqr(x[0] - x[1]) + sqr(x[0] - x[2]) + sqr(x[1] - x[2]);
                    ans = min(ans, res);
                }
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}