#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, b[max_n], a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    a[0] = b[0];
    int x = 0;
    for (int i = 1; i < n; ++i) {
        x = max(x, a[i - 1]);
        a[i] = b[i] + x;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}