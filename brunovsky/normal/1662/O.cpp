#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int n) { *this = disjoint_set(n); }
    void reset() { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (int r = find(u); u != r) {
            size[u] = size[r];
            next[u] = next[r] = u;
        }
    }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

template <typename T, int NDIMS>
struct tensor {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

  protected:
    array<int, NDIMS> shape;
    array<int, NDIMS> strides;
    int len;
    T* data;

  public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(array<int, NDIMS> shape_, const T& t = T()) { assign(shape_, t); }

    tensor(const tensor& o)
        : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        copy(o.data, o.data + len, data);
    }
    tensor(tensor&& o) : tensor() { *this = std::move(o); }

    tensor& operator=(const tensor& o) { return *this = tensor(o); }
    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
        return *this;
    }
    ~tensor() { delete[] data; }

    void assign(array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS - 1] = 1;
        for (int i = NDIMS - 1; i > 0; i--) {
            strides[i - 1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    const auto& size() const { return shape; }
    int size(int dim) const { return shape[dim]; }

    friend istream& operator>>(istream& in, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            in >> t.data[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            out << ' ' << t.data[i];
        }
        return out;
    }
    bool operator==(const tensor& o) const {
        return shape == o.shape && equal(data, data + len, o.data);
    }
    bool operator!=(const tensor& o) const { return !(*this == o); }

  private:
    template <size_t D>
    int flatten_index(array<int, D> idx) const {
        static_assert(1 <= D && D <= NDIMS);
        int res = 0;
        for (int i = 0; i < int(D); i++) {
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T* operator[](array<int, NDIMS - 1> idx) const { return data + flatten_index(idx); }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        // Radii 1..20
        // Angles 0..360
        // We cut it at angle 0 obviously
        constexpr int H = 22, W = 360;
        tensor<bool, 3> ok({H, W, 2}, true); // down, left

        auto add_circular = [&](int r, int a, int b) {
            for (int i = a; i < b; i++) {
                ok[{r, i, 0}] = false;
            }
        };
        auto add_straight = [&](int o, int r, int s) {
            for (int i = r; i < s; i++) {
                ok[{i, o, 1}] = false;
            }
        };
        for (int i = 0; i < N; i++) {
            string type;
            cin >> type;
            if (type == "C") {
                int r, o1, o2;
                cin >> r >> o1 >> o2;
                if (o1 <= o2) {
                    add_circular(r, o1, o2);
                } else {
                    add_circular(r, o1, W);
                    add_circular(r, 0, o2);
                }
            } else if (type == "S") {
                int r1, r2, o;
                cin >> r1 >> r2 >> o;
                add_straight(o, r1, r2);
            } else {
                assert(false);
            }
        }

        disjoint_set dsu(H * W);
        auto id = [&](int i, int j) { return i * W + j; };

        for (int i = 0; i < H; i++) {
            for (int j = 1; j < W; j++) {
                if (ok[{i, j, 1}]) {
                    dsu.join(id(i, j), id(i, j - 1));
                }
            }
            if (ok[{i, 0, 1}]) {
                dsu.join(id(i, 0), id(i, W - 1));
            }
        }
        for (int i = 1; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (ok[{i, j, 0}]) {
                    dsu.join(id(i, j), id(i - 1, j));
                }
            }
        }
        cout << (dsu.same(id(0, 0), id(H - 1, W - 1)) ? "YES\n" : "NO\n");
    }
    return 0;
}