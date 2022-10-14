#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

using ns = chrono::nanoseconds;
using us = chrono::microseconds;
using ms = chrono::milliseconds;

#define CONCAT(x, y) x##y

#define LOOP_FOR_DURATION_IMPL(z, duration)                   \
    auto CONCAT(loop_start, z) = chrono::steady_clock::now(); \
    while (chrono::steady_clock::now() - CONCAT(loop_start, z) < duration)

#define LOOP_FOR_DURATION(in_duration) LOOP_FOR_DURATION_IMPL(__COUNTER__, in_duration)

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

template <typename T, typename BinOp>
struct sparse_table {
    vector<vector<T>> table;
    BinOp binop;

    template <typename It>
    sparse_table(It first, It last, const BinOp& op) : binop(op) {
        table.emplace_back(first, last);
        int N = table[0].size();
        for (int len = 1, k = 1; 2 * len <= N; len *= 2, k++) {
            int J = N - 2 * len + 1;
            table.emplace_back(J);
            for (int j = 0; j < J; j++) {
                table[k][j] = binop(table[k - 1][j], table[k - 1][j + len]);
            }
        }
    }

    sparse_table(const vector<T>& v, const BinOp& op)
        : sparse_table(begin(v), end(v), op) {}

    // query range [a,b)
    auto query(int a, int b) const {
        static constexpr int BITS = CHAR_BIT * sizeof(int) - 1;
        // assert(0 <= a && a < b && b <= int(table[0].size()));
        if (a + 1 == b) {
            return table[0][a];
        } else {
            int bits = BITS - __builtin_clz(b - a);
            return binop(table[bits][a], table[bits][b - (1 << bits)]);
        }
    }
};

void setmin(int& a, int b) { a = min(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    assert(M <= 5);

    vector<vector<int>> arr(N, vector<int>(M));
    vector<int> weight(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
        sort(begin(arr[i]), end(arr[i]));
        cin >> weight[i];
    }

    vector<int> vals;
    for (int i = 0; i < N; i++) {
        for (int v : arr[i]) {
            vals.push_back(v);
        }
    }
    sort(begin(vals), end(vals));
    vals.erase(unique(begin(vals), end(vals)), end(vals));
    for (int i = 0; i < N; i++) {
        for (int& v : arr[i]) {
            v = lower_bound(begin(vals), end(vals), v) - begin(vals);
        }
    }
    int V = vals.size();

    mt19937 rng(random_device{}());
    const int C = 20;
    uniform_int_distribution<int> dist(0, C - 1);

    const int inf = INT_MAX;
    const int full = (1 << C) - 1;
    int ans = inf;

    LOOP_FOR_DURATION (2500ms) {
        vector<int> color(V);
        for (int v = 0; v < V; v++) {
            color[v] = V <= C ? v : dist(rng);
        }

        vector<int> dp(1 << C, inf), mask(N);
        for (int i = 0; i < N; i++) {
            for (int v : arr[i]) {
                mask[i] |= 1 << color[v];
            }
            setmin(dp[mask[i]], weight[i]);
        }

        for (int s = 1; s < (1 << C); s++) {
            for (int i = 0; i < C; i++) {
                if (s >> i & 1) {
                    setmin(dp[s], dp[s ^ (1 << i)]);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            int rest = dp[full ^ mask[i]];
            if (rest != inf) {
                setmin(ans, weight[i] + rest);
            }
        }
    }

    cout << (ans == inf ? -1 : ans) << '\n';
    return 0;
}