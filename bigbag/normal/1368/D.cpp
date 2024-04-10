#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], x[max_n];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int b = 0; b < 20; ++b) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += get_bit(a[i], b);
        }
        for (int i = 0; i < cnt; ++i) {
            x[i] += (1 << b);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += 1LL * x[i] * x[i];
    }
    cout << ans << "\n";
    return 0;
}