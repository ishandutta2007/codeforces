#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    vector<int> data;
    Fenwick(int len): data(len + 10) {}
    void upd(int i, int d) {
        for (++i; i < (int)data.size(); i += i & -i)
            data[i] = max(data[i], d);
    }
    int get(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans = max(ans, data[i]);
        return ans;
    }
};

struct Tree {
    int x, h, id;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<Tree> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].h;
        a[i].id = i;
    }
    
    vector<int> vals;
    for (auto it: a) {
        vals.push_back(it.x);
        vals.push_back(it.x + it.h);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto val_id = [&](int v) {
        return (int)(lower_bound(vals.begin(), vals.end(), v) - vals.begin());
    };
    
    sort(a.begin(), a.end(), [&](const Tree& u, const Tree& v) {
            return u.x < v.x;
            });
    vector<int> ans(n);
    Fenwick bit((int)vals.size());
    for (int i = n; i--; ) {
        auto xid = val_id(a[i].x);
        auto right_id = val_id(a[i].x + a[i].h);
        int mx_pos = max(i, bit.get(right_id - 1));
        ans[a[i].id] = mx_pos - i + 1;
        bit.upd(xid, mx_pos);
    }
    for (auto i: ans) cout << i << ' ';
    
    return 0;
}