/**
 *  created: 22/07/2021, 18:02:04
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 201111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        string s = read();
        string need = read();
        reverse(need.begin(), need.end());
        int last = s.size(), pos = 0;
        for (int i = s.size() - 1; i >= 0 && pos < need.size(); --i) {
            if (i % 2 != last % 2 && need[pos] == s[i]) {
                ++pos;
                last = i;
            }
        }
        if (pos == need.size()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}