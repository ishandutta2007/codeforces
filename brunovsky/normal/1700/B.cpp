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
        string t(N, '0');
        if (s[0] < '9') {
            for (int i = 0; i < N; i++) {
                t[i] = '0' + ('9' - s[i]);
            }
        } else {
            // Make it 111111....
            for (int i = N - 1, c = 0, w = 11; i >= 0; i--) {
                int x = w - (s[i] - '0') - c;
                t[i] = '0' + (x % 10);
                c = x < 10;
            }
        }
        string sum(N + 1, '0');
        int c = 0;
        for (int i = N - 1; i >= 0; i--) {
            int x = (s[i] - '0') + (t[i] - '0') + c;
            sum[i + 1] = '0' + (x % 10);
            c = x / 10;
        }
        sum[0] = '0' + c;
        debug(s, t, sum);
        cout << t << '\n';
    }
    return 0;
}