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

const int max_n = 1, inf = 1111111111;

int n, a, b, x, y, v;
long double ans = inf;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> n;
    while (n--) {
        cin >> x >> y >> v;
        ans = min(ans, sqrt((long double) ((x - a) * (x - a) + (y - b) * (y - b))) / v);
    }
    printf("%.10f\n", (double) ans);
    return 0;
}