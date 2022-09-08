/**
 *  created: 06/03/2021, 16:09:17
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, h, m, x, y;

int rev(int x) {
    vector<int> v;
    for (int i = 0; i < 2; ++i) {
        int d = x % 10;
        x /= 10;
        if (d != 0 && d != 1 && d != 2 && d != 5 && d != 8) {
            return -1;
        }
        if (d == 2 || d == 5) {
            d ^= 2 ^ 5;
        }
        v.push_back(d);
    }
    return v[0] * 10 + v[1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d:%d", &h, &m, &x, &y);
        while (true) {
            int a = rev(y), b = rev(x);
            if (a == -1 || b == -1 || a >= h || b >= m) {
            } else {
                printf("%02d:%02d\n", x, y);
                break;
            }
            ++y;
            if (y == m) {
                y = 0;
                ++x;
                if (x == h) {
                    x = 0;
                }
            }
        }
    }
    return 0;
}