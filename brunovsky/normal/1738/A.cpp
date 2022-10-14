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
        vector<int> t(N), d(N);
        for (int i = 0; i < N; i++) {
            cin >> t[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> d[i];
        }
        vector<int> a, b;
        for (int i = 0; i < N; i++) {
            (t[i] == 0 ? a : b).push_back(d[i]);
        }
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        int A = a.size();
        int B = b.size();
        int64_t as = accumulate(begin(a), end(a), 0LL);
        int64_t bs = accumulate(begin(b), end(b), 0LL);
        if (A == 0) {
            cout << bs << '\n';
        } else if (B == 0) {
            cout << as << '\n';
        } else if (A < B) {
            int64_t cs = accumulate(end(b) - A, end(b), 0LL);
            cout << 2 * as + bs + cs << '\n';
        } else if (A > B) {
            int64_t cs = accumulate(end(a) - B, end(a), 0LL);
            cout << 2 * bs + as + cs << '\n';
        } else {
            cout << 2 * (as + bs) - min(a[0], b[0]) << '\n';
        }
    }
    return 0;
}