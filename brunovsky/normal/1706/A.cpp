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
        vector<int> count(M);
        string ans(M, 'B');
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a, a--;
            a = min(a, M - 1 - a);
            count[a]++;
        }
        for (int i = 0; i < M; i++) {
            if (count[i] > 0) {
                ans[i] = 'A';
                count[i]--;
            }
            if (count[i] > 0) {
                count[M - 1 - i] += count[i];
                count[i] = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}