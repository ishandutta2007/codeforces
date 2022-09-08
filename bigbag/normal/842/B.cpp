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

int d, r, r1, r2, n, x, y, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &r, &d, &n);
    r1 = r - d;
    r2 = r;
    while (n--) {
        scanf("%d%d%d", &x, &y, &r);
        int sq = x * x + y * y;
        if (sq >= (r1 + r) * (r1 + r) && r2 - r >= 0 && sq <= (r2 - r) * (r2 - r)) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}