#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n;
string s, t;

char lower(char c) {
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

int get_type(char c) {
    c = lower(c);
    if (c == 'o' || c == '0') {
        return 1000;
    }
    if (c == '1' || c == 'l' || c == 'i') {
        return 1001;
    }
    return c;
}

bool is_similar(const string &s, const string &t) {
    if (s.length() != t.length()) {
        return false;
    }
    for (int i = 0; i < s.length(); ++i) {
        if (get_type(s[i]) != get_type(t[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> n;
    while (n--) {
        cin >> t;
        if (is_similar(s, t)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}