#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", n);
        for (int i = 0; i < n; ++i) {
            printf("%d ", i + 1);
        }
        puts("");
    }
    return 0;
}