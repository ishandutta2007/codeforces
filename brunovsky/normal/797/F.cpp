#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

/**
 * Multidimensional tensor/matrix with a subdimensional view
 * Good for multidimensional dp and avoiding the cancer of vector<vector<stuff...>>
 * Removed dependency on tensor_view for accessing data; this makes 2D tensor about 8x
 * faster since the arrays don't have to be copied to tensor_view every time operator[]
 * is called.
 * Source: https://github.com/ecnerwala/cp-book
 */
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
    template <size_t D>
    int flatten_index(array<int, D> idx) const {
        static_assert(1 <= D && D <= NDIMS);
        int res = 0;
        for (int i = 0; i < int(D); i++) {
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T* operator[](array<int, NDIMS - 1> idx) const { return data + flatten_index(idx); }
};

template <typename T>
void setmin(T& a, const T& b) {
    a = min(a, b);
}

template <typename T, typename Compare = less<>>
struct min_queue {
    list<pair<T, int>> window;
    int a = 0, b = 0;

    min_queue() = default;

    void push(T x) {
        while (!window.empty() && window.back().first > x)
            window.pop_back();
        window.emplace_back(x, b++);
    }

    void pop() {
        if (!window.empty() && window.front().second == a)
            window.pop_front();
        a++;
    }

    auto top() const { return window.front().first; }
    int size() const { return b - a; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<int> x(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
    }
    sort(begin(x) + 1, end(x));

    vector<pair<long, int>> input(M);
    for (int j = 0; j < M; j++) {
        cin >> input[j].first >> input[j].second;
    }
    sort(begin(input), end(input), [&](const auto& a, const auto& b) {
        return make_pair(a.first, -a.second) < make_pair(b.first, -b.second);
    });

    vector<long> p(M + 2);
    vector<int> capacity(M + 1);
    for (int j = 1; j <= M; j++) {
        p[j] = input[j - 1].first;
        capacity[j] = input[j - 1].second;
    }

    if (accumulate(begin(capacity), end(capacity), 0) < N) {
        cout << -1 << '\n';
        return 0;
    }

    constexpr long pinf = numeric_limits<long>::max() / 2;
    constexpr long ninf = numeric_limits<long>::lowest() / 2;
    p[0] = ninf;
    p[M + 1] = pinf;

    vector<long> dp(N + 1, pinf);
    dp[0] = 0;

    for (int j = 1; j <= M; j++) {
        vector<long> dist(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            dist[i] = dist[i - 1] + abs(x[i] - p[j]);
        }

        vector<long> cost(N + 1, 0);
        for (int i = 0; i <= N; i++) {
            cost[i] = dp[i] + dist[N] - dist[i];
        }

        min_queue<long> mq;
        mq.push(dist[N]);

        for (int i = 1; i <= N; i++) {
            long self = dp[i] + dist[N] - dist[i];
            mq.push(self);
            if (i > capacity[j]) {
                mq.pop();
            }

            setmin(dp[i], mq.top() - dist[N] + dist[i]);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}