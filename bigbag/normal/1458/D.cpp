/**
 *  created: 21/12/2020, 20:26:50
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, cntl[max_n], cntr[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        s = read();
        int bal = max_n / 2;
        for (char c : s) {
            if (c == '1') {
                ++cntr[bal];
                ++bal;
            } else {
                ++cntl[bal];
                --bal;
            }
        }
        bal = max_n / 2;
        string ans;
        for (int i = 0; i < s.length(); ++i) {
            if (cntl[bal] && (cntr[bal - 1] || cntr[bal] == 0)) {

                ans += '0';
                --cntl[bal];
                --bal;
            } else {
                ans += '1';
                --cntr[bal];
                ++bal;
            }
        }
        puts(ans.c_str());
    }
    return 0;
}