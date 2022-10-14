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
    vector<vector<int>> cards(N, vector<int>(N));
    vector<vector<int>> pos(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int c;
            cin >> c, c--;
            cards[i][c]++;
        }
    }

    vector<vector<int>> ops;

    auto next = [N](int i) { return i + 1 == N ? 0 : i + 1; };
    auto prev = [N](int i) { return i == 0 ? N - 1 : i - 1; };

    while (true) {
        vector<int> act(N, -1);
        for (int i = 0; i < N; i++) {
            for (int c = 0; c < N; c++) {
                if (cards[i][c] >= 2) {
                    act[i] = c;
                    break;
                }
            }
        }
        int i = 0;
        while (i < N && act[i] == -1) {
            i++;
        }
        if (i == N) {
            break;
        }
        for (int j = i + 1; j != i; j = next(j)) {
            if (act[j] == -1) {
                act[j] = act[prev(j)];
            }
        }
        for (int j = 0; j < N; j++) {
            cards[j][act[j]]--;
            cards[j][act[prev(j)]]++;
        }
        assert(count(begin(act), end(act), -1) == 0);
        ops.push_back(move(act));
    }

    int K = ops.size();
    ops.insert(end(ops), N * (N - 1) / 2, vector<int>(N, -1));

    for (int i = 0; i < N; i++) {
        for (int k = K, c = next(i); c != i; c = next(c)) {
            for (int j = i; j != c; j = next(j), k++) {
                assert(ops[k][j] == -1);
                ops[k][j] = c;
            }
        }
    }

    K = ops.size();
    cout << K << '\n';
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < N; i++) {
            cout << ops[k][i] + 1 << " \n"[i + 1 == N];
        }
    }

    return 0;
}