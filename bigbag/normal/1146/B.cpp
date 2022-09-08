#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

void wa() {
    printf(":(");
    exit(0);
}

string f(const string &s) {
    string t;
    for (char c : s) {
        if (c != 'a') {
            t += c;
        }
    }
    return s + t;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s, t;
    s = read();
    for (char c : s) {
        if (c != 'a') {
            t += c;
        }
    }
    string was = s.substr(0, s.length() - t.length() / 2);
    if (f(was) != s) {
        wa();
    }
    printf("%s\n", was.c_str());
    return 0;
}