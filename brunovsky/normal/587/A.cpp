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
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }

    const int M = *max_element(begin(w), end(w)) + 100;
    vector<int> cnt(M + 1);
    for (int x : w) {
        cnt[x]++;
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int x = cnt[i] / 2, y = cnt[i] % 2;
        ans += y;
        cnt[i + 1] += x;
    }
    cout << ans << '\n';
    return 0;
}