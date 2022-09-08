#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int q, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int cl = 0, cr = 0, cd = 0, cu = 0;
        for (char c : s) {
            cl += c == 'L';
            cr += c == 'R';
            cu += c == 'U';
            cd += c == 'D';
        }
        cl = min(cl, cr);
        cu = min(cu, cd);
        if (cl == 0 || cu == 0) {
            cl = min(cl, 1);
            cu = min(cu, 1);
        }
        string ans;
        for (int i = 0; i < cl; ++i) {
            ans += 'R';
        }
        for (int i = 0; i < cu; ++i) {
            ans += 'U';
        }
        for (int i = 0; i < cl; ++i) {
            ans += 'L';
        }
        for (int i = 0; i < cu; ++i) {
            ans += 'D';
        }
        cout << ans.length() << "\n" << ans << "\n";
    }
    return 0;
}