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
        string s;
        cin >> N >> s;
        N = s.size();
        if (is_sorted(begin(s), end(s))) {
            cout << "0\n";
            continue;
        }
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < N; i++) {
            ones += s[i] == '1';
            zeros += s[i] == '0';
        }
        if (ones > zeros) {
            for (int i = 0; i < N; i++) {
                s[i] = s[i] == '1' ? '0' : '1';
            }
            swap(ones, zeros);
            reverse(begin(s), end(s));
        }
        vector<int> right(N + 1, -1);
        right[0] = 0;
        int D = 0;
        for (int i = 0; i < N; i++) {
            D += s[i] == '0';
            D -= s[i] == '1';
            if (D >= 0) {
                right[D] = i;
            }
        }
        assert(D == zeros - ones);
        int i = 0, b = right[0], ans = 0;
        while (true) {
            while (i < D && s[i] == '0') {
                i++;
                b = max(b, right[i]);
            }
            ans++;
            if (i == D) {
                break; // we overflowed, we're done
            }
            debug(i, b, s);
            assert((b - i) % 2 == 1);
            for (int l = i, r = b; l < r; l++, r--) {
                s[l] = '0', s[r] = '1';
            }
        }
        debug(s);
        cout << ans << '\n';
    }
    return 0;
}

// based on tourist's sub
// 01000010001010011000
//  .,
// 00100010001010011000
//   .,
// 00010010001010011000
//    .  ,
// 00000110001010011000
//      .          ,
// 00000000000111111000
//         ^  .       , if we ^ we're done so just stop
// 00000000000000111111
// remember you put more zeros

// 10000001000000000000001000000
// 01000001000000000000001000000
// 00100001000000000000001000000
// 00010001000000000000001000000
// 00001001000000000000001000000
// 00000011000000000000001000000
// 00000000110000000000001000000
// 00000000001100000000001000000
// 00000000000011000000001000000
// 00000000000000110000001000000
// 00000000000000001100001000000
// 00000000000000000011001000000
// 00000000000000000000011100000
// 00000000000000000000000011100
// 00000000000000000000000000011