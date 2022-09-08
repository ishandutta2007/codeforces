#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

string s;

bool is_palindrom(const string &s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 1; i < s.length(); ++i) {
        string t = s.substr(i) + s.substr(0, i);
        if (is_palindrom(t) && t != s) {
            cout << 1 << endl;
            return 0;
        }
    }
    if (s.length() == 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    int add = s.length() % 2;
    s = s.substr(0, s.length() / 2);
    set<char> q(s.begin(), s.end());
    if (q.size() == 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << 2 << endl;
    return 0;
}