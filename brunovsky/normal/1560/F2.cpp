#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int count_distinct(const string& x) {
    int cnt[10] = {};
    for (char c : x) {
        cnt[c - '0']++;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += cnt[i] != 0;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        long N, K;
        cin >> N >> K;
        string s = to_string(N);
        int S = s.size();

        // try to maintain all digits up to L-1
        long ans = LONG_MAX;
        for (int L = S; L >= 0; L--) {
            string a = s.substr(0, L);
            while (!a.empty() && a.back() <= '9') {
                if (count_distinct(a) <= K) {
                    for (int z = 0; z <= 9; z++) {
                        string b = a + string(S - L, '0' + z);
                        long c = stoll(b);
                        if (c >= N && count_distinct(b) <= K) {
                            ans = min<long>(ans, c);
                            break;
                        }
                    }
                }
                a.back() = a.back() + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}