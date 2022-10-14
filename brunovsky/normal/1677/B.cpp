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
        string s;
        cin >> s;
        vector<int> ans(N * M);
        // First columns
        vector<int> col(M);
        int tot = 0;
        for (int i = 0; i < N * M; i++) {
            if (s[i] == '1') {
                tot += col[i % M]++ == 0;
            }
            ans[i] += tot;
        }
        // Now rows
        vector<int> row(M);
        for (int r = 0; r < N; r++) {
            vector<int> mom(M + 1);
            for (int c = -M + 1; c < 0 && r > 0; c++) {
                if (s[r * M + c] == '1') {
                    mom[0]++, mom[M + c]--;
                }
            }
            for (int c = 0; c < M; c++) {
                if (s[r * M + c] == '1') {
                    mom[c]++, mom[M]--;
                }
            }
            for (int c = 0; c < M; c++) {
                mom[c + 1] += mom[c];
                row[c] += mom[c] > 0;
            }
            for (int c = 0; c < M; c++) {
                int i = r * M + c;
                ans[i] += row[c];
            }
        }
        for (int i = 0; i < N * M; i++) {
            cout << ans[i] << " \n"[i + 1 == N * M];
        }
    }
    return 0;
}