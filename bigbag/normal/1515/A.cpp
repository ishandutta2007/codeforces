/**
 *  created: 02/05/2021, 17:37:35
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if (accumulate(a, a + n, 0) == x) {
            puts("NO");
        } else {
            puts("YES");
            sort(a, a + n);
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += a[i];
                if (sum == x) {
                    assert(i != i + 1);
                    swap(a[i], a[i + 1]);
                    break;
                }
            }
            for (int i = 0; i < n; ++i) {
                printf("%d ", a[i]);
            }
            puts("");
        }
    }
    return 0;
}