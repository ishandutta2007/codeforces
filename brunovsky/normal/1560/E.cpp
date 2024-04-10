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
        string t;
        cin >> t;
        int L = t.size();

        // count uniques
        array<int, 26> total = {};
        for (int i = 0; i < L; i++) {
            total[t[i] - 'a']++;
        }
        int U = 0;
        for (int i = 0; i < 26; i++) {
            U += total[i] != 0;
        }

        string order;
        array<int, 26> sfreq = {};
        string x = t;
        bool busted = false;

        for (int u = U; u > 0; u--) {
            if (x.empty()) {
                busted = true;
                break;
            }
            char c = x.back();
            int cnt = count(begin(x), end(x), c);
            if (cnt % u != 0) {
                busted = true;
                break;
            }
            order.push_back(c);
            sfreq[c - 'a'] = cnt / u;
            x.erase(remove(begin(x), end(x), c), end(x));
        }
        if (busted) {
            cout << -1 << '\n';
            continue;
        }

        int X = accumulate(begin(sfreq), end(sfreq), 0);
        string s = t.substr(0, X);

        // simulate to confirm
        reverse(begin(order), end(order));
        string trial = s;
        string z;

        for (char c : order) {
            z += trial;
            trial.erase(remove(begin(trial), end(trial), c), end(trial));
        }

        if (z != t) {
            cout << -1 << '\n';
            continue;
        }

        // OK
        cout << s << ' ' << order << '\n';
    }
    return 0;
}