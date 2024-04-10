#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int a, b, x, y, p[max_n];
string s, ans;

void get_prefix_function(const string &s, int p[]) {
    p[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            ++p[i];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    s = read();
    for (char c : s) {
        if (c == '0') {
            ++a;
        } else {
            ++b;
        }
    }
    s = read();
    for (char c : s) {
        if (c == '0') {
            ++x;
        } else {
            ++y;
        }
    }
    get_prefix_function(s + "#" + s.substr(1), p);
    int len = p[2 * s.length() - 1];
    int mnx = 0, mny = 0;
    for (int i = s.length() - len; i < s.length(); ++i) {
        if (s[i] == '0') {
            ++mnx;
        } else {
            ++mny;
        }
    }
    string ans;
    bool first = true;
    while (a >= x && b >= y) {
        // cout << a << " " << b << " " << first << ": " << ans << " " << len << endl;
        a -= x;
        b -= y;
        if (first) {
            ans += s;
            first = false;
            x -= mnx;
            y -= mny;
        } else {
            ans += s.substr(len);
        }
    }
    while (a--) {
        ans += '0';
    }
    while (b--) {
        ans += '1';
    }
    puts(ans.c_str());
    return 0;
}