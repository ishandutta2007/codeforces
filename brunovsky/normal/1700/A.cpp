#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int64_t choose(int64_t n) { return n * (n - 1) / 2; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int64_t N, M;
        cin >> N >> M;
        int64_t A = choose(M + 1) + M * choose(N + 1) - M;
        cout << A << '\n';
    }
    return 0;
}