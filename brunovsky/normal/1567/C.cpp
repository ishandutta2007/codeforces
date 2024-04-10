#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        reverse(begin(s), end(s));
        int S = s.size();

        if (S == 1) {
            cout << stoll(s) - 1 << '\n';
            continue;
        }

        vector<int> ways(20);
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                ways[i + j]++;
            }
        }

        long ans = -2; // exclude (0,n) and (n,0)
        // suppose carries happen in the positions given in mask
        for (int mask = 0; mask < (1 << (S - 2)); mask++) {
            long mul = 1;
            for (int i = 0; i < S; i++) {
                int c = s[i] - '0';
                if (mask >> i & 1) {
                    // the sum here must be +10
                    c += 10;
                }
                if (i >= 2 && mask >> (i - 2) & 1) {
                    c -= 1;
                }
                if (c < 0 || c >= 19) {
                    mul = 0;
                    break;
                } else {
                    mul *= ways[c];
                }
            }
            ans += mul;
        }
        cout << ans << '\n';
    }
    return 0;
}