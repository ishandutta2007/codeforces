#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int n, mod, a[max_n], b[max_n], c[max_n];

bool check(int x) {
    for (int i = 0; i < n; ++i) {
        c[i] = (a[i] + x) % mod;
    }
    sort(c, c + n);
    for (int i = 0; i < n; ++i) {
        if (c[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> mod;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int ans = mod;
    for (int i = 0; i < n; ++i) {
        int x = (b[i] + mod - a[0]) % mod;
        if (check(x)) {
            ans = min(ans, x);
        }
    }
    cout << ans << "\n";
    return 0;
}