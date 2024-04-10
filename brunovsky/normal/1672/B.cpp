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
        int N = s.size();
        bool ok = s.back() == 'B';
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += s[i] == 'A';
            sum -= s[i] == 'B';
            ok &= sum >= 0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}