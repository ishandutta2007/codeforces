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

const int max_n = 55, inf = 1111111111;

int n, sum, cnt[5];
char s[max_n][max_n];

void write(string s) {
    printf("%s\n", s.c_str());
    exit(0);
}

void check(int lx, int rx, int ly, int ry) {
    if (s[lx][ly] != 1 || s[lx][ry] != 1 || s[rx][ly] != 1 || s[rx][ry] != 1) {
        write("No");
    }
    for (int i = lx + 1; i < rx; ++i) {
        for (int j = ly + 1; j < ry; ++j) {
            if (s[i][j] != 4) {
                write("No");
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(lx <= i && i <= rx && ly <= j && j <= ry)) {
                if (s[i][j]) {
                    write("No");
                }
            }
        }
    }
    for (int i = lx + 1; i < rx; ++i) {
        if (s[i][ly] != 2 || s[i][ry] != 2) {
            write("No");
        }
    }
    for (int i = ly + 1; i < ry; ++i) {
        if (s[lx][i] != 2 || s[rx][i] != 2) {
            write("No");
        }
    }
    write("Yes");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int lx = inf, ly = inf;
    int rx = -inf, ry = -inf;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < n; ++j) {
            s[i][j] -= '0';
            sum += s[i][j];
            ++cnt[s[i][j]];
            if (s[i][j] == 1) {
                lx = min(lx, i);
                rx = max(rx, i);
                ly = min(ly, j);
                ry = max(ry, j);
            }
        }
    }
    if (sum == 0 || cnt[3] || cnt[1] != 4 || sum == 4) {
        write("No");
    }
    check(lx, rx, ly, ry);
    return 0;
}