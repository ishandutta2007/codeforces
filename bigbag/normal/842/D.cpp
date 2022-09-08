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

const int max_n = 300333, max_l = 20, inf = 1011111111;

int n, q, x, y, last, to[2 * max_n * max_l][2], used[2 * max_n];

bool get_bit(int x, int pos) {
    return (bool) (x & (1 << pos));
}

void add(int x) {
    int cur = 0;
    for (int i = max_l - 1; i >= 0; --i) {
        int b = get_bit(x, i);
        if (to[cur][b] == 0) {
            ++last;
            to[cur][b] = last;
        }
        cur = to[cur][b];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    while (n--) {
        scanf("%d", &x);
        used[x] = 1;
    }
    for (int i = 0; i < 2 * max_n; ++i) {
        if (used[i] == 0) {
            add(i);
        }
    }
    while (q--) {
        scanf("%d", &x);
        y ^= x;
        int cur = 0, ans = 0;
        for (int i = 0; i < max_l; ++i) {
            int b = get_bit(y, max_l - i - 1);
            ans *= 2;
            if (to[cur][b] != 0) {
                cur = to[cur][b];
            } else {
                if (to[cur][b ^ 1] == 0) {
                    cout << "FAIL" << endl;
                    exit(228);
                }
                ++ans;
                cur = to[cur][b ^ 1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}