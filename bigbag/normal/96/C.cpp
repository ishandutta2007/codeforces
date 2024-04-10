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

int n, f[max_n];
char mnc, mxc;
string a, s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); ++j) {
            if ('A' <= s[i][j] && s[i][j] <= 'Z') {
                s[i][j] = s[i][j] - 'A' + 'a';
            }
        }
    }
    cin >> a >> mnc;
    mxc = mnc - 'a' + 'A';
    for (int l = 0; l < a.length(); ++l) {
        for (int r = l; r < a.length(); ++r) {
            string q;
            for (int i = l; i <= r; ++i) {
                if ('A' <= a[i] && a[i] <= 'Z') {
                    q += (a[i] - 'A' + 'a');
                } else {
                    q += a[i];
                }
            }
            int fff = 0;
            for (int i = 0; i < n; ++i) {
                if (q == s[i]) {
                    fff = 1;
                    break;
                }
            }
            if (fff == 1) {
                for (int i = l; i <= r; ++i) {
                    f[i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < a.length(); ++i) {
        if (f[i] == 1) {
            if ('A' <= a[i] && a[i] <= 'Z') {
                if (a[i] == mxc) {
                    if (a[i] == 'A') {
                        a[i] = 'B';
                    } else {
                        a[i] = 'A';
                    }
                } else {
                    a[i] = mxc;
                }
            } else {
                if (a[i] == mnc) {
                    if (a[i] == 'a') {
                        a[i] = 'b';
                    } else {
                        a[i] = 'a';
                    }
                } else {
                    a[i] = mnc;
                }
            }
        }
    }
    cout << a << endl;
    return 0;
}