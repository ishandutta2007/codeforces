#include <bits/stdc++.h>

using namespace std;

const int max_n = 2222, inf = 1000111222;

int n, p;
set<char> q[max_n];
string s;

void write() {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '.') {
            s[i] = '0';
        }
    }
    cout << s << endl;
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> p >> s;
    for (int i = 0; i + p < n; ++i) {
        int pos = i + p;
        if (s[i] == '.' && s[pos] == '.') {
            s[i] = '0';
            s[pos] = '1';
            write();
        } else if (s[i] != '.' && s[pos] != '.') {
            if (s[i] != s[pos]) {
                write();
            }
        } else {
            if (s[i] == '.') {
                swap(i, pos);
            }
            s[pos] = ((s[i] - '0') ^ 1) + '0';
            write();
        }
    }
    cout << "No" << endl;
    return 0;
}