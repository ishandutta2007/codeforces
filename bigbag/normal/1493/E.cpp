/**
 *  created: 06/03/2021, 17:43:19
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int n;
string l, r;

string inc(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            s[i] = '1';
            reverse(s.begin(), s.end());
            return s;
        }
        s[i] = '0';
    }
    while (1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    l = read();
    r = read();
    if (n == 1) {
        puts(r.c_str());
        return 0;
    }
    string best = r;
    if (l != r && inc(l) != r && r.back() == '0') {
        best.back() = '1';
    }
    if (l[0] == '0') {
        best = string(n, '1');
    }
    puts(best.c_str());
    return 0;
}