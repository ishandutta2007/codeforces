#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

struct vertex {
    ll val;
    int l, r;
    vertex(ll val, int l, int r) : val(val), l(l), r(r) {}
};

vector<vertex> pst;

ll get(int cv) {
    if (cv == -1) {
        return 0;
    }
    return pst[cv].val;
}

int build(int l, int r) {
    if (l + 1 == r) {
        pst.push_back({0, -1, -1});
    }
    else {
        int mid = l + (r - l) / 2;
        int ls = build(l, mid);
        int rs = build(mid, r);
        pst.push_back({0, ls, rs});
    }
    return pst.size() - 1;
}

int change(int l, int r, int ind, int cv) {
    if (l + 1 == r) {
        pst.push_back({1, -1, -1});
    }
    else {
        int mid = l + (r - l) / 2;
        if (ind < mid) {
            int ls = change(l, mid, ind, pst[cv].l);
            pst.push_back({get(ls) + get(pst[cv].r), ls, pst[cv].r});
        }
        else {
            int rs = change(mid, r, ind, pst[cv].r);
            pst.push_back({get(rs) + get(pst[cv].l), pst[cv].l, rs});
        }
    }
    return pst.size() - 1;
}

ll get_sum(int l, int r, int cl, int cr, int lt, int rt) {
    if (l == cl && r == cr) {
        return pst[rt].val - pst[lt].val;
    }
    if (cr <= cl) {
        return 0;
    }
    int mid = l + (r - l) / 2;
    return get_sum(l, mid, cl, min(mid, cr), pst[lt].l, pst[rt].l) +
           get_sum(mid, r, max(mid, cl), cr, pst[lt].r, pst[rt].r);
}

int main() {
    int n, m;
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<int> version;
    version.push_back(build(0, n));
    for (int i = 0; i < n; ++i) {
        int ind;
        cin >> ind;
        version.push_back(change(0, n, ind - 1, version.back()));
    }
    for (int i = 0; i < m; ++i) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        ll s1, s2, s3, s4, s5, s6, s7, s8, s9;
        s1 = get_sum(0, n, 0, d - 1, version[0], version[l - 1]);
        s7 = get_sum(0, n, u, n, version[0], version[l - 1]);
        s3 = get_sum(0, n, 0, d - 1, version[r], version[n]);
        s9 = get_sum(0, n, u, n, version[r], version[n]);
        s2 = d - 1 - s1 - s3;
        s4 = l - 1 - s1 - s7;
        s8 = n - u - s7 - s9;
        s6 = n - r - s9 - s3;
        s5 = n - s1 - s2 - s3 - s4 - s6 - s7 - s8 - s9;
        cout << s5 * (s5 - 1) / 2 + s1 * (s5 + s6 + s8 + s9) +
                s2 * (s4 + s5 + s6 + s7 + s8 + s9) +
                s3 * (s5 + s4 + s8 + s7) +
                s4 * (s5 + s6 + s8 + s9) +
                s5 * (s6 + s7 + s8 + s9) +
                s6 * (s7 + s8) << endl;
    }
}