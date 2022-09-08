/**
 *  created: 31/05/2022, 17:58:00
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 201111, inf = 1000111222;

template<typename T>
struct segment_tree {
    T mx[4 * max_n];
    multiset<T> all[4 * max_n];

    void build(int v, int l, int r) {
        all[v].clear();
        if (l == r) {
            mx[v] = {-inf, -inf};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            all[v].insert(value);
            mx[v] = *all[v].rbegin();
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void erase(int v, int l, int r, int pos, T value) {
        if (l == r) {
            all[v].erase(all[v].find(value));
            if (all[v].empty()) {
                mx[v] = {-inf, -inf};
            } else {
                mx[v] = *all[v].rbegin();
            }
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            erase(2 * v, l, mid, pos, value);
        } else {
            erase(2 * v + 1, mid + 1, r, pos, value);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int t, n, c[max_n], l[max_n], r[max_n];
segment_tree<pair<int, int>> st[2];
vector<int> v;
multiset<array<int, 3>> all;

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void dfs(int c, int l, int r) {
    //cout << "@@" << c << " " << l << " " << r << endl;
    all.erase(all.find({c, l, r}));
    st[c].erase(1, 0, v.size(), l, {r, l});
    while (true) {
        auto [R, L] = st[c ^ 1].get_max(1, 0, v.size(), 0, r);
        //cout << "#" << c << " " << l << " " << r << ": " << L << " " << R << endl;
        if (R >= l) {
            dfs(c ^ 1, L, R);
        } else {
            break;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        v.clear();
        for (int i = 0; i < n; ++i) {
            cin >> c[i] >> l[i] >> r[i];
            v.push_back(l[i]);
            v.push_back(r[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        st[0].build(1, 0, v.size());
        st[1].build(1, 0, v.size());
        for (int i = 0; i < n; ++i) {
            l[i] = compress(l[i]);
            r[i] = compress(r[i]);
            st[c[i]].update(1, 0, v.size(), l[i], {r[i], l[i]});
            all.insert({c[i], l[i], r[i]});
        }
        int ans = 0;
        while (!all.empty()) {
            ++ans;
            auto [c, l, r] = *all.begin();
            dfs(c, l, r);
        }
        cout << ans << "\n";
    }
    return 0;
}