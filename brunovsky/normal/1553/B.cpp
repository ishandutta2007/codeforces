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
        string s, t;
        cin >> s >> t;
        bool found = false;
        int N = s.size(), M = t.size();
        for (int a = 0; a < N && !found; a++) {
            int b = M - a;
            if (0 <= b && b <= N) {
                for (int i = 0, j = i + a; j < N; i++, j++) {
                    int k = j + 1 - b;
                    if (k >= 0) {
                        string left = s.substr(i, a);
                        string right = s.substr(k, b);
                        reverse(begin(right), end(right));
                        if (left + right == t) {
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}