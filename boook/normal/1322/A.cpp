#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int pre = 0;
    int tmp = 0;
    int len = 0;
    for (char c: s) {
        if (c == '(') {
            ++pre; ++len;
        }
        else {
            --pre; ++len;
        }
        if (pre == 0) {
            //ans -= min(tmp, 0);
            if (tmp < 0) {
                ans += len;
            }
            tmp = 0;
            len = 0;
        }
        else {
            tmp = min(tmp, pre);
        }
    }
    if (pre != 0) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}