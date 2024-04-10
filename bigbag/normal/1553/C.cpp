/**
 *  created: 22/07/2021, 17:50:12
**/

#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int solve() {
    for (int i = 1; i <= s.size(); ++i) {
        for (int f = 0; f < 2; ++f) {
            int delta = 0;
            for (int j = 0; j < i; ++j) {
                char c = s[j];
                if (c == '?') {
                    c = '0';
                    if (j % 2 == f) {
                        c = '1';
                    }
                }
                if (c == '1') {
                    if (j % 2 == 0) {
                        delta += 1;
                    } else {
                        delta -= 1;
                    }
                }
            }
            int mx_delta = delta, mn_delta = delta;
            for (int j = i; j < s.size(); ++j) {
                if (j % 2 == 0) {
                    ++mx_delta;
                } else {
                    --mn_delta;
                }
            }
            //cout << i << " " << f << " " << delta << ": " << mn_delta << " " << mx_delta << endl;
            if (mx_delta < 0 || mn_delta > 0) {
                return i;
            }
        }
    }
    return 10;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        cout << solve() << "\n";
    }
    return 0;
}