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

struct tree {
    vector<int> v;
    int mn[4 * max_n];
    tree() {
        v.clear();
        for (int i = 0; i < 4 * max_n; ++i) {
            mn[i] = inf;
        }
    }
    void add(int x) {
        v.push_back(x);
    }
    void proc() {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    int get_num(int x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    }
    void update(int v, int tl, int tr, int poz, int x) {
        if (tl == tr) {
            mn[v] = x;
            return;
        }
        int mid = (tl + tr) / 2;
        if (poz <= mid) {
            update(2 * v, tl, mid, poz, x);
        } else {
            update(2 * v + 1, mid + 1, tr, poz, x);
        }
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }
    int get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, q, x[max_n], y[max_n];
set<int> s;
char c[max_n];
tree t1, t2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%c%c", &y[i], &x[i], &c[i], &c[i]);
        --x[i];
        --y[i];
        t1.add(y[i]);
        t2.add(x[i]);
    }
    t1.proc();
    t2.proc();
    for (int i = 0; i < q; ++i) {
        if (s.count(x[i])) {
            printf("0\n");
            continue;
        }
        if (c[i] == 'L') {
            int num = t1.get_num(y[i]);
            int l = -1, r = num;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (t1.get_min(1, 0, t1.v.size() - 1, mid, num) <= x[i]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (l != -1) {
                l = t1.v[l];
            }
            printf("%d\n", t1.v[num] - l);
            t2.update(1, 0, t2.v.size() - 1, t2.get_num(x[i]), l + 1);
        } else {
            int num = t2.get_num(x[i]);
            int l = -1, r = num;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (t2.get_min(1, 0, t2.v.size() - 1, mid, num) <= y[i]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (l != -1) {
                l = t2.v[l];
            }
            printf("%d\n", t2.v[num] - l);
            t1.update(1, 0, t1.v.size() - 1, t1.get_num(y[i]), l + 1);
        }
        s.insert(x[i]);
    }
    return 0;
}