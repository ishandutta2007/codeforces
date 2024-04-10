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

int res, mx, n, m, a[max_n], ans[max_n], cnt[max_n];
pair<int, int> b[max_n];
set<pair<int, int> > q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        q.insert(make_pair(a[i], i));
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    sort(b, b + m);
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < m; ++i) {
        int x = b[i].first, c = 0;
        while (x) {
            set<pair<int, int> >::iterator it = q.lower_bound(make_pair(x, -1));
            if (it != q.end()) {
                pair<int, int> p = *it;
                if (x == p.first) {
                    ans[p.second] = b[i].second;
                    cnt[b[i].second] = c;
                    res += c;
                    ++mx;
                    q.erase(it);
                    break;
                }
            }
            ++c;
            if (x == 1) {
                break;
            }
            x = (x + 1) / 2;
        }
    }
    printf("%d %d\n", mx, res);
    for (int i = 0; i < m; ++i) {
        printf("%d ", cnt[i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
    return 0;
}