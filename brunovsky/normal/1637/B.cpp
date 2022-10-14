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
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int64_t ans = 0;
        for (int l = 0; l < N; l++) {
            for (int r = l + 1; r <= N; r++) {
                int zeros = count(begin(A) + l, begin(A) + r, 0);
                ans += (r - l + zeros);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}