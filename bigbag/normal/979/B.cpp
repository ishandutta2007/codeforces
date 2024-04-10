#include <bits/stdc++.h>

using namespace std;

const int max_n = 255, inf = 1000111222;
const string names[] = {"Kuro", "Shiro", "Katie"};

int n, cnt[5], a[max_n];
string s[5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
        if (s[i].length() == 1) {
            cnt[i] = 1;
            continue;
        }
        memset(a, 0, sizeof(a));
        for (char c : s[i]) {
            ++a[c];
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            int x = a[c] + n;
            if (x > s[i].length()) {
                if (a[c] == s[i].length() && n == 1) {
                    x = s[i].length() - 1;
                } else {
                    x = s[i].length();
                }
            }
            cnt[i] = max(cnt[i], x);
        }
        for (char c = 'A'; c <= 'Z'; ++c) {
            int x = a[c] + n;
            if (x > s[i].length()) {
                if (a[c] == s[i].length() && n == 1) {
                    x = s[i].length() - 1;
                } else {
                    x = s[i].length();
                }
            }
            cnt[i] = max(cnt[i], x);
        }
    }
    int mx = max({cnt[0], cnt[1], cnt[2]});
    int f = 0;
    for (int i = 0; i < 3; ++i) {
        if (cnt[i] == mx) {
            ++f;
        }
    }
    if (f > 1) {
        cout << "Draw\n";
    } else {
        for (int i = 0; i < 3; ++i) {
            if (cnt[i] == mx) {
                cout << names[i] << "\n";
                return 0;
            }
        }
    }
    return 0;
}