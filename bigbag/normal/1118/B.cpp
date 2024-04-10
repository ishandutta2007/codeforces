#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], sum[2][max_n];

int get_sum(int tp, int l, int r) {
    if (l == 0) {
        return sum[tp][r];
    }
    return sum[tp][r] - sum[tp][l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[i % 2][i] = a[i];
        if (i) {
            sum[0][i] += sum[0][i - 1];
            sum[1][i] += sum[1][i - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        if (i) {
            x = sum[0][i - 1];
            y = sum[1][i - 1];
        }
        int f = i % 2;
        x += get_sum(1, i + 1, n - 1);
        y += get_sum(0, i + 1, n - 1);
        if (x == y) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}