#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int MAX = 500'001;
    vector<int> grundy(MAX);
    for (int n = 1; n < 3000; n++) {
        vector<int8_t> seen(50);
        for (int l = 0, r = n - 2; r >= 0; l++, r--) {
            seen[grundy[l] ^ grundy[r]] = true;
        }
        while (seen[grundy[n]])
            grundy[n]++;
    }
    for (int n = 3000; n < MAX; n++) {
        grundy[n] = grundy[n - 34];
    }

    int T;
    cin >> T;
    while (T--) {
        int N;
        string s;
        cin >> N >> s;
        int Rs = 0, Bs = 0, bal = 0;
        for (int l = 0, r = 1; l < N; l = r++) {
            while (r < N && s[r - 1] != s[r]) {
                r++;
            }
            int k = r - l;
            if (k % 2 == 0) {
                bal ^= grundy[k];
            } else if (k % 2 == 1) {
                Rs += s[l] == 'R';
                Bs += s[l] == 'B';
                bal ^= grundy[k];
            }
        }
        if (Rs > Bs) {
            cout << "Alice\n";
        } else if (Rs < Bs) {
            cout << "Bob\n";
        } else if (bal == 0) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
    return 0;
}