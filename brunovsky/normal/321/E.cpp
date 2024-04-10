#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

const int MAXN = 4001, MAXK = 801;
uint16_t u[MAXN][MAXN];
unsigned cost[MAXN][MAXN];
unsigned dp[MAXN][MAXK];

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> u[i][j];
            u[i][j] += u[i][j - 1];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            cost[i][j] = cost[i][j - 1] + u[j][j] - u[j][i - 1];
        }
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0][0] = 0;
    auto solve = y_combinator([&](auto self, int s, int L, int R, int a, int b) -> void {
        if (L > R) {
            return;
        }
        int m = (L + R) / 2, k = a;
        for (int l = a; l <= min(b, m); l++) {
            unsigned w = dp[l - 1][s - 1] + cost[l][m];
            if (dp[m][s] > w) {
                dp[m][s] = w, k = l;
            }
        }
        self(s, L, m - 1, a, k);
        self(s, m + 1, R, k, b);
    });

    for (int s = 1; s <= K; s++) {
        solve(s, 1, N, 1, N);
    }
    cout << dp[N][K] << '\n';
    return 0;
}