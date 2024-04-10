#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1111111111;

int p[max_n][8], lo[max_n][8];
string s;

void get_ans(int poz) {
    string ans = "";
    int o = 0;
    while (poz >= 0) {
        ans += s[poz];
        int no = lo[poz][o];
        poz = p[poz][o];
        o = no;
    }
    cout << "YES" << endl;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < 8; ++j) {
            p[i][j] = inf;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        p[i][(s[i] - '0') % 8] = -1;
    }
    for (int i = 0; i < s.length(); ++i) {
        if (p[i][0] != inf) {
            get_ans(i);
            return 0;
        }
        for (int o = 1; o < 8; ++o) {
            if (p[i][o] == inf) {
                continue;
            }
            for (int j = i + 1; j < s.length(); ++j) {
                p[j][(o * 10 + s[j] - '0') % 8] = i;
                lo[j][(o * 10 + s[j] - '0') % 8] = o;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}