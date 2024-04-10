#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int64_t> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int64_t V = 0;
    vector<int64_t> need(N);
    for (int i = 0; i < N; i++) {
        V += v[i];
        need[i] = (V + i) / (i + 1);
    }
    int64_t M = *max_element(begin(need), end(need));
    int Q;
    cin >> Q;
    while (Q--) {
        int64_t t;
        cin >> t;
        if (t < M) {
            cout << "-1\n";
        } else if (int64_t ans = (V + t - 1) / t; ans > N) {
            cout << "-1\n";
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}