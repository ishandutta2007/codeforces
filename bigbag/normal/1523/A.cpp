/**
 *  created: 30/05/2021, 17:36:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, m;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        s = read();
        while (m--) {
            string ns = s;
            bool change = 0;
            for (int i = 0; i < n; ++i) {
                int cnt = 0;
                if (i) {
                    cnt += s[i - 1] == '1';
                }
                if (i + 1 < n) {
                    cnt += s[i + 1] == '1';
                }
                if (s[i] == '0' && cnt == 1) {
                    ns[i] = '1';
                    change = 1;
                }
            }
            if (!change) {
                break;
            }
            s.swap(ns);
        }
        puts(s.c_str());
    }
    return 0;
}