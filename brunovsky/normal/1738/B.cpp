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
        int N, K;
        cin >> N >> K;
        vector<int64_t> s(K);
        for (int i = 0; i < K; i++) {
            cin >> s[i];
        }
        if (K == 1) {
            cout << "Yes\n";
            continue;
        }
        vector<int64_t> a(K - 1);
        for (int i = 0; i < K - 1; i++) {
            a[i] = s[i + 1] - s[i];
        }
        bool ok = true;
        for (int i = 1; i < K - 1; i++) {
            ok &= a[i] >= a[i - 1];
        }
        int64_t A = s[0];
        int64_t B = a[0];
        int64_t C = N - K + 1;
        ok &= C * B >= A;
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}