#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111111;

int n, a[max_n];

int main() {
    scanf("%d", &n);
    if (n % 2 == 0) {
        int cnt = 0;
        for (int i = 1; i <= n; i += 2) {
            a[cnt] = i;
            a[n - cnt - 1] = i;
            ++cnt;
        }
        cnt = n;
        for (int i = 2; i < n; i += 2) {
            a[cnt] = i;
            a[3 * n - cnt - 2] = i;
            ++cnt;
        }
        a[cnt] = n;
        a[2 * n - 1] = n;
    } else {
        int cnt = 0;
        for (int i = 1; i < n; i += 2) {
            a[cnt] = i;
            a[n - cnt - 1] = i;
            ++cnt;
        }
        cnt = n;
        for (int i = 2; i < n; i += 2) {
            a[cnt] = i;
            a[3 * n - cnt - 2] = i;
            ++cnt;
        }
        a[2 * n - 1] = n;
        a[n / 2] = n;
    }
    for (int i = 0; i < 2 * n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}