/**
 *  created: 21/12/2020, 14:36:09
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

template<typename T>
struct segment_tree {
    T mn[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            mn[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            mn[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    T get_min(int v, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) {
            return inf;
        }
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

struct point {
    int x, y, id;

    void read() {
        scanf("%d%d", &x, &y);
    }

    int diff() const {
        return y - x;
    }
};

bool cmp_by_diff(const point &a, const point &b) {
    return a.diff() < b.diff();
}

bool cmp_by_x(const point &a, const point &b) {
    return a.x < b.x;
}

bool cmp_by_y(const point &a, const point &b) {
    return a.y < b.y;
}

int n, m, pos[max_n];
bool ans[max_n];
point a[max_n], ax[max_n], ay[max_n], b[max_n];
set<pair<int, int>> all_bad, all_q[max_n];
vector<int> v, diff;
segment_tree<int> tx, ty;

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void proc_ray(int x, int y, int len) {
    //cout << x << " " << y << " " << len << endl;
    int pos = compress(y - x);
    if (pos < v.size() && v[pos] == y - x) {
        while (true) {
            auto it = all_q[pos].lower_bound({x, -1});
            if (it != all_q[pos].end() && it->first < x + len) {
                //cout << "#" << it->second << endl;
                ans[it->second] = 1;
                all_q[pos].erase(it);
            } else {
                break;
            }
        }
    }
}

void solve() {
    sort(a, a + n, cmp_by_diff);
    for (int i = 0; i < n; ++i) {
        diff.push_back(a[i].diff());
        ax[i] = a[i];
        ay[i] = a[i];
        pos[a[i].id] = i;
        tx.update(1, 0, n - 1, i, a[i].x);
        ty.update(1, 0, n - 1, i, a[i].y);
    }
    sort(ax, ax + n, cmp_by_x);
    sort(ay, ay + n, cmp_by_y);
    int posx = 0, posy = 0;
    int x0 = 0, y0 = 0;
    while (x0 < inf && y0 < inf) {
        while (posx < n && ax[posx].x < x0) {
            tx.update(1, 0, n - 1, pos[ax[posx].id], inf);
            ++posx;
        }
        while (posy < n && ay[posy].y < y0) {
            ty.update(1, 0, n - 1, pos[ay[posy].id], inf);
            ++posy;
        }
        int X = tx.get_min(1, 0, n - 1, 0, upper_bound(diff.begin(), diff.end(), y0 - x0) - diff.begin() - 1);
        int Y = ty.get_min(1, 0, n - 1, lower_bound(diff.begin(), diff.end(), y0 - x0) - diff.begin(), n - 1);
        int len = min(X - x0, Y - y0);
        proc_ray(x0, y0, len);
        bool add_x = (x0 + len) == X;
        bool add_y = (y0 + len) == Y;
        x0 += len;
        y0 += len;
        x0 += add_x;
        y0 += add_y;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        a[i].read();
        a[i].id = i;
    }
    for (int i = 0; i < m; ++i) {
        b[i].read();
        b[i].id = i;
    }
    for (int i = 0; i < n; ++i) {
        all_bad.insert({a[i].x, a[i].y});
    }
    for (int i = 0; i < m; ++i) {
        ans[i] = all_bad.count({b[i].x, b[i].y});
        v.push_back(b[i].diff());
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < m; ++i) {
        all_q[compress(b[i].diff())].insert({b[i].x, b[i].id});
    }
    solve();
    for (int i = 0; i < m; ++i) {
        if (ans[i]) {
            puts("LOSE");
        } else {
            puts("WIN");
        }
    }
    return 0;
}