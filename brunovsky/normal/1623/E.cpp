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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;
    s = 'a' + s;

    vector<int> l(N + 1), r(N + 1);
    for (int u = 1; u <= N; u++) {
        cin >> l[u] >> r[u];
    }

    vector<int> index(N), ancestor(N + 1), parent(N + 1), depth(N + 1);
    int timer = 0;

    y_combinator([&](auto self, int u, int p, int a) -> void {
        if (u) {
            self(l[u], u, a);
            index[timer++] = u;
            parent[u] = p;
            ancestor[u] = a;
            depth[u] = depth[p] + 1;
            self(r[u], u, u);
        }
    })(1, 0, 0);

    // The next character after this node
    // If [b]b..bb[c] or [b]c we want to duplicate
    // If [b]b..bb[a] or [b]a we don't want to duplicate
    // We can imagine an 'a' at the end, so we don't want to duplicate that either
    vector<int8_t> dups(N + 1);
    for (int i = N - 1, v = 0; i >= 0; v = index[i--]) {
        int u = index[i];
        if (s[u] == s[v]) {
            dups[u] = dups[v];
        } else if (s[u] > s[v]) {
            dups[u] = false;
        } else {
            dups[u] = true;
        }
    }

    // Decompose into left paths and binary search on each
    vector<vector<int>> paths;
    y_combinator([&](auto self, int u, int p) -> void {
        if (u) {
            if (u == l[p]) {
                paths.back().push_back(u);
            } else {
                paths.push_back({u});
            }
            self(l[u], u);
            self(r[u], u);
        }
    })(1, 0);

    // Now greedily duplicate furthest left
    vector<int8_t> actual(N + 1);
    for (auto& path : paths) {
        int L = path.size();
        int p = path.front();
        int a = parent[p];
        // The ancestor of p isn't getting duplicated, so we can't match
        if (a && !actual[a]) {
            continue;
        }
        // Walk down the path and pick deepest that wants to be duplicated
        int v = -1;
        for (int i = 0; i < L && i + 1 <= K; i++) {
            if (dups[path[i]]) {
                v = path[i];
            }
        }
        if (v != -1) {
            do {
                actual[v] = true, K--;
                v = parent[v];
            } while (v != a);
        }
    }

    string ans;
    for (int u : index) {
        if (actual[u]) {
            ans += s[u];
            ans += s[u];
        } else {
            ans += s[u];
        }
    }

    cout << ans << '\n';
    return 0;
}

// We can duplicate up to k nodes only!
// Suppose we brute force DP.
// There's an issue where we don't know if we should duplicate without looking at ancestor
// stuff. How to get rid of this nuisance?

// This will TLE on left line