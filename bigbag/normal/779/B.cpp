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

const int max_n = 1, inf = 1011111111;

string n;
int x, k;

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    x = 1;
    while (k--) {
        x *= 10;
    }
    int ans = inf;
    if (n.find('0') < n.length()) {
        ans = n.length() - 1;
    }
    for (int mask = 1; mask < (1 << n.length()); ++mask) {
        int y = 0, cnt = 0;
        for (int i = 0; i < n.length(); ++i) {
            if (get_bit(mask, i)) {
                if (y == 0 && n[i] == '0') {
                    y = -1;
                    break;
                }
                y = y * 10 + n[i] - '0';
            } else {
                ++cnt;
            }
        }
        if (y % x == 0) {
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}