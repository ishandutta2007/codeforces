#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int n;
string s;

bool is_ok(const string &s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') {
            ++bal;
        } else if (bal == 0) {
            return false;
        } else {
            --bal;
        }
    }
    return bal == 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    s = read();
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '(') {
            string q = "(" + s.substr(0, i) + s.substr(i + 1);
            if (is_ok(q)) {
                puts("Yes");
                return 0;
            }
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            string q = s.substr(0, i) + s.substr(i + 1) + ")";
            if (is_ok(q)) {
                puts("Yes");
                return 0;
            }
            break;
        }
    }
    puts("No");
    return 0;
}