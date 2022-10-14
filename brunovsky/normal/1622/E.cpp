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
        int N, M;
        cin >> N >> M;
        vector<int> x(N);
        for (int i = 0; i < N; i++) {
            cin >> x[i];
        }

        vector<string> quest(N);
        for (int i = 0; i < N; i++) {
            cin >> quest[i];
        }

        int64_t ans = -1;
        vector<int> ans_index;

        // Bit 1: Consider x[i]-r[i]
        // Bit 0: COnsider r[i]-x[i]
        for (int above = 0; above < (1 << N); above++) {
            int64_t sum = 0;
            for (int i = 0; i < N; i++) {
                sum += (above >> i & 1) ? x[i] : -x[i];
            }

            vector<int> delta(M);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (quest[i][j] == '1') {
                        delta[j] += (above >> i & 1) ? -1 : +1;
                    }
                }
            }

            vector<int> index(M);
            iota(begin(index), end(index), 0);
            sort(begin(index), end(index),
                 [&](int i, int j) { return delta[i] < delta[j]; });

            // Maximize!
            for (int j = 0; j < M; j++) {
                sum += delta[index[j]] * (j + 1);
            }

            if (ans < sum) {
                ans = sum;
                ans_index = move(index);
            }
        }

        vector<int> p(M);
        for (int i = 0; i < M; i++) {
            p[ans_index[i]] = i + 1;
        }

        for (int i = 0; i < M; i++) {
            cout << p[i] << " \n"[i + 1 == M];
        }
    }
    return 0;
}