/**
 *  created: 28/11/2021, 16:38:14
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, q, ok[max_n], ans;
string s;

void upd(int i) {
    ans -= ok[i];
    ok[i] = s.substr(i, 3) == "abc";
    ans += ok[i];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> s;
    for (int i = 0; i + 2 < n; ++i) {
        upd(i);
    }
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;
        s[pos] = c;
        for (int i = max(0, pos - 2); i <= pos && i + 2 < n; ++i) {
            upd(i);
        }
        cout << ans << "\n";
    }
    return 0;
}