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
        string want;
        cin >> want;
        constexpr char NOT_LOSE = '1', WIN_ONE = '2';

        vector<int> winners;
        for (int i = 0; i < N; i++) {
            if (want[i] == WIN_ONE) {
                winners.push_back(i);
            }
        }

        int W = winners.size();
        if (W == 1 || W == 2) {
            cout << "NO\n";
            continue;
        }

        vector<string> ans(N, string(N, '='));
        for (int i = 0; i < N; i++) {
            ans[i][i] = 'X';
        }

        for (int s = 0; s < W; s++) {
            int i = winners[s], j = winners[(s + 1) % W];
            ans[i][j] = '+';
            ans[j][i] = '-';
        }

        cout << "YES\n";
        for (int i = 0; i < N; i++) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}