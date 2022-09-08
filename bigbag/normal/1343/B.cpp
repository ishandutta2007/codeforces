#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if ((n % 4) == 2) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 0; i < n / 4; ++i) {
                printf("%d %d ", 12 * i + 2, 12 * i + 10);
            }
            for (int i = 0; i < n / 4; ++i) {
                printf("%d %d ", 12 * i + 3, 12 * i + 9);
            }
            puts("");
        }
    }
    return 0;
}