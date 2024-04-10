#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

#define tail(k) ((N - k - 1) >= 63 ? INT64_MAX : (long(1) << (N - k - 1)))

auto solve() {
    int N;
    long K;
    cin >> N >> K, K--;
    vector<int> ans(N);
    iota(begin(ans), end(ans), 1);
    for (int n = 1; n < N && K; n++) {
        if (tail(n) > K)
            continue;

        int start = n;
        K -= tail(n), n++;
        while (n < N && tail(n) <= K) {
            K -= tail(n), n++;
        }
        for (int i = start; i <= n; i++) {
            ans[i - 1] = n - i + start;
        }
    }
    if (K > 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < N; i++) {
            cout << (i ? " " : "") << ans[i];
        }
        cout << endl;
    }
}

// *****

int main() {
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}