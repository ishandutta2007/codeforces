#include <bits/stdc++.h>

using namespace std;

template<typename K, typename V>
struct vector_map : public vector<pair<K, V>> {
    int count(K k) {
        for (auto p : *this)
            if (p.first == k)
                return 1;
        return 0;
    }
    V& operator[](K k) {
        for (auto& p : *this)
            if (p.first == k)
                return p.second;
        this->emplace_back(k, 0);
        return this->back().second;
    }
};

struct Query { int l, r, k, idx; };

struct DNC {
    int n;
    vector<int> v;
    vector<vector<int>> pos;
    vector<vector<Query>> data;
    vector<int> ans;

    DNC(vector<int> v) : n(v.size()), v(v), pos(n + 1), data(4 * n) {
        for (int i = 0; i < n; ++i)
            pos[v[i]].push_back(i);
    }
    

    void add(int node, int b, int e, const Query& q) {
        assert(b <= q.l && e >= q.r);
        int m = (b + e) / 2;
        if (m >= q.r) return add(node * 2, b, m, q);
        if (m < q.l) return add(node * 2 + 1, m + 1, e, q);
        data[node].push_back(q);
    }

    vector<vector_map<int, int>> aux;

    void solve(int node, int b, int e) {
        if (b == e) return;
        int m = (b + e) / 2;
        solve(node * 2, b, m);
        solve(node * 2 + 1, m + 1, e);

        vector_map<int, int> vmap;

        auto trans = [&](int val) {
            if (vmap.size() < 4 || vmap.count(val)) {
                vmap[val] += 1;
                return;
            }

            for (auto& p : vmap) if (p.second == 0) {
                p = {val, 1};
                return;
            }

            for (auto& p : vmap)
                p.second -= 1;
        };
        auto combine = [&](vector_map<int, int> l, vector_map<int, int> r) {
            if (l.empty()) return r;
            if (r.empty()) return l;

            for (auto p : r) {
                if (l.size() < 4 || l.count(p.first)) 
                    l[p.first] += p.second;
                else {
                    int sub = 1e9;
                    for (auto q : l) 
                        sub = min(sub, q.second);
                    if (sub > p.second)
                        for (auto& q : l)
                            q.second -= p.second;
                    else {
                        for (auto it = l.begin(); it != l.end();) {
                            if (it->second == sub)
                                it = l.erase(it);
                            else {
                                it->second -= sub;
                                ++it;
                            }
                        }
                        if (p.second != sub)
                            l[p.first] = p.second - sub;
                    }
                }
            }
            return l;
        };

        sort(data[node].begin(), data[node].end(), [&](Query& a, Query& b) {
            return a.r < b.r;
        });
        int at = m + 1;
        for (auto q : data[node]) {
            while (at <= q.r)
                trans(v[at++]);
            aux[q.idx] = vmap;
        }


        sort(data[node].begin(), data[node].end(), [&](Query& a, Query& b) {
            return a.l > b.l;
        });
        at = m; vmap.clear();
        for (auto q : data[node]) {
            while (at >= q.l)
                trans(v[at--]);

            auto now = combine(aux[q.idx], vmap);
            int best = 1e9;
            for (auto p : now) {
                int val = p.first;
                auto it1 = lower_bound(pos[val].begin(), pos[val].end(), q.r + 1);
                auto it2 = lower_bound(pos[val].begin(), pos[val].end(), q.l);
                int cnt = it1 - it2;
                if (cnt * q.k > q.r - q.l + 1)
                    best = min(best, val); 
            }
            if (best <= n) 
                ans[q.idx] = best;
        }
    }

    vector<int> Solve(vector<Query> qs) {
        aux.resize(qs.size());
        for (auto q : qs) {
            if (q.l == q.r) {
                ans.push_back(v[q.l]);
            } else {
                add(1, 0, n - 1, q);
                ans.push_back(-1);                
            }
        }
        solve(1, 0, n - 1);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<Query> qs;
    for (int i = 0; i < q; ++i) {
        int l, r, k; cin >> l >> r >> k; --l; --r;
        qs.push_back(Query{l, r, k, i});
    }

    auto ans = DNC(v).Solve(qs);
    for (auto x : ans) 
        cout << x << '\n';
    
    return 0;
}