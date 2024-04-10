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

        // check if S already is
        int ans = N + 1;

        for (char c = 'a'; c <= 'z'; c++) {
            int count = 0;
            for (int i = 0, j = N - 1; i < j; i++, j--) {
                if (s[i] != s[j]) {
                    if (s[i] == c) {
                        do {
                            count++, i++;
                        } while (i < j && s[i] == c);
                    } else if (s[j] == c) {
                        do {
                            count++, j--;
                        } while (i < j && s[j] == c);
                    }
                }
                if (s[i] != s[j]) {
                    count = N + 1;
                    break;
                }
            }
            ans = min(ans, count);
        }

        cout << (ans == N + 1 ? -1 : ans) << '\n';
    }
    return 0;
}