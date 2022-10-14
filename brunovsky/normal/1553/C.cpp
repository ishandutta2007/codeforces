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
        // first suppose A always scores and B never does
        int least = 10;
        for (int prefer : {0, 1}) {
            array<int, 2> score = {};
            for (int i = 0; i < 10; i++) {
                if (s[i] == '0') {
                    // ...
                } else if (s[i] == '1') {
                    score[i & 1]++;
                } else if ((i & 1) == prefer) {
                    score[i & 1]++;
                }
                array<int, 2> best = score;
                for (int j = i + 1; j < 10; j++) {
                    if ((j & 1) == prefer) {
                        // ...
                    } else {
                        best[j & 1]++;
                    }
                }
                if (best[prefer] > best[!prefer]) {
                    least = min(least, i + 1);
                }
                debug(score, best, i);
            }
        }
        debug(s);
        cout << least << '\n';
    }
    return 0;
}