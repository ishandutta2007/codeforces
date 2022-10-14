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
        int N, A, B;
        cin >> N >> A >> B;
        if (abs(A - B) >= 2 || A + B > N - 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans(N);
        if (A == B + 1) {
            // one more up peak
            for (int i = 0; i < A; i++) {
                ans[2 * i] = i + 1;
                ans[2 * i + 1] = N - i;
            }
            for (int i = 2 * A; i < N; i++) {
                ans[i] = N - i + A;
            }
        } else if (A == B) {
            for (int i = 0; i < A; i++) {
                ans[2 * i] = i + 1;
                ans[2 * i + 1] = N - i;
            }
            for (int i = 2 * A; i < N; i++) {
                ans[i] = i - A + 1;
            }
        } else if (A == B - 1) {
            // one more down peak
            for (int i = 0; i < B; i++) {
                ans[2 * i] = N - i;
                ans[2 * i + 1] = i + 1;
            }
            for (int i = 2 * B; i < N; i++) {
                ans[i] = i - B + 1;
            }
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}