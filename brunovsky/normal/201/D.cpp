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
    enable_if_t<NDIMS == 2, T*> operator[](int i) const { return data + i * strides[0]; }
};

inline void next_lexicographical_mask(unsigned& v) {
    unsigned c = v & -v, r = v + c;
    v = c ? (((r ^ v) >> 2) / c) | r : 0;
}
#define FOR_EACH_MASK(mask, size, max_size)                                            \
    for (unsigned mask = (1 << (size)) - 1, m##mask = 1 << (max_size); mask < m##mask; \
         next_lexicographical_mask(mask))

#define FOR_EACH_BIT_NUMBER(bit, i, mask)                                            \
    for (remove_const<decltype(mask)>::type z##bit = (mask), bit = z##bit & -z##bit, \
                                            i = __builtin_ctz(bit);                  \
         z##bit;                                                                     \
         z##bit ^= bit, z##bit && (bit = z##bit & -z##bit, i = __builtin_ctz(bit)))

void setmin(int& a, int b) { a = min(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    unordered_map<string, int> stringid;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        stringid.emplace(move(s), stringid.size());
    }
    int M;
    cin >> M;
    vector<vector<int>> words(M);
    vector<int> match(M);
    for (int m = 0; m < M; m++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            string s;
            cin >> s;
            if (stringid.count(s)) {
                int id = stringid.at(s);
                if (words[m].empty() || words[m].back() != id) {
                    words[m].push_back(id);
                    match[m] |= 1 << id;
                }
            }
        }
    }
    int MASK = (1 << N) - 1;
    vector<int> candidates;
    for (int m = 0; m < M; m++) {
        if (match[m] == MASK) {
            candidates.push_back(m);
        }
    }
    if (candidates.empty()) {
        cout << "Brand new problem!\n";
        return 0;
    }

    tensor<int, 2> invs({1 << N, N});
    for (int mask = 1; mask < MASK; mask++) {
        int rest = mask ^ MASK;
        for (int i = 0; i < N; i++) {
            if ((rest >> i) & 1) {
                invs[mask][i] = __builtin_popcount(mask & ~((1 << i) - 1));
            }
        }
    }

    pair<int, int> best = {INT_MAX, -1};
    for (int m : candidates) {
        int K = words[m].size();

        tensor<int, 2> link({K, N}, K);
        for (int j = K - 2; j >= 0; j--) {
            for (int i = 0; i < N; i++) {
                link[j][i] = link[j + 1][i];
            }
            link[j][words[m][j + 1]] = j + 1;
        }

        // iterate over size of subsequence
        // dp[mask][size]: earliest i at which we have visited the words in mask and have
        // size inversions
        tensor<int, 2> dp({1 << N, {N * (N - 1) / 2}}, K);
        for (int i = 0; i < N; i++) {
            dp[1 << i][0] = link[0][i];
        }
        dp[1 << words[m][0]][0] = 0; // fix first character

        for (int len = 1; len < N && dp[MASK][0] == K; len++) {
            int maxinv = len * (len - 1) / 2;
            FOR_EACH_MASK (mask, len, N) {
                for (int z = 0; z <= maxinv; z++) {
                    if (dp[mask][z] < K) {
                        FOR_EACH_BIT_NUMBER (bit, i, mask ^ MASK) {
                            setmin(dp[mask | bit][z + invs[mask][i]],
                                   link[dp[mask][z]][i]);
                        }
                    }
                }
            }
        }

        int minimum = -1;
        for (int z = 0; z <= N * (N - 1) / 2; z++) {
            if (dp[MASK][z] < K) {
                minimum = z;
                break;
            }
        }
        assert(minimum != -1);
        best = min(best, make_pair(minimum, m + 1));
    }

    auto [x, i] = best;
    int price = N * (N - 1) / 2 - x + 1;
    cout << i << '\n';
    cout << "[:" + string(price, '|') + ":]" << '\n';
    return 0;
}