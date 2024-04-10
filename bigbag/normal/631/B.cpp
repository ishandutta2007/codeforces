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

const int max_n = 5055, inf = 1111111111;

int n, m, q, last[2][max_n], t[2][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; ++i) {
        int tp, x, c;
        scanf("%d%d%d", &tp, &x, &c);
        --tp;
        --x;
        last[tp][x] = c;
        t[tp][x] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t[0][i] > t[1][j]) {
                printf("%d ", last[0][i]);
            } else {
                printf("%d ", last[1][j]);
            }
        }
        printf("\n");
    }
    return 0;
}