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
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    int len;
    T* data;

  public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
        assign(shape_, t);
    }

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

    void assign(std::array<int, NDIMS> shape_, const T& t = T()) {
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

    friend istream& operator>>(istream& in, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            in >> t.data[i];
        }
        return in;
    }
    bool operator==(const tensor& o) const {
        return shape == o.shape && equal(data, data + len, o.data);
    }
    bool operator!=(const tensor& o) const { return !(*this == o); }

  private:
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, Q;
    cin >> N >> M >> Q;
    const int R = N + 2;
    const int C = M + 2;

    vector<vector<int>> mat(R, vector<int>(C));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> mat[i][j];
        }
    }

    using index_t = array<int, 2>;
    tensor<index_t, 2> north({R, C});
    tensor<index_t, 2> south({R, C});
    tensor<index_t, 2> left({R, C});
    tensor<index_t, 2> right({R, C});

    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            north[{i, j}] = {i - 1, j};
            south[{i - 1, j}] = {i, j};
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 1; j < C; j++) {
            left[{i, j}] = {i, j - 1};
            right[{i, j - 1}] = {i, j};
        }
    }

    auto find = [&](auto a, bool down_first = true) {
        auto [r, c] = a;
        index_t i = {0, 0};
        while (down_first && r--) {
            i = south[i];
        }
        while (c--) {
            i = right[i];
        }
        while (!down_first && r--) {
            i = south[i];
        }
        return i;
    };

    for (int q = 0; q < Q; q++) {
        index_t ai, bi;
        int h, w;
        cin >> ai[0] >> ai[1] >> bi[0] >> bi[1] >> h >> w;
        h--, w--;
        auto a = find(ai);
        auto b = find(bi);

        for (int x = 0; x <= h; x++) {
            right[left[a]] = b;
            right[left[b]] = a;
            swap(left[a], left[b]);
            if (x < h) {
                a = south[a];
                b = south[b];
            }
        } // left border
        for (int y = 0; y <= w; y++) {
            north[south[a]] = b;
            north[south[b]] = a;
            swap(south[a], south[b]);
            if (y < w) {
                a = right[a];
                b = right[b];
            }
        } // lower border
        for (int x = 0; x <= h; x++) {
            left[right[a]] = b;
            left[right[b]] = a;
            swap(right[a], right[b]);
            if (x < h) {
                a = north[a];
                b = north[b];
            }
        } // right border
        for (int y = 0; y <= w; y++) {
            south[north[a]] = b;
            south[north[b]] = a;
            swap(north[a], north[b]);
            if (y < w) {
                a = left[a];
                b = left[b];
            }
        } // upper border
    }

    vector<vector<int>> ans(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        index_t idx = {i + 1, 0};
        for (int j = 0; j < M; j++) {
            idx = right[idx];
            ans[i][j] = mat[idx[0]][idx[1]];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << " \n"[j + 1 == M];
        }
    }
    return 0;
}