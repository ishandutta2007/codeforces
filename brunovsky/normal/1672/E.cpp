#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int QUERY(int w) {
    cout << "? " << w << endl;
    int h;
    cin >> h;
    return h;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    const int V = 2000 * N + N - 1; // maximum length
    int L = 0, R = V;
    while (L + 1 < R) {
        int M = (L + R) / 2;
        QUERY(M) == 1 ? R = M : L = M;
    }
    // R is the length
    int ans = R;
    for (int n = 2; n <= N; n++) {
        int w = (R - 1) / n;
        int h = QUERY(w);
        if (h > 0) {
            ans = min(ans, h * w);
        }
    }
    cout << "! " << ans << endl;
    return 0;
}

// fucking atcoder statements
// just latex text editor
// a single row is very close to optimal in all cases
// So its obviously one binary search + one linear search
// We can binary search for longest word
// We can also binary search for total length as != 1
// Suppose we target a height of n and need width w
// We should have nw < R <=> w < R/n <=> w <= floor(R - 1, n)
// If we reduce to w-1 we get n(w-1) = nw-n area. If we add n-1 spaces we can make a
// single line, but nw-n+n-1 < nw < R so contradiction. So only check w