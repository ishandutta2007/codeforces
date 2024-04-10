/**
 *  created: 30/05/2021, 17:41:03
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", 3 * n);
        for (int i = 0; i < n; i += 2) {
            for (int it = 0; it < 2; ++it) {
                printf("1 %d %d\n", i + 1, i + 2);
                printf("2 %d %d\n", i + 1, i + 2);
                printf("1 %d %d\n", i + 1, i + 2);
            }
        }
    }
    return 0;
}