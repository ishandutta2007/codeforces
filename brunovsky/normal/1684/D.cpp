#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        vector<int> order(N);
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order), [&](int i, int j) { return a[i] + i > a[j] + j; });
        set<int> jump(begin(order), begin(order) + K);
        int J = 0;
        int64_t ans = 0;
        for (int i = 0; i < N; i++) {
            if (jump.count(i)) {
                J++;
            } else {
                ans += a[i] + J;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}