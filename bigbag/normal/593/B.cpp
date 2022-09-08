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

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

int n, x1, x2, k, b;
pair<long long, long long> p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x1, &x2);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &k, &b);
        p[i].first = 1LL * k * x1 + b;
        p[i].second = 1LL * k * x2 + b;
    }
    sort(p, p + n);
    long long mx = -inf, last = p[0].first, mx2 = p[0].second;
    for (int i = 1; i < n; ++i) {
        if (last != p[i].first) {
            last = p[i].first;
            mx = max(mx, mx2);
            mx2 = p[i].second;
        } else {
            mx2 = max(mx2, p[i].second);
        }
        if (mx > p[i].second) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}