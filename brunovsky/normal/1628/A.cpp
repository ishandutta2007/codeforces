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
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        vector<vector<int>> index(N + 1);
        for (int i = 0; i < N; i++) {
            index[a[i]].push_back(i);
        }

        auto get = [&](int x, int L) {
            auto i = lower_bound(begin(index[x]), end(index[x]), L) - begin(index[x]);
            int S = index[x].size();
            return i >= S ? -1 : index[x][i];
        };

        vector<int> b;
        int L = 0;
        while (L < N) {
            int x = 0, i = -1, R = L + 1;
            while (x < N && (i = get(x, L)) != -1) {
                x++, R = max(R, i + 1);
            }
            b.push_back(x);
            L = R;
        }

        int M = b.size();
        cout << M << '\n';
        for (int i = 0; i < M; i++) {
            cout << b[i] << " \n"[i + 1 == M];
        }
    }
    return 0;
}