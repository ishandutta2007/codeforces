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

int x, res;
string s, ans;

bool ok(int h) {
    if (x == 12) {
        return 1 <= h && h <= 12;
    }
    return 0 <= h && h <= 23;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> s;
    res = inf;
    for (int a = 0; a <= 9; ++a) {
        for (int b = 0; b <= 9; ++b) {
            int h = a * 10 + b;
            for (int c = 0; c <= 9; ++c) {
                for (int d = 0; d <= 9; ++d) {
                    int m = c * 10 + d;
                    if (ok(h) && m < 60) {
                        int cnt = (a != (s[0] - '0')) + (b != (s[1] - '0')) + (c != (s[3] - '0')) + (d != (s[4] - '0'));
                        //cout << h << " " << cnt << endl;
                        if (cnt < res) {
                            res = cnt;
                            ans = s;
                            ans[0] = a + '0';
                            ans[1] = b + '0';
                            ans[3] = c + '0';
                            ans[4] = d + '0';
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}