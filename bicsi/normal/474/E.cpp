#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    vector<pair<int, int>> T;
    SegmentTree(int n) : n(n), T(4 * n, make_pair(-1, -1)) {}

    void update(int node, int b, int e, int pos, pair<int, int> val) {
        if (b == e) {
            assert(b == pos);
            T[node] = max(T[node], val);
        } else {
            int m = (b + e) / 2;
            if (pos <= m) update(node * 2, b, m, pos, val);
            else update(node * 2 + 1, m + 1, e, pos, val);
            T[node] = max(T[node * 2], T[node * 2 + 1]);
        }
    }
    void Update(int pos, int val, int idx) {
        update(1, 0, n - 1, pos, make_pair(val, idx));
    }

    pair<int, int> query(int node, int b, int e, int l, int r) {
        if (l > r) return T[node];
        if (b == l && e == r) return make_pair(-1, -1);
        int m = (b + e) / 2;
        return max(
            query(node * 2, b, m, l, min(r, m)),
            query(node * 2 + 1, m + 1, e, max(m + 1, l), r)
        );
    }
    int Query(int l, int r) {
        auto ret = query(1, 0, n - 1, l + 1, r - 1);
        return ret.second;
    }
};

int main() {
    int n, d; cin >> n >> d;

    vector<long long> all, V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
        all.push_back(V[i]);
        all.push_back(V[i] + d);
        all.push_back(V[i] - d);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    auto norm = [&](long long x) {
        auto it = lower_bound(all.begin(), all.end(), x);
        assert(*it == x);
        return distance(all.begin(), it);
    };

    vector<int> dp(n), par(n);
    SegmentTree st(all.size());
    pair<int, int> best{-1, -1};

    for (int i = n - 1; i >= 0; --i) {
        par[i] = st.Query(norm(V[i] - d), norm(V[i] + d));
        dp[i] = (par[i] == -1 ? 0 : 1 + dp[par[i]]);
        best = max(best, make_pair(dp[i], i));
        st.Update(norm(V[i]), dp[i], i);
    }
    
    cout << best.first + 1 << endl;
    for (int i = best.second; i != -1; i = par[i])
        cout << i + 1 << " ";
    cout << endl;

    return 0;
}