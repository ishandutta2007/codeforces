#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto merge(vector<int64_t> hs) {
    // (gain,need)
    vector<pair<int64_t, int64_t>> runs;
    int H = hs.size();
    int64_t gain = 0, need = 0;
    for (int i = 0; i < H; i++) {
        gain += hs[i];
        need = min(need, gain);
        if (gain >= 0) {
            runs.emplace_back(gain, -need);
            gain = need = 0;
        }
    }
    return make_pair(runs, -need);
}

void solve() {
    int N, K;
    cin >> N >> K, K--;
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int64_t> L(K), R(N - K - 1);
    for (int j = 0, i = K - 1; i >= 0; i--, j++) {
        L[j] = a[i];
    }
    for (int j = 0, i = K + 1; i < N; i++, j++) {
        R[j] = a[i];
    }
    int64_t H = a[K];
    auto [As, Aneed] = merge(L);
    auto [Bs, Bneed] = merge(R);
    reverse(begin(As), end(As));
    reverse(begin(Bs), end(Bs));
    while (true) {
        if (As.size() && H >= As.back().second) {
            H += As.back().first;
            As.pop_back();
        } else if (Bs.size() && H >= Bs.back().second) {
            H += Bs.back().first;
            Bs.pop_back();
        } else if (As.empty() && H >= Aneed) {
            cout << "YES\n";
            return;
        } else if (Bs.empty() && H >= Bneed) {
            cout << "YES\n";
            return;
        } else {
            cout << "NO\n";
            return;
        }
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