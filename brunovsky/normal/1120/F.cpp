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
    int N;
    int64_t D, C;
    cin >> N >> D >> C;

    vector<int> t(N + 1), p(N + 1);
    for (int i = 0; i < N; i++) {
        char dude;
        cin >> t[i] >> ws >> dude;
        p[i] = dude == 'W';
    }
    cin >> t[N];

    vector<array<int, 2>> cnt(N + 1);
    vector<array<int64_t, 2>> sum(N + 1);
    for (int i = 0; i < N; i++) {
        cnt[i + 1] = cnt[i];
        sum[i + 1] = sum[i];
        cnt[i + 1][p[i]] += 1;
        sum[i + 1][p[i]] += t[i];
    }

    static constexpr int64_t inf = INT64_MAX / 3;
    vector<int64_t> dpr(N + 1, inf), dpo(N + 1, inf);
    dpr[N] = dpo[N] = 0;
    int last[2] = {N, N}, tail[2] = {N, N};
    const int G = (C + D - 1) / D;

    for (int i = N - 1; i >= 0; i--) {
        int s = p[i];
        int j = last[!s];
        int k = tail[s];
        while (k > i && t[j] - t[k] < G) {
            tail[s] = --k;
        }
        int ds = j - k - 1;
        int cs = k - i;
        int gap = t[j] - t[i];
        dpo[i] = C + min(dpo[i + 1], dpr[i + 1]);
        dpr[i] = dpr[j] + C * cs + D * (ds * t[j] - (sum[j][s] - sum[j - ds][s]) + gap);
        last[s] = i;
        tail[!s] = min(tail[!s], i - 1);
    }

    cout << min(dpr[0], dpo[0]) << '\n';
    return 0;
}