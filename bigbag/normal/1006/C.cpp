#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n];
long long x, y, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    ans = 0;
    int pos = n - 1;
    for (int i = 0; i < n; ++i) {
        x += a[i];
        while (pos > i && y < x) {
            y += a[pos];
            --pos;
        }
        if (x == y) {
            ans = x;
        }
    }
    cout << ans << "\n";
    return 0;
}