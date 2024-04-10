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
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(begin(a), end(a));
    int ans = y_combinator([&](auto self, int b, int L, int R) -> int {
        if (R - L <= 2) {
            return 0;
        }
        int M = L;
        while (M < R && (a[M] >> b & 1) == (a[L] >> b & 1)) {
            M++;
        }
        if (M == L || M == R) {
            return self(b - 1, L, R);
        } else {
            int left = self(b - 1, L, M) + (R - M - 1);
            int right = self(b - 1, M, R) + (M - L - 1);
            return min(left, right);
        }
    })(30, 0, N);
    cout << ans << '\n';
    return 0;
}

// Fix i, suppose we link a[i] and a[j] because a[i]^a[j] is minimal
// There will be one pair (i,j) such that a[i]^a[j] is minimal all around, so j picks i
// Then everyone else picks towards this edge
// Suppose x picks y and adding this edge would form a cycle