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

const int max_n = 111, inf = 1011111111;

int n, q, t, k, d, tm[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    while (q--) {
        scanf("%d%d%d", &t, &k, &d);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (tm[i] < t) {
                ++cnt;
            }
        }
        if (cnt < k) {
            printf("-1\n");
        } else {
            int ans = 0;
            for (int i = 0; k; ++i) {
                if (tm[i] < t) {
                    --k;
                    ans += i + 1;
                    tm[i] = t + d - 1;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}