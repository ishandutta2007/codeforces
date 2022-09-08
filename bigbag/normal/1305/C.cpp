#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    if (n > 1111) {
        puts("0");
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 0; j < i; ++j) {
            ans = 1LL * ans * abs(a[i] - a[j]) % m;
        }
    }
    printf("%d\n", ans);
    return 0;
}