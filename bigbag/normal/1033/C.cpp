#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n], pos[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    for (int x = n; x >= 1; --x) {
        for (int i = pos[x] % x; i < n; i += x) {
            if (dp[i] == 0 && x < a[i]) {
                dp[pos[x]] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i]) {
            printf("A");
        } else {
            printf("B");
        }
    }
    printf("\n");
    return 0;
}