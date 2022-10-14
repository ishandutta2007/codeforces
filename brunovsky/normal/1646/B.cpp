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
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(rbegin(a), rend(a));
        // We don't have to paint everything
        int reds = (N - 1) / 2;
        int64_t A = accumulate(begin(a), begin(a) + reds, 0LL);
        int64_t B = accumulate(begin(a) + reds + (N % 2 == 0), end(a), 0LL);
        cout << (A > B ? "YES\n" : "NO\n");
    }
    return 0;
}