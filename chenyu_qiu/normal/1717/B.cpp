#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    --r;
    --c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ".X"[(j - i + n) % k == (c - r + n) % k];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}