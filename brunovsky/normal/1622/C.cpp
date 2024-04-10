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
        int64_t K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        int64_t sum = accumulate(begin(a), end(a), 0LL);

        // Suppose we only decrement a[0]
        int64_t ans = max<int64_t>(0, sum - K);

        vector<int64_t> suffix(N);
        suffix[N - 1] = a[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            suffix[i] = a[i] + suffix[i + 1];
        }

        // Now suppose we can decrement a[0] and then assign a[i]...a[N-1]
        for (int i = N - 1; i >= 1; i--) {
            int64_t was = suffix[i];
            int64_t now = int64_t(N - i) * a[0];
            int64_t need = max<int64_t>(0, sum - was + now - K);
            // If we decrement x times first we decrease by (N-i+1)x
            // (N-i+1)x>=need <==> x>=need/(N-i+1)
            int64_t x = (need + N - i) / (N - i + 1);
            ans = min(ans, x + (N - i));
        }

        cout << ans << '\n';
    }
    return 0;
}