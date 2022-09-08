#include <bits/stdc++.h>

using namespace std;

int t, a, b, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        string s;
        if (b % 2) {
            for (int i = 0; i <= a; ++i) {
                s += '0';
            }
            int last = 0;
            for (int i = 0; i < b; ++i) {
                last ^= 1;
                s += '0' + last;
            }
            for (int i = 0; i < c; ++i) {
                s += '1';
            }
        } else if (!b) {
            if (a) {
                for (int i = 0; i <= a; ++i) {
                    s += '0';
                }
            }
            if (c) {
                for (int i = 0; i <= c; ++i) {
                    s += '1';
                }
            }
        } else {
            for (int i = 0; i <= a; ++i) {
                s += '0';
            }
            int last = 0;
            for (int i = 0; i < b; ++i) {
                last ^= 1;
                s += '0' + last;
            }
            s.pop_back();
            for (int i = 0; i < c; ++i) {
                s += '1';
            }
            s += '0';
        }
        cout << s << "\n";
    }
    return 0;
}