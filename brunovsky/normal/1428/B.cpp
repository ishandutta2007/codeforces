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
        int acw = count(begin(s), end(s), '>');
        int bcw = count(begin(s), end(s), '<');
        if (acw == 0 || bcw == 0) {
            cout << N << '\n';
            continue;
        }
        vector<bool> ok(N);
        for (int i = 0; i < N; i++) {
            int l = i, r = (i + 1) % N;
            ok[i] = s[l] == '-' || s[r] == '-';
        }
        cout << count(begin(ok), end(ok), true) << '\n';
    }
    return 0;
}