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

struct Run {
    vector<int64_t> sum;
    vector<int64_t> value;
    vector<int> count;
    int b = 1;

    void prepare(int mult, vector<int>& xs) {
        b = mult;
        vector<pair<int, int>> adds;
        sort(rbegin(xs), rend(xs));
        for (int x : xs) {
            if (adds.empty() || adds.back().first > x) {
                adds.emplace_back(x, 1);
            } else {
                adds.back().second++;
            }
        }
        sum.push_back(0);
        count.push_back(0);
        for (auto [x, c] : adds) {
            sum.push_back(1LL * x * c);
            value.push_back(x);
            count.push_back(c);
        }
        int S = value.size();
        for (int i = 1; i <= S; i++) {
            sum[i] += sum[i - 1];
            count[i] += count[i - 1];
        }
    }

    auto query(int64_t q, int64_t a, int64_t b) const {
        int S = value.size(), L = -1, R = S;
        while (R - L > 1) {
            int M = (L + R) / 2;
            (value[M] * b >= q) ? L = M : R = M;
        }
        return make_pair(a * sum[S] + b * sum[R], count[R]);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    int64_t budget, add_cost, mul_cost;
    cin >> N >> budget >> add_cost >> mul_cost;

    vector<int> xs = {1};
    vector<Run> runs(1);

    int M = 0, A = 0;
    int64_t MUL = 1, ADD = 1;
    for (int i = 0; i < N; i++) {
        string txt;
        int x;
        cin >> txt >> x;
        char op = txt[0];
        if (op == '+' && x > 0) {
            xs.emplace_back(x);
            A++, ADD += x;
        } else if (op == '*' && x > 1) {
            runs[M].prepare(x, xs);
            runs.push_back({});
            xs.clear();
            M++, MUL *= x;
        }
    }
    runs[M].prepare(1, xs);

    if (M * mul_cost <= budget || A * add_cost <= budget) {
        cout << ADD * MUL << '\n';
        return 0;
    }

    const int B = min<int>(M, budget / mul_cost);
    vector<int> cap(B + 1, 0);
    for (int m = 0; m <= B; m++) {
        cap[m] = (budget - m * mul_cost) / add_cost;
    }

    int moves = 0;
    int64_t ans = 0;

    vector<int64_t> mul(M + 1, MUL);
    for (int i = 0; i < M; i++) {
        mul[i + 1] = mul[i] / runs[i].b;
    }

    vector<pair<int, int>> order;
    for (int i = 0; i < M; i++) {
        order.emplace_back(runs[i].b, i);
    }
    sort(begin(order), end(order), [&](auto x, auto y) {
        return make_pair(-x.first, x.second) < make_pair(-y.first, y.second);
    });

    auto query = [&](int64_t q) {
        int64_t sum = 0;
        int count = 0;
        for (int i = 0; i <= M; i++) {
            auto [v, c] = runs[i].query(q, mul[i], MUL - mul[i]);
            sum += v, count += c;
        }
        return make_pair(sum, count);
    };

    auto compute = [&]() {
        int C = cap[moves];
        int64_t L = 0, R = ADD * MUL + 1;
        while (R - L > 1) {
            int64_t Q = (L + R) / 2;
            query(Q).second > C ? L = Q : R = Q;
        }
        auto [sum, c] = query(L);
        ans = max(ans, sum - L * max(0, c - C));
    };

    y_combinator([&](auto self, int k, int m, int K) -> void {
        while (k < M && order[k].first > m) {
            k++;
        }
        if (k == M) {
            compute();
            return;
        }
        int r = order[k].second;
        if (moves < B && r < K) {
            for (int i = r + 1; i <= M; i++) {
                mul[i] *= runs[r].b;
            }
            moves++;
            self(k + 1, runs[r].b, K);
            moves--;
            for (int i = r + 1; i <= M; i++) {
                mul[i] /= runs[r].b;
            }
        }
        self(k + 1, runs[r].b - 1, min(K, r));
    })(0, MUL, M);

    cout << ans << '\n';
    return 0;
}