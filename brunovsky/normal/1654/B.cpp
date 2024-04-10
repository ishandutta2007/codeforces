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
        int S = s.size();

        array<int, 26> cnt = {}; // dude...
        int i = S - 1, ans = S - 1;
        while (i >= 0) {
            int c = s[i] - 'a';
            cnt[c]++;
            if (cnt[c] == 1) {
                ans = i;
            }
            i--;
        }

        s = s.substr(ans);
        cout << s << '\n';
    }
    return 0;
}