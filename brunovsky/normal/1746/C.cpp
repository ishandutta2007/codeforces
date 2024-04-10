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
    vector<int> a(N), pos(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<int> op(N + 1);
    for (int v = 1; v <= N; v++) {
        if (pos[v] == N - 1) {
            op[v] = 0;
        } else {
            op[v] = pos[v] + 1;
        }
    }
    for (int v = 1; v <= N; v++) {
        cout << op[v] + 1 << " \n"[v == N];
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