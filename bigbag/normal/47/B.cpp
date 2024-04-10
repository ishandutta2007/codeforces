#include <map>
#include <set>
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

int a[5][5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s[5];
    cin >> s[1] >> s[2] >> s[3];
    for (int i = 1; i < 4; ++i) {
        if (s[i][1] == '<') {
            a[s[i][2] - 'A'][s[i][0] - 'A'] = 1;
        } else {
            a[s[i][0] - 'A'][s[i][2] - 'A'] = 1;
        }
    }
    for (int i = 0; i < 3; ++i) {
        int f = 0;
        for (int j = 0; j < 3; ++j) {
            if (a[i][j] == 1) {
                f = 1;
            }
        }
        if (f == 0) {
            printf("%c", i + 'A');
            int x = 1, y = 2;
            if (i == 1) {
                x = 0;
            }
            if (i == 2) {
                y = 0;
            }
            if (a[x][y] == 1) {
                printf("%c%c", y + 'A', x + 'A');
            } else {
                printf("%c%c" ,x + 'A', y + 'A');
            }
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}