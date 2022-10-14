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
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        // a[i] == 0 means i->N+1, a[i]==1 means N+1->i
        vector<int> ans(N + 1);
        for (int i = 1; i < N; i++) {
            if (a[i] == 0 && a[i + 1] == 1) {
                iota(begin(ans), begin(ans) + i, 1);
                ans[i] = N + 1;
                iota(begin(ans) + i + 1, end(ans), i + 1);
                goto answer;
            }
        }

        if (a[N] == 0) {
            iota(begin(ans), end(ans), 1);
            goto answer;
        }

        if (a[1] == 1) {
            ans[0] = N + 1;
            iota(begin(ans) + 1, end(ans), 1);
            goto answer;
        }

        cout << -1 << '\n';
        continue;

    answer:
        for (int i = 0; i <= N; i++) {
            cout << ans[i] << " \n"[i == N];
        }
    }
    return 0;
}