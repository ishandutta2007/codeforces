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

auto compress_uniq(vector<int>& xs) {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> xs, ys;
    vector<array<int, 2>> graph(N);
    for (auto& [x, y] : graph) {
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    compress_uniq(xs);
    compress_uniq(ys);
    int X = xs.size(), Y = ys.size();
    for (auto& [x, y] : graph) {
        x = lower_bound(begin(xs), end(xs), x) - begin(xs);
        y = lower_bound(begin(ys), end(ys), y) - begin(ys);
    }

    vector<set<pair<int, int>>> ag(X), bg(Y);
    for (int i = 0; i < N; i++) {
        auto [x, y] = graph[i];
        ag[x].emplace(y, i);
        bg[y].emplace(x, i);
    }

    auto erase_edge = [&](int i) {
        auto [x, y] = graph[i];
        ag[x].erase({y, i});
        bg[y].erase({x, i});
    };
    auto get_one_x = [&](int x) {
        auto [y, i] = *ag[x].begin();
        erase_edge(i);
        return make_pair(y, i);
    };
    auto get_one_y = [&](int y) {
        auto [x, j] = *bg[y].begin();
        erase_edge(j);
        return make_pair(x, j);
    };

    string chars = "rb";
    string ans(N, '0');

    auto process_path = [&](int u, int right) {
        vector<int> path;
        int x = u, y, i;
        if (right) {
            tie(x, i) = get_one_y(u);
            path.push_back(i);
        }
        do {
            if (ag[x].size() % 2) {
                tie(y, i) = get_one_x(x);
                path.push_back(i);
            } else {
                break;
            }
            if (bg[y].size() % 2) {
                tie(x, i) = get_one_y(y);
                path.push_back(i);
            } else {
                break;
            }
        } while (true);
        for (int i = 0, P = path.size(); i < P; i++) {
            ans[path[i]] = chars[i % 2];
        }
    };

    auto process_cycle = [&](int u) {
        vector<int> cycle;
        int x = u, y, i;
        do {
            if (ag[x].size()) {
                tie(y, i) = get_one_x(x);
                cycle.push_back(i);
            } else {
                break;
            }
            if (bg[y].size()) {
                tie(x, i) = get_one_y(y);
                cycle.push_back(i);
            } else {
                break;
            }
        } while (true);
        assert(x == u);
        for (int i = 0, P = cycle.size(); i < P; i++) {
            ans[cycle[i]] = chars[i % 2];
        }
    };

    for (int u = 0; u < X; u++) {
        if (ag[u].size() % 2) {
            process_path(u, 0);
            assert(ag[u].size() % 2 == 0);
        }
    }
    for (int v = 0; v < Y; v++) {
        if (bg[v].size() % 2) {
            process_path(v, 1);
            assert(bg[v].size() % 2 == 0);
        }
    }
    for (int u = 0; u < X; u++) {
        while (ag[u].size()) {
            process_cycle(u);
        }
    }

    cout << ans << '\n';
    return 0;
}