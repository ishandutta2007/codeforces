/**
 *  created: 07/05/2021, 17:41:21
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

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
        int pos = min_element(a, a + n) - a;
        printf("%d\n", n - 1);
        for (int i = 0; i < n; ++i) {
            if (i == pos) {
                continue;
            }
            int value = a[pos] + abs(i - pos);
            printf("%d %d %d %d\n", pos + 1, i + 1, a[pos], value);
        }
    }
    return 0;
}