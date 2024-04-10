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
        string s;
        cin >> N >> s;

        int S = s.size();
        int D = count(begin(s), end(s), 'D');
        int R = count(begin(s), end(s), 'R');

        if (D == 0 || R == 0) {
            cout << N << '\n';
            continue;
        }
        assert(D < N && R < N);

        int d = find(begin(s), end(s), 'D') - begin(s);
        int r = find(begin(s), end(s), 'R') - begin(s);

        // Leeway each side
        int A = N - (1 + D), B = N - (1 + R);

        int64_t x = S + 1;
        int64_t below = 1LL * (R + 1 - d) * A;
        int64_t right = 1LL * (D + 1 - r) * B;
        int64_t corner = 1LL * A * B; // dude...
        cout << (x + below + right + corner) << '\n';
    }
    return 0;
}