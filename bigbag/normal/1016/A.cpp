#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, a[max_n];
long long cur;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        cur += a[i];
        printf("%d ", cur / m);
        cur %= m;
    }
    printf("\n");
    return 0;
}