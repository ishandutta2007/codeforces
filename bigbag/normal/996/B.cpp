#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];
int ans = inf, num;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int k = (a[i] - i + n - 1) / n;
        int x = k * n + i;
        if (x < ans) {
            ans = x;
            num = i + 1;
        }
    }
    printf("%d\n", num);
    return 0;
}