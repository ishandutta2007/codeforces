#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T>
void setmin(T& a, T b) {
    a = min(a, b);
}

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename T, typename Compare = less<T>>
auto cartesian_tree(const vector<T>& arr, const Compare& cmp = Compare()) {
    int N = arr.size();
    vector<int> parent(N, -1);
    vector<array<int, 2>> kids(N, {-1, -1});

    for (int i = 1; i < N; i++) {
        int p = i - 1;
        while (parent[p] != -1 && cmp(arr[i], arr[p])) {
            p = parent[p];
        }
        if (cmp(arr[i], arr[p])) {
            parent[i] = parent[p], kids[i][0] = p;
        } else {
            parent[i] = p, kids[i][0] = kids[p][1];
        }
        if (parent[i] != -1) {
            kids[parent[i]][1] = i;
        }
        if (kids[i][0] != -1) {
            parent[kids[i][0]] = i;
        }
    }

    int root = N - 1;
    while (parent[root] != -1)
        root = parent[root];

    return make_tuple(root, move(parent), move(kids));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N), w(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> w[i];
    }

    auto compute = [&](int l, int r) { return abs(x[l] - x[r]) * int64_t(w[l] + w[r]); };

    vector<vector<pair<int, int>>> queries(N);
    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r, l--, r--;
        queries[r].push_back({q, l});
    }

    int root;
    vector<int> parent;
    vector<array<int, 2>> kids;
    tie(root, parent, kids) = cartesian_tree(w);

    vector<int64_t> ans(Q);
    vector<vector<int>> cands(N);
    y_combinator([&](auto self, int u) -> void {
        if (int l = kids[u][0]; l != -1) {
            self(l);
            while (l != -1) {
                cands[u].push_back(l);
                l = kids[l][1];
            }
        }
        if (int r = kids[u][1]; r != -1) {
            self(r);
            while (r != -1) {
                cands[r].push_back(u);
                r = kids[r][0];
            }
        }
    })(root);

    map<int, int64_t> opt;

    for (int r = 1; r < N; r++) {
        auto d = compute(r - 1, r);
        while (!opt.empty() && opt.rbegin()->second >= d) {
            opt.erase(std::prev(opt.end()));
        }
        opt.emplace(r - 1, d);

        for (int l : cands[r]) {
            auto c = compute(l, r);
            auto it = opt.lower_bound(l);
            if (it->second > c) {
                if (it->first == l) {
                    it->second = c;
                } else {
                    it = opt.emplace(l, c).first;
                }
                while (it != opt.begin() && std::prev(it)->second >= c) {
                    opt.erase(std::prev(it));
                }
            }
        }

        for (auto [q, l] : queries[r]) {
            ans[q] = opt.lower_bound(l)->second;
        }
    }

    for (int q = 0; q < Q; q++) {
        cout << ans[q] << '\n';
    }
    return 0;
}