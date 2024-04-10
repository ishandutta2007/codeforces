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

const int max_n = 11, inf = 1111111111;

string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 8; ++i) {
        cin >> s[i];
    }
    int a = 11, b = 11;
    for (int i = 0; i < 8; ++i) {
        int mx1 = -1, mn1 = 11, mx2 = -1, mn2 = 11;
        for (int j = 0; j < 8; ++j) {
            if (s[j][i] == 'W') {
                mn1 = min(mn1, j);
                mx2 = max(mx2, j);
            }
            if (s[j][i] == 'B') {
                mx1 = max(mx1, j);
                mn2 = min(mn2, j);
            }
        }
        //cout << mn1 << " " << mx1 << " " << mn2 << " " << mx2 << endl;
        if (mn1 < mn2 && mn1 != 11) {
            a = min(a, mn1);
        }
        if (mx1 > mx2 && mx1 != -1) {
            b = min(b, 7 - mx1);
        }
    }
    //cout << a << " " << b << endl;
    if (a == 11) {
        cout << "B" << endl;
        return 0;
    }
    if (b == 11) {
        cout << "A" << endl;
        return 0;
    }
    if (a <= b) {
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }
    return 0;
}