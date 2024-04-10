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
        uint64_t x;
        cin >> N >> K >> x, x--;

        string s;
        cin >> s;

        string ans;
        int i = N - 1;
        while (i >= 0) {
            if (s[i] == 'a') {
                ans += 'a';
                i--;
            } else {
                int r = i;
                do {
                    i--;
                } while (i >= 0 && s[i] == '*');
                int D = K * (r - i) + 1;
                ans += string(x % D, 'b');
                x /= D;
            }
        }

        reverse(begin(ans), end(ans));
        cout << ans << '\n';
    }
    return 0;
}