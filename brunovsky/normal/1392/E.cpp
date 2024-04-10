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
    vector<vector<int64_t>> a(N, vector<int64_t>(N));
    // b[i][j]: smallest possible sum from (i,j) to (N-1,N-1)
    vector<vector<int64_t>> b(N, vector<int64_t>(N));
    // c[i][j]: largest possible sum from (i,j) to (N-1,N-1), including (i,j)
    vector<vector<int64_t>> c(N, vector<int64_t>(N));
    for (int j = N - 2; j >= 0; j--) {
        for (int i = N - 1; i >= 1; i--) {
            a[i][j] = 1 + c[i - 1][j + 1] - a[i - 1][j + 1];
            b[i][j] = a[i][j] + b[i][j + 1];
            c[i][j] = a[i][j] + (i == N - 1 ? c[i][j + 1] : c[i + 1][j]);
        }
        c[0][j] = c[1][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " \n"[j + 1 == N];
        }
    }
    cout.flush();
    int Q;
    cin >> Q;
    while (Q--) {
#ifdef LOCAL
        int64_t k = 0;
        vector<array<int, 2>> solution;
        {
            int x = 0, y = 0;
            static bernoulli_distribution coin(0.5);
            static mt19937 mt(random_device{}());
            while (x < N - 1 && y < N - 1) {
                k += a[x][y];
                solution.push_back({x, y});
                if (coin(mt)) {
                    x++;
                } else {
                    y++;
                }
            }
            while (x < N - 1) {
                k += a[x][y];
                solution.push_back({x, y});
                x++;
            }
            while (y < N - 1) {
                k += a[x][y];
                solution.push_back({x, y});
                y++;
            }
        }
#else
        int64_t k;
        cin >> k;
#endif
        vector<array<int, 2>> positions;
        int x = 0, y = 0;
        while (x < N - 1 && y < N - 1) {
            k -= a[x][y];
            if (c[x][y + 1] < k) {
                positions.push_back({x++, y});
            } else {
                positions.push_back({x, y++});
            }
        }
        while (x < N - 1) {
            k -= a[x][y];
            positions.push_back({x++, y});
        }
        while (y < N - 1) {
            k -= a[x][y];
            positions.push_back({x, y++});
        }
        assert(k == 0);
        assert(x == N - 1);
        assert(y == N - 1);
#ifdef LOCAL
        assert(solution == positions);
#endif
        positions.push_back({x, y});
        for (int i = 0; i < 2 * N - 1; i++) {
            auto [r, c] = positions[i];
            cout << r + 1 << ' ' << c + 1 << endl;
        }
    }
    return 0;
}