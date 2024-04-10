/**
 *  created: 09/08/2021, 17:53:46
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 600666, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mx[4 * max_n];

    void push(int v, int l, int r, int mid) {
        mx[2 * v] = max(mx[2 * v], f[v]);
        mx[2 * v + 1] = max(mx[2 * v + 1], f[v]);
        f[2 * v] = max(f[2 * v], f[v]);
        f[2 * v + 1] = max(f[2 * v + 1], f[v]);
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] = max(f[v], value);
            mx[v] = max(mx[v], value);
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};


int n, m, p[max_n], ok[max_n];
vector<int> v;
vector<pair<int, int>> all[max_n];
segment_tree<pair<int, int>> st;

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int i, l, r;
        scanf("%d%d%d", &i, &l, &r);
        --i;
        v.push_back(l);
        v.push_back(r);
        all[i].push_back({l, r});
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int ans = 0, row = -1;
    for (int i = 0; i < n; ++i) {
        pair<int, int> res(0, inf);
        for (auto p : all[i]) {
            int l = compress(p.first);
            int r = compress(p.second);
            res = max(res, st.get_max(1, 0, v.size(), l, r));
        }
        ++res.first;
        p[i] = res.second;
        res.second = i;
        for (auto p : all[i]) {
            int l = compress(p.first);
            int r = compress(p.second);
            st.update(1, 0, v.size(), l, r, res);
        }
        if (res.first > ans) {
            ans = res.first;
            row = i;
        }
    }
    vector<int> res;
    while (row != inf) {
        ok[row] = 1;
        row = p[row];
    }
    for (int i = 0; i < n; ++i) {
        if (!ok[i]) {
            res.push_back(i);
        }
    }
    printf("%d\n", res.size());
    for (int id : res) {
        printf("%d ", id + 1);
    }
    puts("");
    return 0;
}