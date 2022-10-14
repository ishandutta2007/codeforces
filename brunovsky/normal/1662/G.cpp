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

auto subset_sum_filter_weights(vector<int> ws) {
    int N = ws.size();
    sort(begin(ws), end(ws));
    vector<int> lower;
    for (int l = 0, r = 1; l < N; l = r++) {
        while (r < N && ws[l] == ws[r]) {
            r++;
        }
        int S = r - l;
        int b = 1;
        while (b <= S) {
            lower.push_back(b * ws[l]);
            S -= b, b *= 2;
        }
        lower.push_back(S * ws[l]);
    }
    return lower;
}

auto subset_sum_fast(vector<int> ws) {
    ws = subset_sum_filter_weights(ws);
    int W = accumulate(begin(ws), end(ws), 0);
    sort(begin(ws), end(ws));
    int M = ws.back();
    if (W <= 2 * M + 1) {
        return 1LL * M * (W - M);
    }
    constexpr int MAXW = 1'000'000;
    bitset<MAXW + 1> ok;
    ok[0] = true;
    for (int w : ws) {
        ok |= ok << w;
    }
    for (int w = W / 2; w >= 0; w--) {
        if (ok[w]) {
            return 1LL * w * (W - w);
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> parent(N);
    vector<vector<int>> kids(N);
    for (int i = 1; i < N; i++) {
        cin >> parent[i], parent[i]--;
        kids[parent[i]].push_back(i);
    }

    vector<int> subt(N, 1);
    vector<int64_t> score(N, 0);
    for (int u = N - 1; u > 0; u--) {
        subt[parent[u]] += subt[u];
        score[u] += subt[u];
        score[parent[u]] += score[u];
    }
    score[0] += N;

    int64_t ans = 0;
    y_combinator([&](auto self, int u, int64_t C) -> void {
        int64_t B = 0;
        vector<int> subs;
        for (int v : kids[u]) {
            subs.push_back(subt[v]);
            B += score[v];
        }
        if (u > 0) {
            subs.push_back(N - subt[u]);
        }
        int64_t got = B + C + N + subset_sum_fast(subs);
        ans = max(ans, got);
        for (int v : kids[u]) {
            self(v, B + C + N - score[v] - subt[v]);
        }
    })(0, 0);
    cout << ans << '\n';
    return 0;
}