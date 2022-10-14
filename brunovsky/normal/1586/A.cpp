#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    constexpr int MAXS = 200 * 100;

    vector<bool> prime(MAXS + 1, true);
    for (int n = 2; n <= MAXS; n++) {
        for (int k = 2; n * k <= MAXS; k++) {
            prime[n * k] = false;
        }
    }
    prime[0] = prime[1] = false;

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        auto output = [&](set<int> bad) {
            int O = N - bad.size();
            cout << O << '\n';
            for (int i = 0, k = 0; i < N; i++) {
                if (!bad.count(i)) {
                    cout << i + 1 << " \n"[++k == O];
                }
            }
        };

        int sum = accumulate(begin(A), end(A), 0);
        if (!prime[sum]) {
            output({});
            goto next;
        }

        for (int i = 0; i < N; i++) {
            if (!prime[sum - A[i]]) {
                output({i});
                goto next;
            }
        }

        // don't think this is possible, one of the above will be even
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (!prime[sum - A[i] - A[j]]) {
                    output({i, j});
                    goto next;
                }
            }
        }

    next:;
    }
    return 0;
}