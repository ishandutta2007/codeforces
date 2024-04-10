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
        int N, Q;
        cin >> N >> Q;
        string input;
        cin >> input;

        vector<int> charge(N + 1);
        vector<int> who[2];

        for (int i = 1; i <= N; i++) {
            if (input[i - 1] == '+') {
                charge[i] = (i & 1) ? +1 : -1;
            } else {
                charge[i] = (i & 1) ? -1 : +1;
            }
            if (charge[i] == +1) {
                who[1].push_back(i);
            } else {
                who[0].push_back(i);
            }
        }
        debug(charge);

        vector<int> sum(N + 1);
        for (int i = 1; i <= N; i++) {
            sum[i] = sum[i - 1] + charge[i];
        }

        while (Q--) {
            int l, r;
            cin >> l >> r;
            int S = r - l + 1;
            int delta = sum[r] - sum[l - 1];
            int ans = 0;
            vector<int> rem;
            if (delta != 0 && S % 2 == 0) {
                ans = 2;
                rem.push_back(r);
                delta -= charge[r--];
            } else if (delta != 0) {
                ans = 1;
            }
            cout << ans << '\n';
            if (ans == 0) {
                continue;
            }
            if (delta == charge[r]) {
                rem.push_back(r);
            } else if (delta == charge[l]) {
                rem.push_back(l);
            } else if (delta != 0) {
                int L = l, R = r;
                while (L + 1 < R) {
                    int M = (L + R) / 2;
                    int get = sum[M - 1] - sum[l - 1] - (sum[r] - sum[M]);
                    if (get == 0) {
                        rem.push_back(M);
                        break;
                    } else if ((get > 0) == (delta > 0)) {
                        R = M;
                    } else {
                        L = M;
                    }
                }
            }
            for (int i = 0; i < ans; i++) {
                cout << rem[i] << " \n"[i + 1 == ans];
            }
        }
    }
    return 0;
}