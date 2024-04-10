#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int n;
long long x, y, ans;
char a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') {
            ++x;
            if (b[i] == '0') {
                ++y;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            if (b[i] == '0') {
                ans += x;
            } else {
                ans += y;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}