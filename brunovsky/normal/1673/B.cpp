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
        string s;
        cin >> s;
        int N = s.size();
        constexpr int A = 26;
        vector<array<int, A>> trail(N + 1);
        vector<vector<int>> pos(A);
        for (int i = 0; i < N; i++) {
            int c = s[i] - 'a';
            trail[i + 1] = trail[i];
            trail[i + 1][c]++;
            pos[c].push_back(i);
        }
        bool bad = false;
        for (int c = 0; c < A; c++) {
            int S = pos[c].size();
            for (int i = 0; i + 1 < S; i++) {
                int a = pos[c][i];
                int b = pos[c][i + 1];
                for (int k = 0; k < A; k++) {
                    bad |= trail[N][k] > 0 && trail[b + 1][k] == trail[a][k];
                }
            }
        }
        cout << (bad ? "NO\n" : "YES\n");
    }
    return 0;
}