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
        cin >> N;
        string s;
        cin >> s;
        int f = N;
        for (int i = 0; i + 1 < N; i++) {
            if (s[i] < s[i + 1]) {
                f = i + 1;
                break;
            }
        }
        if (N > 1 && s[0] == s[1]) {
            f = 1;
        }
        string a = s.substr(0, f);
        string b = a;
        reverse(begin(b), end(b));
        cout << a + b << '\n';
    }
    return 0;
}