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

const int max_n = 222222, inf = 1011111111;

int n, m, ans, x, y, a[max_n], used[max_n];
set<int> all[2], q;
vector<int> f;

void wa() {
    printf("-1\n");
    exit(0);
}

void answer() {
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    exit(0);
}

int get(int num) {
    int mn = *all[num].begin();
    all[num].erase(all[num].find(mn));
    return mn;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    m = min(m, 2 * max_n);
    for (int i = 1; i <= m; ++i) {
        all[i % 2].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (all[a[i] % 2].count(a[i])) {
            all[a[i] % 2].erase(a[i]);
        }
        if (!q.count(a[i])) {
            q.insert(a[i]);
            if (a[i] % 2 == 0) {
                ++x;
            } else {
                ++y;
            }
        } else {
            used[i] = 0;
            f.push_back(i);
        }
    }
    while (f.size() && x < y && all[0].size()) {
        int pos = f.back();
        f.pop_back();
        ++ans;
        a[pos] = get(0);
        ++x;
    }
    while (f.size() && y < x && all[1].size()) {
        int pos = f.back();
        f.pop_back();
        ++ans;
        a[pos] = get(1);
        ++y;
    }
    if (f.size()) {
        if (x == y) {
            while (f.size() >= 2) {
                if (all[0].size() == 0 || all[1].size() == 0) {
                    wa();
                }
                int pos1 = f.back();
                f.pop_back();
                int pos2 = f.back();
                f.pop_back();
                a[pos1] = get(0);
                a[pos2] = get(1);
                ++ans;
                ++ans;
            }
        } else {
            wa();
        }
        answer();
    }
    if (x == y) {
        answer();
    }
    if (x < y) {
        for (int i = 0; i < n && x < y; ++i) {
            if (used[i] == 0 && a[i] % 2 == 1) {
                if (all[0].size() == 0) {
                    wa();
                }
                --y;
                ++x;
                a[i] = get(0);
                ++ans;
            }
        }
    }
    if (x > y) {
        for (int i = 0; i < n && x > y; ++i) {
            if (used[i] == 0 && a[i] % 2 == 0) {
                if (all[1].size() == 0) {
                    wa();
                }
                ++y;
                --x;
                a[i] = get(1);
                ++ans;
            }
        }
    }
    if (x == y) {
        answer();
    }
    wa();
    return 0;
}