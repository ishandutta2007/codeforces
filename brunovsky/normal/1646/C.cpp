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
    const int64_t MAX = 1e15;

    set<int64_t, greater<int64_t>> powers, facts;
    for (int64_t n = 1; n < MAX; n *= 2) {
        powers.insert(n);
    }
    for (int64_t n = 1, k = 2; n < MAX; n *= k++) {
        facts.insert(n);
    }

    int T;
    cin >> T;
    while (T--) {
        int64_t N;
        cin >> N;

        int b = __builtin_popcountll(N);
        int ans = b;
        set<int64_t> nums;

        y_combinator([&](auto self, int64_t n, int ops) -> void {
            if (ops >= ans) {
                return;
            }
            if (n == 0) {
                ans = min(ans, ops);
                return;
            }
            int64_t two = *powers.lower_bound(n);
            int64_t fac = *facts.lower_bound(n);
            if (!nums.count(two)) {
                nums.insert(two);
                self(n - two, ops + 1);
                nums.erase(two);
            }
            if (!nums.count(fac)) {
                nums.insert(fac);
                self(n - fac, ops + 1);
                nums.erase(fac);
            }
        })(N, 0);

        cout << ans << '\n';
    }
    return 0;
}