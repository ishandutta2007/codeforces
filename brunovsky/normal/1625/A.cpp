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
        int N, L;
        cin >> N >> L;
        vector<int> count(L);
        for (int i = 0; i < N; i++) {
            int number;
            cin >> number;
            for (int j = 0; j < L; j++) {
                count[j] += (number >> j) & 1;
            }
        }
        int ans = 0;
        for (int j = 0; j < L; j++) {
            if (count[j] > N / 2) {
                ans |= 1 << j;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}