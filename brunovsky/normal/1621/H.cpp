#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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

template <typename T>
void set_merge(set<T>& a, set<T>& b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    a.merge(b);
}

int mod(int64_t n, int m) { return n %= m, n <= 0 ? (n + m) : n; }
int64_t floordiv(int64_t n, int d) { return n == 0 ? -1 : (n - 1) / d; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v, t;
        cin >> u >> v >> t, u--, v--;
        tree[u].push_back({v, t});
        tree[v].push_back({u, t});
    }
    int K;
    string zone_string;
    cin >> K >> zone_string;
    vector<int> zone(N);
    for (int i = 0; i < N; i++) {
        zone[i] = zone_string[i] - 'A';
    }
    assert(*max_element(begin(zone), end(zone)) < K);
    vector<vector<pair<int, int>>> passes(K), fines(K);
    for (int k = 0; k < K; k++) {
        int cost;
        cin >> cost;
        passes[k].push_back({-1, cost});
    }
    for (int k = 0; k < K; k++) {
        int cost;
        cin >> cost;
        fines[k].push_back({-1, cost});
    }
    int T, Q;
    cin >> T >> Q;
    vector<vector<int>> queries(N);
    for (int q = 0; q < Q; q++) {
        if (int t; cin >> t, t == 1) {
            char z;
            int cost;
            cin >> ws >> z >> cost;
            assert('A' <= z && z < 'A' + K);
            passes[z - 'A'].push_back({q, cost});
        } else if (t == 2) {
            char z;
            int cost;
            cin >> ws >> z >> cost;
            assert('A' <= z && z < 'A' + K);
            fines[z - 'A'].push_back({q, cost});
        } else if (t == 3) {
            int u;
            cin >> u, u--;
            queries[u].push_back(q);
        } else {
            assert(false);
        }
    }

    vector<int64_t> len(K), pass(K), fine(K), time(K);
    vector<int64_t> ans(Q, -1);

    auto solve = [&](int q, int u, const set<int>& lens) {
        int64_t lead = 0;
        vector<array<int, 3>> events;
        for (int k = zone[u] - 1; k >= 0; k--) {
            auto query = make_pair(q, 0);
            pass[k] = prev(lower_bound(begin(passes[k]), end(passes[k]), query))->second;
            fine[k] = prev(lower_bound(begin(fines[k]), end(fines[k]), query))->second;
            time[k] = floordiv(lead + len[k], T) - floordiv(lead, T);
            int a = mod(1 - lead, T);
            int b = mod(1 - lead - len[k], T);
            events.push_back({a, k, -1}), events.push_back({b, k, +1});
            lead += len[k];
        }

        int64_t cost = 0;
        for (int k = 0; k < zone[u]; k++) {
            cost += pass[k] / fine[k] < time[k] ? pass[k] : time[k] * fine[k];
        }
        int64_t best = INT64_MAX;

        auto check = [&](int l, int r) {
            if (l == r) {
                return;
            }
            auto it = lens.lower_bound(l);
            if (it == lens.end() || *it >= r) {
                return;
            }
            best = min(best, cost);
        };

        sort(begin(events), end(events));

        int L = 0;
        for (auto [R, k, delta] : events) {
            check(L, R);
            cost -= pass[k] / fine[k] < time[k] ? pass[k] : time[k] * fine[k];
            time[k] += delta;
            cost += pass[k] / fine[k] < time[k] ? pass[k] : time[k] * fine[k];
            L = R;
        }
        check(L, T);

        return best;
    };

    y_combinator([&](auto self, int u, int p) -> set<int> {
        set<int> lens = {int(len[zone[u]] % T)};
        for (auto [v, d] : tree[u]) {
            if (v != p) {
                len[zone[v]] += d;
                auto more = self(v, u);
                if (zone[u] == zone[v]) {
                    set_merge(lens, more);
                }
                len[zone[v]] -= d;
            }
        }
        for (int q : queries[u]) {
            ans[q] = u == 0 ? 0 : solve(q, u, lens);
        }
        return lens;
    })(0, -1);

    for (int q = 0; q < Q; q++) {
        if (ans[q] >= 0) {
            cout << ans[q] << '\n';
        }
    }
    return 0;
}