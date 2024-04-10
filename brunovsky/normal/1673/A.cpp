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
        int x = 0;
        for (char c : s) {
            x += (c - 'a') + 1;
        }
        if (N % 2 == 0) {
            cout << "Alice " << x << '\n';
        } else {
            int y = min(s[0] - 'a' + 1, s[N - 1] - 'a' + 1);
            x -= y;
            if (x > y) {
                cout << "Alice " << x - y << '\n';
            } else {
                cout << "Bob " << y - x << '\n';
            }
        }
    }
    return 0;
}