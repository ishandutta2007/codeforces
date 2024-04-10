#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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

inline void reverse_bits(unsigned& v) {
    v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
    v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
    v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
    v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
    v = (v >> 16) | (v << 16);
}

inline auto first_gray_code(int size, int max_size) {
    assert(0 <= size && size <= max_size && max_size <= 31);
    return make_tuple((1u << size) - 1, (1u << max_size) - 1, 0u, -1, -1);
}
inline void next_gray_code(unsigned& u, unsigned i, int& in, int& out) {
    assert(i > 0);
    unsigned b = u ^ i ^ (i >> 1);
    if (u & b) {
        in = -1, out = __builtin_ctz(b);
    } else {
        in = __builtin_ctz(b), out = -1;
    }
    u ^= b;
}
#define FOR_ALL_MASKS_GRAY_CODE(mask, max_size, in, out)                      \
    for (auto [mask, max##in, i##in, in, out] = first_gray_code(0, max_size); \
         i##in <= max##in; i##in++, next_gray_code(mask, i##in, in, out))

constexpr int inf = INT_MAX / 3;
struct Node {
    int l, r, size;
    int min_value = inf;
    int max_value = -inf;
    int min_diff = inf;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int S = 1 << K;
    vector<Node> st(2 * S);

    for (int i = 0; i < N; i++) {
        st[S + arr[i]].min_value = 0;
        st[S + arr[i]].max_value = 0;
    }

    auto combine = [&](int i) {
        int l = st[i].l, r = st[i].r, s = st[l].size;
        auto& cl = st[l];
        auto& cr = st[r];
        st[i].size = cl.size + cr.size;
        st[i].min_value = min(cl.min_value, cr.min_value + s);
        st[i].max_value = max(cl.max_value, cr.max_value + s);
        st[i].min_diff = min(cl.min_diff, cr.min_diff);
        if (cl.min_value < inf && cr.min_value < inf) {
            st[i].min_diff = min(st[i].min_diff, cr.min_value + s - cl.max_value);
        }
    };

    y_combinator([&](auto self, int i, int l, int r) -> void {
        if (i < S) {
            self(i << 1, l, (l + r) / 2);
            self(i << 1 | 1, (l + r) / 2, r);
            st[i].l = i << 1, st[i].r = i << 1 | 1;
            combine(i);
        } else {
            assert(l + 1 == r && i == l + S);
            st[i].size = 1;
        }
    })(1, 0, S);

    auto flip = y_combinator([&](auto self, int bit, int depth, int i) -> void {
        if (bit == depth) {
            assert(i < S);
            swap(st[i].l, st[i].r);
        } else {
            self(bit, depth + 1, st[i].l);
            self(bit, depth + 1, st[i].r);
        }
        combine(i);
    });

    vector<int> ans(S);
    int x = 0;
    FOR_ALL_MASKS_GRAY_CODE(mask, K, in, out) {
        if (in != -1) {
            x ^= 1 << (K - 1 - in);
            flip(in, 0, 1);
        } else if (out != -1) {
            x ^= 1 << (K - 1 - out);
            flip(out, 0, 1);
        }
        ans[x] = st[1].min_diff;
    }

    for (int i = 0; i < S; i++) {
        cout << ans[i] << " \n"[i + 1 == S];
    }

    return 0;
}