#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int extend(int n) {
    int ans = 0;
    for (int i = 0; i < 15; i++) {
        if (n >> i & 1) {
            ans |= 1 << (2 * i);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> gray(32);
    for (int i = 0; i < 32; i++) {
        gray[i] = i ^ (i >> 1);
    }
    int n, k;
    cin >> n >> k;
    vector<int> row(n - 1), col(n - 1);
    row[0] = col[0] = 1;
    for (int r = 1; r < n - 1; r++) {
        row[r] = col[r] = gray[r] ^ gray[r + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        row[i] = extend(row[i]);
        col[i] = extend(col[i]) << 1;
    }
    constexpr int B = 1 << 10;
    vector<array<int, 2>> where(B);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int x = 0;
            int pr = 0, pc = 0;
            while (pr != r) {
                x ^= col[pr++];
            }
            while (pc != c) {
                x ^= row[pc++];
            }
            where[x] = {r, c};
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n - 1; c++) {
            cout << row[c] << " \n"[c + 1 == n - 1];
        }
    }
    for (int r = 0; r < n - 1; r++) {
        for (int c = 0; c < n; c++) {
            cout << col[r] << " \n"[c + 1 == n];
        }
    }
    cout.flush();

    int x = 0;
    while (k--) {
        int y;
        cin >> y;
        x ^= y;
        auto [r, c] = where[x];
        cout << r + 1 << ' ' << c + 1 << endl;
    }

    return 0;
}

// Put a gray code upwards and downwards but use different bits?
// n=32 => 2n(n-1) roads = 1984 roads ~ max 24 on average per road, sounds enough
// well if he cycles then x must not cycle so every building has a different label
// 1024 labels then, wtf
// every other column has label 1
// of the remaining every other one has label 2, and so on