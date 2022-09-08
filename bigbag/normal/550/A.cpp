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

const int inf = 1111111111;

int mn[2], mx[2];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    mn[0] = mn[1] = inf;
    mx[0] = mx[1] = -inf;
    for (int i = 0; i + 1 < s.length(); ++i) {
        if (s[i] == 'A' && s[i + 1] == 'B') {
            mn[0] = min(mn[0], i);
            mx[0] = max(mx[0], i);
        }
        if (s[i] == 'B' && s[i + 1] == 'A') {
            mn[1] = min(mn[1], i);
            mx[1] = max(mx[1], i);
        }
    }
    if (mn[0] == inf || mn[1] == inf) {
        cout << "NO" << endl;
        return 0;
    }
    if (mn[0] + 1 < mx[1] || mn[1] + 1 < mx[0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}