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
        vector<int> a(N), cnt(N + 1);
        for (int i = 0; i < N; i++) {
            cin >> a[i], cnt[a[i]]++;
        }
        string ans(N, '0');
        ans[0] = *max_element(begin(cnt), end(cnt)) == 1 ? '1' : '0';
        ans[N - 1] = cnt[1] > 0 ? '1' : '0';
        int L = 0, R = N - 1;
        for (int k = 2; k < N && cnt[k - 1] == 1 && cnt[k]; k++) {
            if (a[L] == k - 1) {
                L++;
            } else if (a[R] == k - 1) {
                R--;
            } else {
                break;
            }
            ans[N - k] = '1';
        }
        cout << ans << '\n';
    }
    return 0;
}