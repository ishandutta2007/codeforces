#include <map>
#include <set>
#include <stack>
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

int n;
pair<int, pair<int, int> > p[max_n];

bool ok(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long res = (x2 - x1) * (y2 + y1) + (x3 - x2) * (y3 + y2) + (x1 - x3) * (y1 + y3);
    return res != 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second.first);
        p[i].second.second = i;
    }
    sort(p, p + n);
    for (int i = 0; i + 2 < n; ++i) {
        if (ok(p[i].first, p[i].second.first, p[i + 1].first, p[i + 1].second.first, p[i + 2].first, p[i + 2].second.first)) {
            printf("%d %d %d\n", p[i].second.second + 1, p[i + 1].second.second + 1, p[i + 2].second.second + 1);
            return 0;
        }
    }
    return 0;
}