#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto diffs(const string& a, const string& b) {
    int a11 = 0, a10 = 0, a01 = 0, a00 = 0;
    for (int i = 0, N = a.size(); i < N; i++) {
        a11 += a[i] == '1' && b[i] == '1';
        a10 += a[i] == '1' && b[i] == '0';
        a01 += a[i] == '0' && b[i] == '1';
        a00 += a[i] == '0' && b[i] == '0';
    }
    return make_tuple(a11, a10, a01, a00);
}

const int inf = INT_MAX / 2;

int solve(int a11, int a10, int a01, int a00) {
    if (a11 < 0 || a10 < 0 || a01 < 0 || a00 < 0) {
        return inf;
    } else if (a10 == 0 && a01 == 0) {
        return 0;
    } else if (a10 != a01) {
        return inf;
    } else {
        return 2 * a10;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string a, b;
        cin >> a >> b;
        auto [a11, a10, a01, a00] = diffs(a, b);

        int ans = solve(a11, a10, a01, a00);
        ans = min(ans, 1 + solve(1 + a01, a00, a11 - 1, a10));
        ans = min(ans, 1 + solve(a01, 1 + a00, a11, a10 - 1));
        cout << (ans >= inf ? -1 : ans) << '\n';
    }
    return 0;
}