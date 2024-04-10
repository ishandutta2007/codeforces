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
        set<int> colors;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            colors.insert(a[i]);
        }

        a.erase(unique(begin(a), end(a)), end(a));
        int S = a.size(); // shrink

        vector<vector<int>> by_color(N + 1);
        vector<int> index(S);
        for (int i = 0; i < S; i++) {
            index[i] = by_color[a[i]].size();
            by_color[a[i]].push_back(i);
        }

        vector<vector<int>> score(S, vector<int>(S + 1));
        for (int len = 2; len <= S; len++) {
            for (int l = 0, r = l + len; r <= S; l++, r++) {
                int c = a[l];
                int I = by_color[c].size();
                score[l][r] = score[l + 1][r];
                for (int k = index[l] + 1; k < I && by_color[c][k] < r; k++) {
                    int m = by_color[c][k];
                    score[l][r] = max(score[l][r], 1 + score[l + 1][m] + score[m][r]);
                }
            }
        }

        cout << S - 1 - score[0][S] << '\n';
    }
    return 0;
}

// Try every color brute force (any that appears anyway)
// Maximize count of color + count of unions