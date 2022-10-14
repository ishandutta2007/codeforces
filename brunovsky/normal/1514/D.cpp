#include <bits/stdc++.h>

using namespace std;

// *****

default_random_engine mt(random_device{}());
using intd = uniform_int_distribution<int>;

auto solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<vector<int>> pos(N + 1);
    for (int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r, l--;
        int len = r - l, M = (len + 1) / 2, ans;
        int k = 0;
        for (int i = 0; i < 40; i++) {
            int n = A[intd(l, r - 1)(mt)];
            auto lo = lower_bound(begin(pos[n]), end(pos[n]), l);
            auto hi = lower_bound(begin(pos[n]), end(pos[n]), r);
            k = hi - lo;
            if (k >= M)
                break;
        }
        ans = 2 * k - len;
        cout << max(ans, 1) << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}