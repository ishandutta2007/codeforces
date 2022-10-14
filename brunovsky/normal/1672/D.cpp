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
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }

        vector<int> left(N + 1);
        for (int i = 0; i < N; i++) {
            left[a[i]]++;
        }

        if (a[N - 1] != b[N - 1]) {
            cout << "NO" << '\n';
            continue;
        }

        vector<int> rems(N + 1);
        bool busted = false;
        int i = N - 2, j = N - 2;

        // debug("GO");

        while (i >= 0 && j >= 0) {
            if (a[i] == b[j]) {
                // debug("MATCH", i, j, a[i], b[j]);
                left[a[i]]--;
                i--, j--;
                continue;
            }
            if (b[j] != b[j + 1] && rems[a[i]] > 0) {
                // debug("REM", i, j, a[i], b[j]);
                rems[a[i]]--;
                i--;
                continue;
            }
            if (b[j] != b[j + 1]) {
                // debug("DIFF");
                busted = true;
                break;
            }
            if (b[j] == b[j + 1] && left[b[j]] == 0) {
                // debug("NONE");
                busted = true;
                break;
            }
            // debug("LEFT", i, j, a[i], b[j]);
            left[b[j]]--;
            rems[b[j]]++;
            j--;
        }

        busted |= j >= 0;
        cout << (busted ? "NO" : "YES") << '\n';
    }
    return 0;
}