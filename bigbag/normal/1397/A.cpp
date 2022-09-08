#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int t, n, cnt[26];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (char c : s) {
                ++cnt[c - 'a'];
            }
        }
        bool ok = 1;
        for (int i = 0; i < 26; ++i) {
            ok &= cnt[i] % n == 0;
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}