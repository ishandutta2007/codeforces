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
        // a run of zeros has mex of 1
        // see if the string has a single run of zeros
        if (s == string(N, '0')) {
            cout << 1 << '\n';
        } else if (s == string(N, '1')) {
            cout << 0 << '\n';
        } else {
            // there are zeros and ones
            int i = 0;
            while (i < N && s[i] == '1') {
                i++;
            }
            while (i < N && s[i] == '0') {
                i++;
            }
            while (i < N && s[i] == '1') {
                i++;
            }
            if (i == N) {
                cout << 1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }
    }
    return 0;
}