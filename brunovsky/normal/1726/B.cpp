#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void output(const vector<int>& a) {
    cout << "Yes\n";
    for (int n = a.size(), i = 0; i < n; i++) {
        cout << a[i] << " \n"[i + 1 == n];
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N, 1);
    if (N > M) {
        cout << "No\n";
    } else if (N == M) {
        output(a);
    } else if (N % 2 == 0 && M % 2 == 1) {
        cout << "No\n";
    } else if (N % 2 == 1) {
        M -= N;
        a[0] = 1 + M;
        output(a);
    } else {
        M -= N;
        a[0] = 1 + M / 2;
        a[1] = 1 + M / 2;
        output(a);
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