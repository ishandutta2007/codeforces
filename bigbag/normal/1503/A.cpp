/**
 *  created: 03/04/2021, 17:36:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

bool ok(const string &s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') {
            ++bal;
        } else {
            --bal;
            if (bal < 0) {
                return false;
            }
        }
    }
    return bal == 0;
}

int t, n;
string s, a, b;


bool solve() {
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        tot += s[i] == '0';
    }
    if (tot % 2) {
        return false;
    }
    int need = n / 2 - tot / 2;
    a = "";
    b = "";
    bool f = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (need) {
                a += '(';
                b += '(';
                --need;
            } else {
                a += ')';
                b += ')';
            }
        } else {
            if (f) {
                a += '(';
                b += ')';
            } else {
                b += '(';
                a += ')';
            }
            f ^= 1;
        }
    }
    return ok(a) && ok(b);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        s = read();
        if (solve()) {
            puts("YES");
            puts(a.c_str());
            puts(b.c_str());
        } else {
            puts("NO");
        }
    }
    return 0;
}