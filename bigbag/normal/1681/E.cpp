/**
 *  created: 23/05/2022, 19:16:46
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111;
const int max_v = 4 * max_n;
const long long inf = 1000111222000111222;;

struct Point {
    int x, y;

    void read() {
        cin >> x >> y;
        //cout << "$ " << x << " " << y << endl;
        --x;
        --y;
    }
};

struct State {
    int lev_start, lev_fin;
    long long d[2][2];

    State() {
        d[0][0] = inf;
        d[0][1] = inf;
        d[1][0] = inf;
        d[1][1] = inf;
    }
};

Point p[max_n][2], nxt[max_n][2];

int get_dist(const Point &a, const Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

State merge(const State &a, const State &b) {
    State res;
    res.lev_start = a.lev_start;
    res.lev_fin = b.lev_fin;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int q = 0; q < 2; ++q) {
                for (int w = 0; w < 2; ++w) {
                    res.d[i][w] = min(res.d[i][w],
                                      a.d[i][j] + b.d[q][w] + 1 + get_dist(nxt[a.lev_fin][j], p[b.lev_start][q]));
                }
            }
        }
    }
    return res;
}

struct segment_tree {
    State s[max_v];

    void build(int v, int l, int r, Point a[max_n][2]) {
        if (l == r) {
            s[v].lev_start = l;
            s[v].lev_fin = l;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    s[v].d[i][j] = get_dist(a[l][i], a[l][j]);
                }
            }
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        s[v] = merge(s[2 * v], s[2 * v + 1]);
    }

    State get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return s[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return merge(get_sum(2 * v, tl, mid, l, mid),
                     get_sum(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, m;
segment_tree st;

int get_lev(const Point &p) {
    return max(p.x, p.y);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        p[i][0].read();
        p[i][1].read();
        nxt[i][0] = p[i][0];
        nxt[i][1] = p[i][1];
        ++nxt[i][0].x;
        ++nxt[i][1].y;
    }
    st.build(1, 0, n - 2, p);
    cin >> m;
    while (m--) {
        Point p1, p2;
        p1.read();
        p2.read();
        int lev1 = get_lev(p1);
        int lev2 = get_lev(p2);
        if (lev1 == lev2) {
            cout << get_dist(p1, p2) << "\n";
            continue;
        }
        if (lev1 > lev2) {
            swap(lev1, lev2);
            swap(p1, p2);
        }
        State s = st.get_sum(1, 0, n - 2, lev1, lev2 - 1);
        long long ans = inf;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                ans = min(ans, s.d[i][j] + get_dist(p1, p[lev1][i]) + 1 + get_dist(p2, nxt[lev2 - 1][j]));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}