#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        long N;
        cin >> N;
        int ans = 150;
        string s = to_string(N);
        int S = s.size();
        for (int k = 0; k <= 63; k++) {
            string a = to_string(1ULL << k);
            int A = a.size();
            int cost = 0;
            int i = 0, j = 0;
            while (i < S && j < A) {
                if (s[i] == a[j]) {
                    i++, j++; // don't need to pay
                } else {
                    i++, cost++; // need to pay
                }
            }
            cost += S - i + A - j;
            ans = min(ans, cost);
        }
        cout << ans << '\n';
    }
    return 0;
}