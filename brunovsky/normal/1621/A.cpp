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
        if (2 * K - 1 > N) {
            cout << -1 << '\n';
            continue;
        } else {
            vector<string> ans(N, string(N, '.'));
            for (int i = 0; i < K; i++) {
                ans[2 * i][2 * i] = 'R';
            }
            for (int i = 0; i < N; i++) {
                cout << ans[i] << "\n";
            }
        }
    }
    return 0;
}