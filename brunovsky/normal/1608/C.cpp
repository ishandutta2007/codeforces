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
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        vector<int> index(N);
        iota(begin(index), end(index), 0);
        sort(begin(index), end(index), [&](int i, int j) { return a[i] > a[j]; });
        int R = 0;
        int B = b[index[0]];
        int K = b[index[0]];
        for (int i = 1; i < N; i++) {
            int j = index[i];
            K = min(K, b[j]);
            if (b[j] > B) {
                R = i;
                B = K;
            }
        }
        string ans(N, '0');
        for (int i = 0; i <= R; i++) {
            ans[index[i]] = '1';
        }
        cout << ans << '\n';
    }
    return 0;
}