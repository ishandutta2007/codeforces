#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, A, B, K;
    cin >> N >> M >> A >> B >> K;
    vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    if (K >= N) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = -1;
    for (int i = 0; i < K + 1; i++) {
        // cancel A[0,i) and then K-i more from B and take flight i
        int f = K - i + lower_bound(begin(b), end(b), a[i] + A) - begin(b);
        if (f < M) {
            ans = max(ans, b[f] + B);
        } else {
            ans = -1;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}