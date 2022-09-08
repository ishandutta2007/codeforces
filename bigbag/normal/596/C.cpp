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

const int max_n = 111111, inf = 1111111111;

int n, x[max_n], y[max_n], a[max_n];
set<pair<int, int> > all;
set<pair<int, pair<int, int> > > q;
map<pair<int, int>, int> m;
vector<pair<int, int> > ans;

void add(int x, int y) {
    q.insert(make_pair(y - x, make_pair(x, y)));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        all.insert(make_pair(x[i], y[i]));
    }
    q.insert(make_pair(0, make_pair(0, 0)));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (q.size() == 0) {
            printf("NO\n");
            return 0;
        }
        set<pair<int, pair<int, int> > >::iterator it = q.lower_bound(make_pair(a[i], make_pair(-inf, -inf)));
        if (it == q.end()) {
            printf("NO\n");
            return 0;
        }
        pair<int, pair<int, int> > p = *it;
        if (p.first != a[i]) {
            printf("NO\n");
            return 0;
        }
        int x = p.second.first;
        int y = p.second.second;
        ans.push_back(make_pair(x, y));
        q.erase(it);
        if (x == 0) {
            if (all.count(make_pair(x, y + 1))) {
                add(x, y + 1);
            }
        }
        if (y == 0) {
            if (all.count(make_pair(x + 1, y))) {
                add(x + 1, y);
            }
        }
        ++m[make_pair(x + 1, y)];
        if (m[make_pair(x + 1, y)] == 2) {
            add(x + 1, y);
        }
        ++m[make_pair(x, y + 1)];
        if (m[make_pair(x, y + 1)] == 2) {
            add(x, y + 1);
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}