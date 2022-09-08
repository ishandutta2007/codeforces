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

int n, k;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    s = " " + s;
    if (k - 1 < n - k) {
        while (k != 1) {
            cout << "LEFT" << endl;
            --k;
        }
        for (int i = 1; i <= n; ++i) {
            cout << "PRINT " << s[i] << endl;
            if (i != n) {
                cout << "RIGHT" << endl;
            }
        }
    } else {
        while (k != n) {
            cout << "RIGHT" << endl;
            ++k;
        }
        for (int i = n; i > 0; --i) {
            cout << "PRINT " << s[i] << endl;
            if (i != 1) {
                cout << "LEFT" << endl;
            }
        }
    }
    return 0;
}