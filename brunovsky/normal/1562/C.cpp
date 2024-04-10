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
        auto put = [&](int a, int b, int c, int d) {
            cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        };
        if (N == 2) {
            if (s[0] == '0') {
                put(1, 1, 2, 2);
            } else {
                put(2, 2, 1, 1);
            }
            continue;
        }

        bool found = false;
        int M = N / 2;
        for (int i = 0; !found && i < M; i++) {
            if (s[i] == '0') {
                found = true;
                put(i + 1, N, i + 2, N);
            }
        }
        for (int i = N - 1; !found && i >= M; i--) {
            if (s[i] == '0') {
                found = true;
                put(1, i + 1, 1, i);
            }
        }
        if (!found) {
            found = true;
            put(1, 2 * M, 1, M);
        }
    }
    return 0;
}