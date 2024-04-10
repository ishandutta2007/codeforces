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

int n, m, s, f, t;

int ans() {
    if (s == f) {
        return t;
    }
    if (s < f) {
        int d = 2 * (m - 1);
        t += 1 - s;
        int k = max(0, t / d);
        while (k * d < t) {
            ++k;
        }
        return k * d + f - 1;
    }
    int d = 2 * (m - 1);
    t += s - m - m + 1;
    int k = max(0, t / d);
    while (k * d < t) {
        ++k;
    }
    return m - 1 + k * d + m - f;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%d%d%d", &s, &f, &t);
        printf("%d\n", ans());
    }
    return 0;
}