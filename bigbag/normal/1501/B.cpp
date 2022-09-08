/**
 *  created: 25/03/2021, 18:59:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], add[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        fill(add, add + n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++add[max(i - a[i] + 1, 0)];
            --add[i + 1];
        }
        int x = 0;
        for (int i = 0; i < n; ++i) {
            x += add[i];
            printf("%d ", (int) (x > 0));
        }
        puts("");
    }
    return 0;
}