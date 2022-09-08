/**
 *  created: 25/03/2021, 16:56:22
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_c = 26;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, last[max_c], used[max_c], first[max_c];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        s = read();
        memset(last, -1, sizeof(last));
        memset(used, 0, sizeof(used));
        for (int i = 0; i < s.length(); ++i) {
            last[s[i] - 'a'] = i;
        }
        int tot = 0;
        for (int i = 0; i < max_c; ++i) {
            tot += last[i] != -1;
        }
        int pos = 0;
        for (int it = 0; it < tot; ++it) {
            memset(first, -1, sizeof(first));
            for (int i = pos; i < s.size(); ++i) {
                if (first[s[i] - 'a'] == -1) {
                    first[s[i] - 'a'] = i;
                }
            }
            for (int i = max_c - 1; i >= 0; --i) {
                if (!used[i] && last[i] != -1) {
                    int mn = inf;
                    for (int j = 0; j < max_c; ++j) {
                        if (i != j && !used[j] && last[j] != -1) {
                            mn = min(mn, last[j]);
                        }
                    }
                    if (mn > first[i]) {
                        printf("%c", i + 'a');
                        pos = first[i] + 1;
                        used[i] = 1;
                        break;
                    }
                }
            }
        }
        puts("");
    }
    return 0;
}