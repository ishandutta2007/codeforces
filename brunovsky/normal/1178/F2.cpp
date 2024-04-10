#include <bits/stdc++.h>

using namespace std;

#define long int64_t

inline namespace lib {

template <typename T, int NDIMS>
struct tensor {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

  protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    int len;
    T* data;

  public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS - 1] = 1;
        for (int i = NDIMS - 1; i > 0; i--) {
            strides[i - 1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    tensor(const tensor& o)
        : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        for (int i = 0; i < len; i++) {
            data[i] = o.data[i];
        }
    }

    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
        return *this;
    }
    tensor(tensor&& o) : tensor() { *this = std::move(o); }
    tensor& operator=(const tensor& o) { return *this = tensor(o); }
    ~tensor() { delete[] data; }

    auto size() const { return shape; }

  protected:
    int flatten_index(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            res += idx[i] * strides[i];
        }
        return res;
    }
    int flatten_index_checked(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](std::array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T& at(std::array<int, NDIMS> idx) const { return data[flatten_index_checked(idx)]; }
};

template <int mod>
struct modnum {
    static_assert(mod > 0 && 2LL * mod < INT_MAX);
    int n;

    modnum() : n(0) {}
    modnum(int v) : n(fit(v % mod)) {}
    explicit operator int() const { return n; }
    explicit operator bool() const { return n != 0; }

    static int fit(int v) { return v >= mod ? v - mod : (v < 0 ? v + mod : v); }
    static int modinv(int v, int m = mod) {
        v %= m, assert(v);
        return v == 1 ? 1 : (m - 1LL * modinv(m, v) * m / v);
    }
    friend modnum modpow(modnum b, long e) {
        modnum p = 1;
        while (e > 0) {
            if (e & 1)
                p = p * b;
            if (e >>= 1)
                b = b * b;
        }
        return p;
    }

    modnum inv() const { return {modinv(n)}; }
    modnum operator-() const { return {fit(-n)}; }
    modnum operator+() const { return {n}; }
    modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    modnum operator--(int) { return n = fit(n - 1), *this + 1; }
    modnum& operator++() { return n = fit(n + 1), *this; }
    modnum& operator--() { return n = fit(n - 1), *this; }
    modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    modnum& operator-=(modnum v) { return n = fit(n - v.n), *this; }
    modnum& operator*=(modnum v) { return n = (1LL * n * v.n) % mod, *this; }
    modnum& operator/=(modnum v) { return n = (1LL * n * modinv(v.n)) % mod, *this; }

    friend modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        return in >> v.n, v.n = fit(v.n % mod), in;
    }
};

template <typename T>
struct rmq_index {
    vector<T> v;
    vector<vector<int>> jmp;

    rmq_index() = default;
    explicit rmq_index(const vector<T>& v) : v(v), jmp(1, vector<int>(v.size())) {
        iota(begin(jmp[0]), end(jmp[0]), 0);
        for (unsigned len = 1, k = 1; len * 2 <= v.size(); len *= 2, ++k) {
            jmp.emplace_back(v.size() - len * 2 + 1);
            for (unsigned j = 0; j < jmp[k].size(); j++) {
                int l = jmp[k - 1][j];
                int r = jmp[k - 1][j + len];
                jmp[k][j] = min(make_pair(v[l], l), make_pair(v[r], r)).second;
            }
        }
    }

    T query(int a, int b) const /* [a, b) */ {
        assert(a < b); // or return inf if a == b
        static constexpr int bits = CHAR_BIT * sizeof(int) - 1;
        int dep = bits - __builtin_clz(b - a);
        int l = jmp[dep][a];
        int r = jmp[dep][b - (1 << dep)];
        return min(make_pair(v[l], l), make_pair(v[r], r)).second;
    }
};

} // namespace lib

using num = modnum<998244353>;

#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    vector<int> color(M + 2);
    for (int j = 1; j <= M; j++) {
        cin >> color[j];
    }

    vector<vector<int>> positions(N + 1);
    vector<int> first(N + 1), last(N + 1);
    for (int j = 0; j <= M + 1; j++) {
        positions[color[j]].push_back(j);
    }
    for (int c = 0; c <= N; c++) {
        assert(!positions[c].empty());
        first[c] = positions[c].front();
        last[c] = positions[c].back();
    }

    set<int> vis_pos;
    vis_pos.insert(M + 1);
    for (int i = 1; i <= N; i++) {
        int smaller = *vis_pos.lower_bound(first[i]);
        if (smaller < last[i]) {
            cout << 0 << endl;
            return 0;
        }
        vis_pos.insert(begin(positions[i]), end(positions[i]));
    }

    vector<num> arrange(N + 1, 1);

    for (int c = N; c >= 0; c--) {
        int j = first[c];
        while (j <= last[c] && color[j] == c)
            j++;

        while (j <= last[c]) {
            vector<int> above;
            while (j <= last[c] && color[j] != c) {
                int i = color[j];
                assert(j == first[i]);
                above.push_back(i);
                j = last[i] + 1;
            }
            int A = above.size();

            tensor<num, 2> dp({A + 1, A + 1});
            rmq_index<int> rmq(above);

            for (int i = 0; i <= A; i++) {
                dp[{i, i}] = 1;
            }
            for (int len = 1; len <= A; len++) {
                for (int l = 0, r = len; r <= A; l++, r++) {
                    int i = rmq.query(l, r);
                    assert(l <= i && i < r);
                    num L = 0;
                    num R = 0;
                    for (int k = l; k <= i; k++) {
                        L += dp[{l, k}] * dp[{k, i}];
                    }
                    for (int k = i + 1; k <= r; k++) {
                        R += dp[{i + 1, k}] * dp[{k, r}];
                    }
                    assert(L != 0 && R != 0);
                    dp[{l, r}] = L * R;
                }
            }

            arrange[c] *= dp[{0, A}];
            for (int i : above) {
                arrange[c] *= arrange[i];
            }

            while (j <= last[c] && color[j] == c)
                j++;
        }
    }

    cout << arrange[0] << endl;
    return 0;
}