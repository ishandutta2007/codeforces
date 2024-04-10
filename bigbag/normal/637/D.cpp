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

int n, m, s, d, a[max_n], f[max_n];
vector<pair<string, int> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    f[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i + 1] - a[i] - 2 >= s) {
            f[i] = 1;
        }
    }
    int x = 0;
    for (int i = 0; i < n; ++i) {
        int len = a[i] - 1 - x;
        if (len < s) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        ans.push_back(make_pair("RUN", len));
        x = a[i] - 1;
        while (i + 1 < n && f[i] == 0) {
            ++i;
        }
        len = a[i] + 1 - x;
        if (len > d) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        ans.push_back(make_pair("JUMP", len));
        x = a[i] + 1;
    }
    if (x < m) {
        ans.push_back(make_pair("RUN", m - x));
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d\n", ans[i].first.c_str(), ans[i].second);
    }
    return 0;
}