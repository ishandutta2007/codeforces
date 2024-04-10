#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    sort(rbegin(P), rend(P) - 1);
    vector<int64_t> S(N + 1);
    for (int i = 1; i <= N; i++) {
        S[i] = S[i - 1] + P[i];
    }
    debug(P, S);
    while (Q--) {
        int x, y;
        cin >> x >> y;
        cout << S[x] - S[x - y] << '\n';
    }
    return 0;
}