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

const int max_n = 100111, max_c = 30, inf = 1011111111;

int n, used[2][max_n][max_c];
vector<int> g[max_c];
char s[max_n];
string cur, all[2][max_n];
int q1 = 0, q2 = 1;

void fail() {
    printf("NO\n");
    exit(0);
}

void build_used() {
    memset(used[q1], -1, sizeof(used[q1]));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < all[q1][i].length(); ++j) {
            if (used[q1][i][all[q1][i][j] - 'a'] != -1) {
                fail();
            }
            used[q1][i][all[q1][i][j] - 'a'] = j;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        all[0][i] = s;
    }
    build_used();
    for (int i = 0; i < 26; ++i) {
        int m = 0;
        string cur = "";
        for (int j = 0; j < n; ++j) {
            if (used[q1][j][i] != -1) {
                if (cur == "") {
                    cur = all[q1][j];
                } else {
                    int pos = cur.find(i + 'a');
                    string ncur = cur;
                    if (pos < used[q1][j][i]) {
                        ncur = all[q1][j].substr(0, used[q1][j][i] - pos) + cur;
                    }
                    if (cur.length() - pos < all[q1][j].length() - used[q1][j][i]) {
                        int st = used[q1][j][i] + cur.length() - pos;
                        ncur += all[q1][j].substr(st);
                    }
                    cur.swap(ncur);
                    pos = cur.find(i + 'a');
                    if (cur.substr(pos - used[q1][j][i], all[q1][j].length()) != all[q1][j]) {
                        fail();
                    }
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (used[q1][j][i] == -1) {
                all[q2][m] = all[q1][j];
                ++m;
            }
        }
        if (cur != "") {
            all[q2][m] = cur;
            ++m;
        }
        swap(q1, q2);
        swap(n, m);
        build_used();
    }
    sort(all[q1], all[q1] + n);
    for (int i = 0; i < n; ++i) {
        printf("%s", all[q1][i].c_str());
    }
    printf("\n");
    return 0;
}