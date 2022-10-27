#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), pos;
    int s = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (abs(a[i])) {
            s++;
            pos.push_back(i);
        }
    }
    if (s % 2) {
        cout << "-1\n";
        return;
    }
    debug(s, pos, a);
    if (s == 0) {
        cout << 1 << '\n';
        cout << 1 << ' ' << N << '\n';
        return;
    }
    int x = pos.front();
    int y = pos.back();
    vector<array<int, 2>> ans;
    if (x > 0) {
        ans.push_back({0, x - 1});
    }
    for (int i = 0; i < s; i += 2) {
        int z = pos[i];
        int w = pos[i + 1];
        int t = i + 2 == s ? w : pos[i + 2] - 1;
        if (a[z] == a[w] && z % 2 == w % 2) {
            ans.push_back({z, w - 2});
            ans.push_back({w - 1, t});
        } else if (a[z] == a[w] && z % 2 != w % 2) {
            ans.push_back({z, t});
        } else if (a[z] != a[w] && z % 2 == w % 2) {
            ans.push_back({z, t});
        } else {
            ans.push_back({z, w - 1});
            ans.push_back({w, t});
        }
    }
    if (y < N - 1) {
        ans.push_back({y + 1, N - 1});
    }
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}