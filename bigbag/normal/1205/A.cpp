#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    if (n % 2 == 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    a[0] = 1;
    for (int i = 1; i < n; i += 2) {
        a[i] = a[i - 1] + 3;
        a[i + 1] = a[i] + 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (i % 2 == 0) {
            ++x;
        } else {
            --x;
        }
        printf("%d ", x);
    }
    return 0;
}