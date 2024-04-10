#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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
        vector<int> P(N);
        for (int i = 0; i < N; i++) {
            cin >> P[i], P[i]--;
        }
        vector<int> in(N);
        for (int i = 0; i < N; i++) {
            in[P[i]] = i;
        }
        // pref[i][v]: how many values in [0..i) are < v?
        tensor<int16_t, 2> pref({N + 1, N});
        for (int i = 0; i < N; i++) {
            for (int v = 0; v < N; v++) {
                pref[{i + 1, v}] = pref[{i, v}] + (P[i] < v);
            }
        }
        // suff[i][v]: how many values in (i..N) are < v?
        tensor<int16_t, 2> suff({N + 1, N});
        for (int i = N - 1; i > 0; i--) {
            for (int v = 0; v < N; v++) {
                suff[{i - 1, v}] = suff[{i, v}] + (P[i] < v);
            }
        }
        // First, pb largest
        int64_t ans = 0;
        for (int b = 3; b < N; b++) {
            int low = 0;
            for (int c = 0; c < b; c++) {
                if (in[c] < in[b]) {
                    low++;
                } else {
                    ans += low * suff[{in[c], b}];
                }
            }
        }
        // Now, pc largest
        for (int c = 3; c < N; c++) {
            int high = 0;
            for (int b = 0; b < c; b++) {
                if (in[c] < in[b]) {
                    high++;
                } else {
                    ans += high * pref[{in[b], c}];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}