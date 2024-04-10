#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#include "code/numeric/bits.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

#ifdef LOCAL

template <typename T>
struct integer_xor_basis {
    vector<T> basis;
    vector<T> rep;

    int dimensions() const { return basis.empty() ? 0 : basis.front().size(); }
    int basis_size() const { return basis.size(); }
    void clear() { basis.clear(); }

    auto reduce(T vec) { return operate(vec, false); }

    // Return true if the vector is representable (possibly empty)
    bool representable(const T& vec) { return operate(vec, false) == T(); }

    // Return true if the vector is not empty and can be/was added to the basis
    bool check(const T& vec) { return operate(vec, false) != T(); }
    bool insert_check(const T& vec) { return operate(vec, true) != T(); }

    auto representation(const T& vec) { return get(vec); }

  private:
    // Reduce and maybe insert the vec in basis. Returns the vector fully reduced
    auto operate(T vec, bool add_basis) {
        int B = basis_size();
        T mask = 0;
        for (int i = 0; i < B && vec != T(); i++) {
            if (auto b = vec ^ basis[i]; vec > b) {
                vec = b;
                mask ^= rep[i];
            }
        }
        if (add_basis && vec) {
            basis.push_back(vec);
            rep.push_back(mask ^ (1 << B));
        }
        return vec;
    }

    auto get(T vec) {
        int B = basis_size();
        T mask = 0;
        for (int i = 0; i < B && vec != T(); i++) {
            if (auto b = vec ^ basis[i]; vec > b) {
                vec = b;
                mask ^= rep[i];
            }
        }
        assert(vec == 0);
        return mask;
    }
};

void analyze() {
    for (int N = 1; N <= 17; N++) {
        vector<vector<int64_t>> mat(N + 1, vector<int64_t>(N + 1));
        for (int j = 1; j <= N; j++) {
            mat[0][j] = 1LL << (j - 1);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                mat[i][j] = mat[i - 1][j] ^ mat[i][j - 1];
            }
        }
        integer_xor_basis<int64_t> basis;
        for (int i = 1; i <= N; i++) {
            basis.insert_check(mat[i][N]);
        }
        for (int i = 0; i < N; i++) {
            auto x = basis.representation(1LL << i);
            println("{:>2} {:>2} | {}", N, i, lsbits(x, N));
        }
        putln();
    }
}

#endif

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

auto combine(vector<int>& a, vector<int>& b, int x, int y) {
    for (int i = y, m = b.size(); i < y + m; i++) {
        a[i - x] ^= b[i - y];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    int M = 1;
    while (M < N) {
        M *= 2;
    }
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    auto eval = y_combinator([&](auto self, int l, int r) -> vector<int> {
        int s = r - l;
        vector<int> c(s);
        if (s == 1) {
            c[0] = b[l];
        } else {
            int k = s / 2;
            int m = (l + r) / 2;
            auto lo = self(l, m);
            auto hi = self(m, r);
            for (int i = 0; i < k; i++) {
                c[i] ^= lo[i];
                c[i] ^= hi[i];
                c[i + k] ^= hi[i];
            }
        }
        return c;
    });

    auto a = y_combinator([&](auto self, int l, int r) -> vector<int> {
        int s = r - l;
        int k = 1 << (31 - __builtin_clz(s));
        if (s == k) {
            return eval(l, r);
        } else {
            vector<int> c(s);
            auto d = eval(l, l + k);
            int g = s - k;
            for (int i = 0; i < k; i++) {
                c[i + g] ^= d[i];
            }
            auto lo = self(l, l + g);
            auto hi = self(r - g, r);
            for (int i = 0; i < g; i++) {
                c[i] ^= lo[i];
                c[i] ^= hi[i];
                c[i + k] ^= lo[i];
                c[i + k] ^= hi[i];
            }
            return c;
        }
    })(0, N);

    for (int i = 0; i < N; i++) {
        cout << a[i] << " \n"[i + 1 == N];
    }
    return 0;
}