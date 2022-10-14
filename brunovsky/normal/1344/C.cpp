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

void setmin(int& a, int b) { a = min(a, b); }
void setmax(int& a, int b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> out(N), in(N);
    vector<int> indeg(N), outdeg(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        out[u].push_back(v);
        in[v].push_back(u);
        outdeg[u]++;
        indeg[v]++;
    }

    vector<int> topoorder(N);
    int S = 0;

    for (int u = 0; u < N; u++) {
        if (indeg[u] == 0) {
            topoorder[S++] = u;
        }
    }

    for (int i = 0; i < S; i++) {
        int u = topoorder[i];
        for (int v : out[u]) {
            if (--indeg[v] == 0) {
                topoorder[S++] = v;
            }
        }
    }

    if (S != N) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> lowest_out(N, N);
    vector<int> lowest_in(N, N);

    for (int i = 0; i < N; i++) {
        int u = topoorder[i];
        setmin(lowest_in[u], u);
        for (int v : out[u]) {
            setmin(lowest_in[v], lowest_in[u]);
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        int u = topoorder[i];
        setmin(lowest_out[u], u);
        for (int v : in[u]) {
            setmin(lowest_out[v], lowest_out[u]);
        }
    }

    vector<bool> quant(N, true);
    int Q = 0;
    for (int u = 0; u < N; u++) {
        quant[u] = lowest_in[u] == u && lowest_out[u] == u;
        Q += quant[u];
    }

    cout << Q << '\n';
    for (int u = 0; u < N; u++) {
        cout << "EA"[quant[u]] << (u + 1 == N ? "\n" : "");
    }
    return 0;
}