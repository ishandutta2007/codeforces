#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<multimap<int, int>> T; 
    SegmentTree(int n) : T(n + 1) {}
    set<int> available;

    void Insert(int l, int r, int idx) {
        for (++l; l > 0; l -= (l & (-l)))
            T[l].emplace(r, idx);
        available.insert(idx);
    }
    int Query(int l, int r) {
        for (++l; l < (int)T.size(); l += (l & (-l))) {
            while (true) {
                if (T[l].empty() or T[l].begin()->first > r) 
                    break;
                auto now = (*T[l].begin());
                T[l].erase(T[l].begin());
                if (available.count(now.second)) {
                    available.erase(now.second);
                    return now.second;
                }
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, int, int, int>> events;
    vector<int> all;

    for (int i = 0; i < n; ++i) {
        int s, f, t; cin >> s >> f >> t;
        events.emplace_back(t, 1, s, f, i);
        all.push_back(s);
    }
    for (int i = 0; i < m; ++i) {
        int l, r, b; cin >> l >> r >> b;
        events.emplace_back(b, 0, l, r, i);
        all.push_back(l);
    }

    sort(events.begin(), events.end());
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    SegmentTree st(all.size());
    vector<int> ans(m, -2);

    for (auto itr : events) {
        int tp, l, r, idx;
        tie(ignore, tp, l, r, idx) = itr;
        l = distance(all.begin(), lower_bound(all.begin(), all.end(), l));

        if (tp == 0) {
            st.Insert(l, r, idx);
        } else {
            while (true) {
                int now = st.Query(l, r);
                if (now == -1) break;
                ans[now] = idx;
            }
        }
    }
    
    for (auto x : ans) 
        cout << x + 1 << ' ';
    cout << endl;

    return 0;
}