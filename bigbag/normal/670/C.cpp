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

const int max_n = 222222, inf = 1111111111;

int n, m, a[max_n], b[max_n];
map<int, int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++q[x];
    }
    pair<pair<int, int>, int> ans = make_pair(make_pair(0, 0), 0);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; ++i) {
        ans = max(ans, make_pair(make_pair(q[a[i]], q[b[i]]), i));
    }
    printf("%d\n", ans.second + 1);
    return 0;
}