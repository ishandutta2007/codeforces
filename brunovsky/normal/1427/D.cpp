#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i], c[i]--;
    }
    vector<vector<int>> ans;
    auto run_op = [&](vector<int> op) {
        vector<int> filt;
        for (int S : op) {
            if (S > 0) {
                filt.push_back(S);
            }
        }
        swap(filt, op);
        ans.push_back(op);
        vector<int> d;
        int M = N;
        reverse(begin(op), end(op));
        for (int S : op) {
            for (int i = M - S; i < M; i++) {
                d.push_back(c[i]);
            }
            M -= S;
        }
        swap(c, d);
    };
    while (!is_sorted(begin(c), end(c))) {
        vector<int> where(N);
        for (int i = 0; i < N; i++) {
            where[c[i]] = i;
        }
        vector<int> index = {0, N};
        for (int n = 0; n < N; n++) {
            if (n == N - 1) {
                index.push_back(where[n] + 1);
            } else if (where[n + 1] < where[n]) {
                index.push_back(where[n] + 1);
                index.push_back(where[n + 1]);
                int j = where[n + 1];
                while (c[j + 1] == c[j] + 1) {
                    j++;
                }
                index.push_back(j + 1);
                break;
            }
        }
        sort(begin(index), end(index));
        index.erase(unique(begin(index), end(index)), end(index));
        vector<int> op;
        int S = index.size();
        for (int i = 1; i < S; i++) {
            op.push_back(index[i] - index[i - 1]);
        }
        run_op(op);
        debug(c);
    }
    int S = ans.size();
    cout << S << '\n';
    for (int i = 0; i < S; i++) {
        int K = ans[i].size();
        cout << K << ' ';
        for (int j = 0; j < K; j++) {
            cout << ans[i][j] << " \n"[j + 1 == K];
        }
    }
    return 0;
}