#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) {
            a[i] = -a[i] - 1;
        }
    }
    if (n % 2) {
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < a[pos]) {
                pos = i;
            }
        }
        a[pos] = -a[pos] - 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}