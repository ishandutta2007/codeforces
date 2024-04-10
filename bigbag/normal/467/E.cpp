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

const int max_n = 555555, inf = 1111111111;

struct tree {
    pair<int, int> maxs[4 * max_n];
    void build(int v, int l, int r) {
        maxs[v] = make_pair(-1, l);
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            maxs[v] = make_pair(value, l);
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        maxs[v] = max(maxs[2 * v], maxs[2 * v + 1]);
    }
    pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return maxs[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, a[max_n], z[max_n];
tree t;
vector<int> ans, poz[max_n];
set<int> q;
map<int, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        q.insert(a[i]);
    }
    int num = 0;
    while (q.size()) {
        int x = *q.begin();
        q.erase(x);
        ++num;
        z[num] = x;
        m[x] = num;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = m[a[i]];
    }
    int lasti = -1;
    t.build(1, 0, n);
    for (int i = 0; i < n; ++i) {
        if (poz[a[i]].size() == 3) {
            ans.push_back(a[i]);
            ans.push_back(a[i]);
            ans.push_back(a[i]);
            ans.push_back(a[i]);
            for (int k = lasti + 1; k <= i; ++k) {
                poz[a[k]].clear();
            }
            lasti = i;
        } else {
            int f = 0;
            for (int j = 0; j < poz[a[i]].size(); ++j) {
                int l = poz[a[i]][j], r =i;
                if (lasti + 1 <= l - 1) {
                    pair<int, int> p = t.get_max(1, 0, n, lasti + 1, l - 1);
                    if (l < p.first && p.first < r) {
                        ans.push_back(a[p.second]);
                        ans.push_back(a[i]);
                        ans.push_back(a[p.second]);
                        ans.push_back(a[i]);
                        f = 1;
                        for (int k = lasti + 1; k <= i; ++k) {
                            poz[a[k]].clear();
                        }
                        lasti = i;
                        break;
                    }
                }
            }
            if (f == 0) {
                for (int j = 0; j < poz[a[i]].size(); ++j) {
                    t.update(1, 0, n, poz[a[i]][j], i);
                }
                poz[a[i]].push_back(i);
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", z[ans[i]]);
    }
    return 0;
}