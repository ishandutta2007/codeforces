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

const int max_n = 222, inf = 1111111111;

int n, ans, a[max_n], b[max_n];
string s;

int get1(int l, int r) {
    if (l == 0) {
        return a[r];
    }
    return a[r] - a[l - 1];
}

int get2(int l, int r) {
    if (l == 0) {
        return b[r];
    }
    return b[r] - b[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            a[i] = 1;
        } else if (s[i] == 'D') {
            a[i] = -1;
        } else if (s[i] == 'L') {
            b[i] = 1;
        } else {
            b[i] = -1;
        }
        if (i) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (get1(i, j) == 0 && get2(i, j) == 0) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}