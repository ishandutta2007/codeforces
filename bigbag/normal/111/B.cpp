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

const int max_n = 111111, inf = 1111111111;

int n, ans, x[max_n], y[max_n], last[max_n];

void proc(int d, int num) {
    if (last[d] < num) {
        ++ans;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(last, -1, sizeof(last));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        ans = 0;
        for (int d = 1; d * d <= x[i]; ++d) {
            if (x[i] % d == 0) {
                proc(d, i - y[i]);
                if (d != x[i] / d) {
                    proc(x[i] / d, i - y[i]);
                }
            }
        }
        printf("%d\n", ans);
        for (int d = 1; d * d <= x[i]; ++d) {
            if (x[i] % d == 0) {
                last[d] = i;
                last[x[i] / d] = i;
            }
        }
    }
    return 0;
}