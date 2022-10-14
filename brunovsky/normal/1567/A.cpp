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
        int n;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') {
                s[i] = 'D';
            } else if (s[i] == 'D') {
                s[i] = 'U';
            }
        }
        cout << s << '\n';
    }
    return 0;
}