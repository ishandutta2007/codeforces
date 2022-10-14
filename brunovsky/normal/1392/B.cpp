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
        vector<int> a(N), b(N), c(N), d(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int D = *max_element(begin(a), end(a));
        for (int i = 0; i < N; i++) {
            b[i] = D - a[i];
        }
        int E = *max_element(begin(b), end(b));
        for (int i = 0; i < N; i++) {
            c[i] = E - b[i];
        }
        int F = *max_element(begin(c), end(c));
        for (int i = 0; i < N; i++) {
            d[i] = F - c[i];
        }
        assert(b == d);
        vector<int> ans;
        if (K == 0) {
            ans = a;
        } else if (K % 2 == 0) {
            ans = c;
        } else {
            ans = b;
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}