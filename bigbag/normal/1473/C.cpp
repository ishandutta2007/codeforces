/**
 *  created: 14/01/2021, 17:10:27
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k; ++i) {
            a[i] = i;
        }
        reverse(a + 2 * k - 1 - n, a + k);
        for (int i = 0; i < k; ++i) {
            printf("%d ", a[i] + 1);
        }
        puts("");
    }
    return 0;
}