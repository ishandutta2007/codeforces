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
        s.push_back('R');
        int j = 0;
        while (s[j] == '?')
            j++;
        for (int i = j + 1; i < N; i++) {
            if (s[i] == '?') {
                s[i] = s[i - 1] == 'R' ? 'B' : 'R';
            }
        }
        for (int i = j - 1; i >= 0; i--) {
            s[i] = s[i + 1] == 'R' ? 'B' : 'R';
        }
        s.pop_back();
        cout << s << '\n';
    }
    return 0;
}