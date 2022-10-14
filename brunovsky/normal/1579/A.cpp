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
        int A = count(begin(s), end(s), 'A');
        int B = count(begin(s), end(s), 'B');
        int C = count(begin(s), end(s), 'C');
        if (A + C == B) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}