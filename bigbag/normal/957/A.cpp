#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1]) {
            puts("No");
            return 0;
        }
        cnt += s[i] == '?';
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            set<char> q;
            if (i) {
                q.insert(s[i - 1]);
            }
            if (i + 1 < n) {
                q.insert(s[i + 1]);
            }
            if (q.count('?')) {
                q.erase('?');
            }
            if (q.size() <= 1) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}