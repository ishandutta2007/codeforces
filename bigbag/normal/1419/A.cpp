#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        if (n % 2) {
            bool ok = 0;
            for (int i = 0; i < n; i += 2) {
                ok |= (s[i] - '0') % 2;
            }
            if (ok) {
                puts("1");
            } else {
                puts("2");
            }
        } else {
            bool ok = 0;
            for (int i = 1; i < n; i += 2) {
                ok |= (s[i] - '0') % 2 == 0;
            }
            if (ok) {
                puts("2");
            } else {
                puts("1");
            }
        }
    }
    return 0;
}