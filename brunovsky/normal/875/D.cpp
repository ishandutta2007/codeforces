#include <bits/stdc++.h>

using namespace std;

#define long int64_t

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
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    vector<int> index(N);
    iota(begin(index), end(index), 1);
    sort(begin(index), end(index), [&](int u, int v) { return a[u] < a[v]; });

    constexpr int B = 31;
    vector<array<int, B>> prefix_bits(N + 2);
    for (int i = 1; i <= N; i++) {
        prefix_bits[i + 1] = prefix_bits[i];
        for (int b = 0; b < B; b++) {
            if ((1 << b) & a[i]) {
                prefix_bits[i + 1][b]++;
            }
        }
    }

    auto range_or = [&](int l, int r) {
        assert(l <= r);
        int ans = 0;
        for (int b = 0; b < B; b++) {
            if (prefix_bits[r + 1][b] > prefix_bits[l][b]) {
                ans |= (1 << b);
            }
        }
        return ans;
    };

    auto go_left = [&](int L, int R, int mask) {
        while (L + 1 < R) {
            int M = (L + R) / 2;
            int ror = range_or(M, R);
            if ((ror & mask) != ror) {
                L = M;
            } else {
                R = M;
            }
        }
        return L;
    };

    auto go_right = [&](int L, int R, int mask) {
        while (L + 1 < R) {
            int M = (L + R) / 2;
            int ror = range_or(L, M);
            if ((ror & mask) != ror) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    };

    vector<int> far_left(N + 2);
    vector<int> far_right(N + 2);
    for (int i = 1; i <= N; i++) {
        far_left[i] = i - 1;
        far_right[i] = i + 1;
    }

    long ans = 0;

    for (int i : index) {
        int L = far_left[i];
        int R = far_right[i];
        int need_L = go_left(L, i, a[i]);
        int need_R = go_right(i, R, a[i]);
        assert(L <= need_L && need_L < i && i < need_R && need_R <= R);
        ans += 1LL * (need_L - L) * (R - i);
        ans += 1LL * (R - need_R) * (i - L);
        ans -= 1LL * (need_L - L) * (R - need_R);
        far_left[far_right[i]] = far_left[i];
        far_right[far_left[i]] = far_right[i];
    }

    cout << ans << endl;

    return 0;
}