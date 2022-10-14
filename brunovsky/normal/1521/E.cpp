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
        int M, K;
        cin >> M >> K;
        vector<int> a(K);
        for (int i = 0; i < K; i++) {
            cin >> a[i];
        }

        vector<int> index(K);
        iota(begin(index), end(index), 0);
        sort(begin(index), end(index), [&](int i, int j) { return a[i] > a[j]; });

        const int A = a[index[0]];

        // Find smallest solution with odd n
        // n must satisfy: (3n^2+2n-1)/4>=M and n((n+1)/2)>=A
        int n = 1;
        while (3 * n * n + 2 * n - 1 < 4 * M)
            n += 2;
        while (n * ((n + 1) / 2) < A)
            n += 2;

        // Does even n-1 work? 3n^2/4>=M and n^2/2>=A
        n--;
        if (n == 0 || 3 * n * n < 4 * M || n * n / 2 < A)
            n++;

        vector<vector<int>> mat(n, vector<int>(n));
        vector<array<int, 2>> positions;
        for (int r = 0; r < n; r += 2) {
            for (int c = 1; c < n; c += 2) {
                positions.push_back({r, c});
            }
        } // hack: different order
        for (int r = 0; r < n; r += 2) {
            for (int c = 0; c < n; c += 2) {
                positions.push_back({r, c});
            }
        }
        for (int r = 1; r < n; r += 2) {
            for (int c = 0; c < n; c += 2) {
                positions.push_back({r, c});
            }
        }
        assert(int(positions.size()) >= M);

        for (int i = 0, m = 0; i < K; i++) {
            for (int x = 0; x < a[index[i]]; x++, m++) {
                auto [r, c] = positions[m];
                mat[r][c] = index[i] + 1;
            }
        }

        cout << n << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " \n"[j + 1 == n];
            }
        }
    }
    return 0;
}