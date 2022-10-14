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
        string row_1, row_2;
        cin >> row_1 >> row_2;

        vector<int> table(N + 1);
        table[0] = -1;
        for (int i = 1; i <= N; i++) {
            if (row_1[i - 1] == '0' && row_2[i - 1] == '0') {
                table[i] = 0;
            } else if (row_1[i - 1] == '1' && row_2[i - 1] == '1') {
                table[i] = 1;
            } else {
                table[i] = 2;
            }
        }

        vector<bool> taken(N + 1);
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (table[i] == 0) {
                if (!taken[i - 1] && table[i - 1] == 1) {
                    ans += 2;
                    taken[i] = true;
                } else {
                    ans += 1;
                }
            } else if (table[i] == 1) {
                if (!taken[i - 1] && table[i - 1] == 0) {
                    ans += 1;
                    taken[i] = true;
                }
            } else {
                ans += 2;
                taken[i] = true;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}