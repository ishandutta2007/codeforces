#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    if (N >= M + 1) {
        cout << 0 << '\n';
    } else {
        int ans = 1;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                ans = 1LL * ans * abs(a[i] - a[j]) % M;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}