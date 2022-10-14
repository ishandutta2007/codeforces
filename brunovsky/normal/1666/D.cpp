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
        string a, b;
        cin >> a >> b;
        vector<int> cnt(256);
        for (char c : b) {
            cnt[c]++;
        }
        for (char c : a) {
            cnt[c]--;
        }
        int M = *max_element(begin(cnt), end(cnt));
        if (M > 0) {
            cout << "NO\n";
            continue;
        }
        string y;
        for (char c : a) {
            if (cnt[c]++ >= 0) {
                y.push_back(c);
            }
        }
        cout << (y == b ? "YES\n" : "NO\n");
    }
    return 0;
}