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
        vector<int64_t> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        while (N > 0 && a[N - 1] == 0) {
            N--, a.pop_back();
        }
        if (N == 0) {
            cout << "Yes\n";
            continue;
        }
        vector<int64_t> p(N + 1);
        for (int i = 1; i <= N; i++) {
            p[i] = a[i - 1] + p[i - 1];
        }
        bool ok = p[N] == 0;
        for (int i = 1; i < N; i++) {
            ok &= p[i] >= 1;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}