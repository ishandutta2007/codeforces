#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int MAX = 300'000;
    vector<int> sum(MAX + 1);
    for (int i = 1; i <= MAX; i++) {
        sum[i] = sum[i - 1] ^ i;
    }
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (sum[a - 1] == b) {
            cout << a << '\n';
        } else if ((sum[a - 1] ^ b) != a) {
            cout << a + 1 << '\n';
        } else {
            cout << a + 2 << '\n';
        }
    }
    return 0;
}