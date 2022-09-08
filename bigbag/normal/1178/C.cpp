#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, mod = 998244353;

int n, m, ans = 1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        ans = (2LL * ans) % mod;
    }
    cout << ans << endl;
    return 0;
}