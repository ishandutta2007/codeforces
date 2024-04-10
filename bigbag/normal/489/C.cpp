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

int n, s, f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    if (s == 0) {
        if (n == 1) {
            cout << "0 0" << endl;
        } else {
            cout << "-1 -1" << endl;
        }
        return 0;
    }
    if (s > 9 * n || s == 0) {
        cout << "-1 -1" << endl;
        return 0;
    }
    int k = n, ss = s;
    while (n--) {
        int st = 0;
        if (f == 0) st = 1, f = 1;
        for (int i = st; i < 10; ++i) {
            if (s - i <= 9 * n) {
                s -= i;
                cout << i;
                break;
            }
        }
    }
    cout << " ";
    n = k;
    s = ss;
    f = 0;
    while (n--) {
        int st = 0;
        if (f == 0) st = 1, f = 1;
        for (int i = 9; i >= st; --i) {
            if (s - i >= 0 && s - i <= 9 * n) {
                s -= i;
                cout << i;
                break;
            }
        }
    }
    return 0;
}