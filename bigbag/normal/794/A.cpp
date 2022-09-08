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

int a, b, c, n, x, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &a, &b, &c, &n);
    while (n--) {
        scanf("%d", &x);
        if (b < x && x < c) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}