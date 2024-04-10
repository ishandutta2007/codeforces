#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, ans;
char a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] != a[i + 1] && a[i] != b[i] && a[i + 1] != b[i + 1]) {
            swap(a[i], a[i + 1]);
            ++ans;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}