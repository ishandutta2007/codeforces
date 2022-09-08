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

const int max_n = 111111, inf = 1111111111;

string s[3];
int a[3][33], q[33];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s[0] >> s[1] >> s[2];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < s[i].length(); ++j) {
            ++a[i][s[i][j] - 'a'];
        }
    }
    int ans = 0, ansx = 0, ansy = 0;
    for (int resx = 0; ; ++resx) {
        int resy = inf;
        for (int j = 0; j < 26; ++j) {
            if (a[2][j]) {
                resy = min(resy, a[0][j] / a[2][j]);
            }
        }
        if (ans < resx + resy) {
            ans = resx + resy;
            ansx = resx;
            ansy = resy;
            for (int j = 0; j < 26; ++j) {
                q[j] = a[0][j] - resy * a[2][j];
            }
        }
        for (int j = 0; j < 26; ++j) {
            a[0][j] -= a[1][j];
            if (a[0][j] < 0) {
                resy = -1;
                break;
            }
        }
        if (resy == -1) {
            break;
        }
    }
    if (ans == 0) {
        cout << s[0] << endl;
        return 0;
    }
    for (int i = 0; i < ansx; ++i) {
        cout << s[1];
    }
    for (int i = 0; i < ansy; ++i) {
        cout << s[2];
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < q[i]; ++j) {
            printf("%c", 'a' + i);
        }
    }
    cout << endl;
    return 0;
}