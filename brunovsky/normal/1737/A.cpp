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
        int N, K;
        cin >> N >> K;
        string books;
        cin >> books;
        constexpr int A = 26;
        array<int, A> cnt = {};
        for (char c : books) {
            cnt[c - 'a']++;
        }
        string ans(K, 'a');
        for (int i = 0; i < K; i++) {
            for (int a = 0; a < A && a < N / K; a++) {
                if (cnt[a]) {
                    cnt[a]--;
                    ans[i] = 'a' + a + 1;
                } else {
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}