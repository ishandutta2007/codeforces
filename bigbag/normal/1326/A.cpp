#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 1) {
            puts("-1");
        } else {
            for (int i = 0; i + 2 < n; ++i) {
                printf("2");
            }
            if (n % 9 == 1) {
                printf("5");
            } else {
                printf("2");
            }
            puts("9");
        }
    }
    return 0;
}