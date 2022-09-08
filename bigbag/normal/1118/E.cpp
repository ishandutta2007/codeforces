#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    if (n > 1LL * k * (k - 1)) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 2; i <= k; ++i) {
        int st = i;
        for (int j = 1; j <= k && n; ++j) {
            --n;
            printf("%d %d\n", j, st);
            ++st;
            if (st > k) {
                st = 1;
            }
        }
    }
    return 0;
}