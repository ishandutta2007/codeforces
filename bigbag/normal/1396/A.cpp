#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n;
long long a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    if (n == 1) {
        puts("1 1");
        printf("%d\n", -a[0]);
        puts("1 1");
        puts("0");
        puts("1 1");
        puts("0");
        return 0;
    }
    printf("1 %d\n", n);
    const int m = n - 1;
    for (int i = 0; i < n; ++i) {
        int x = ((a[i] % m) + m) % m;
        int k = (m - x) % m;
        a[i] += 1LL * k * n;
        printf("%I64d ", 1LL * k * n);
    }
    puts("");
    puts("1 1");
    printf("%I64d\n", -a[0]);
    printf("2 %d\n", n);
    for (int i = 1; i < n; ++i) {
        assert(a[i] % m == 0);
        printf("%I64d ", -a[i]);
    }
    puts("");
    return 0;
}