#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

struct tree {
    long long t[max_n];

    tree() {
        memset(t, 0, sizeof(t));
    }

    void update(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            t[i] += x;
        }
    }

    long long get_sum(int r) const {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    long long get_sum(int l, int r) const {
        if (l == 0) {
            return get_sum(r);
        }
        return get_sum(r) - get_sum(l - 1);
    }
};

int n, m, a[max_n], ql[max_n], qr[max_n];
int p[max_n];
long long ans[max_n];
vector<int> all[max_n], q[max_n];

void solvel() {
    vector<pair<int, int>> v;
    v.push_back({inf, -1});
    tree t1, t2;
    for (int i = 0; i < n; ++i) {
        all[i].clear();
        q[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        q[ql[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        while (a[i] > v.back().first) {
            v.pop_back();
        }
        p[i] = v.back().second + 1;
        v.push_back(make_pair(a[i], i));
        t1.update(i, p[i]);
        all[p[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int id : q[i]) {
            long long pl = t1.get_sum(ql[id], qr[id]);
            pl += t2.get_sum(ql[id], qr[id]) * ql[id];
            ans[id] -= pl;
        }
        for (int id : all[i]) {
            t1.update(id, -p[id]);
            t2.update(id, 1);
        }
    }
}

void solver() {
    vector<pair<int, int>> v;
    v.push_back({inf, n});
    tree t1, t2;
    for (int i = 0; i < n; ++i) {
        all[i].clear();
        q[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        q[qr[i]].push_back(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        while (a[i] > v.back().first) {
            v.pop_back();
        }
        p[i] = v.back().second - 1;
        v.push_back(make_pair(a[i], i));
        t1.update(i, p[i]);
        all[p[i]].push_back(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int id : q[i]) {
            long long pl = t1.get_sum(ql[id], qr[id]);
            pl += t2.get_sum(ql[id], qr[id]) * qr[id];
            ans[id] += pl;
        }
        for (int id : all[i]) {
            t1.update(id, -p[id]);
            t2.update(id, 1);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &ql[i]);
        --ql[i];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &qr[i]);
        --qr[i];
        ans[i] = qr[i] - ql[i] + 1;
    }
    solvel();
    solver();
    for (int i = 0; i < m; ++i) {
        printf("%I64d ", ans[i]);
    }
    printf("\n");
    return 0;
}