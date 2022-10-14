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
    string s;
    cin >> N >> s;
    vector<int> freq(N + 1), last(N + 1);
    int64_t ans = 0;
    auto process = [&](int v, int t) {
        int g = t - last[v];
        ans += 1LL * v * g * freq[v];
        last[v] = t;
    };
    for (int i = 0, L = 0; i < N; i++) {
        L = s[i] == '1' ? L + 1 : 0;
        if (s[i] == '1') {
            if (L == 1) {
                process(0, i);
                process(1, i);
                freq[1] += freq[0] + 1;
                freq[0] = 0;
            } else {
                process(L - 1, i);
                process(L, i);
                freq[L] += freq[L - 1];
                freq[L - 1] = 1;
            }
        } else {
            freq[0]++;
        }
    }
    for (int v = 1; v <= N; v++) {
        process(v, N);
    }
    cout << ans << '\n';
    return 0;
}