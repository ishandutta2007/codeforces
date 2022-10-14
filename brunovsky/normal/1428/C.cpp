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
        string s;
        cin >> s;
        // only the length
        int N = s.size();
        string skip;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'A') {
                skip.push_back('A');
            } else if (s[i] == 'B' && skip.empty()) {
                skip.push_back('B');
            } else {
                skip.pop_back();
            }
        }
        cout << skip.size() << '\n';
    }
    return 0;
}