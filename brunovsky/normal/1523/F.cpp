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
void setmax(int& a, int b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    // first N locations are the towers
    // last M locations are the quests
    vector<array<int, 2>> place(N + M);
    for (int i = 0; i < N; i++) {
        cin >> place[i][0] >> place[i][1];
    }
    vector<int> qtime(N + M);
    for (int i = N; i < N + M; i++) {
        cin >> place[i][0] >> place[i][1] >> qtime[i];
    }

    tensor<int, 2> dist({N + M, N + M});
    for (int i = 0; i < N + M; i++) {
        for (int j = i + 1; j < N + M; j++) {
            auto [x1, y1] = place[i];
            auto [x2, y2] = place[j];
            dist[j][i] = dist[i][j] = abs(x1 - x2) + abs(y1 - y2);
            assert(dist[i][j] > 0);
        }
    }

    // for every tower mask ts and location i, compute min distance from them to i
    constexpr int inf = 1e9 + 1;
    const int MASK = 1 << N;
    tensor<int, 2> mdist({MASK, N + M}, inf);
    for (int ts = 1; ts < MASK; ts++) {
        FOR_EACH_BIT_NUMBER (bit, t, ts) {
            for (int i = 0; i < N + M; i++) {
                mdist[ts][i] = min(mdist[ts][i], dist[t][i]);
            }
        }
    }

    // quests ordered by time, ties broken arbitrarily
    vector<int> order(M);
    iota(begin(order), end(order), N);
    sort(begin(order), end(order), [&](int u, int v) { return qtime[u] < qtime[v]; });

    vector<vector<int>> reachable(N + M);
    for (int p = N; p < N + M; p++) {
        for (int q = N; q < N + M; q++) {
            if (p != q && qtime[p] + dist[p][q] <= qtime[q]) {
                reachable[p].push_back(q);
            }
        }
    }

    // transitions
    // 1 Q(ts,p) -> Q(ts,q)             if q is reachable from p (walk p->q)
    // 2 Q(ts,p) -> K(ts,dpq[ts][p])    if ts>0 (teleport to any tower)
    // 3 Q(ts,p) -> K(ts+i,dpq[ts][p])  cost dist[p][t] (walk p->t)
    // 4 K(ts,k) -> K(ts+i,k)           if ts is not full (visit a new tower)
    // 5 K(ts,k) -> Q(ts,q)             if dpk[ts][k] + mdist[ts][q] <= qtime[q]
    // at the end, check both dpq and dpk

    // we got towers ts and are at quest q, maximum number of quests we may have visited
    // state Q(ts,q)
    tensor<int, 2> dpq({MASK, N + M}, 0);
    for (int q = N; q < N + M; q++) {
        dpq[0][q] = 1;
    }

    // we got towers ts and have visited k quests, what is the earliest time at the towers
    // state K(ts,k), ts>0
    tensor<int, 2> dpk({MASK, M + 1}, inf);
    for (int t = 0; t < N; t++) {
        dpk[1 << t][0] = 0;
    }

    const int ALL_TOWERS = MASK - 1;

    for (int ts = 0; ts <= ALL_TOWERS; ts++) {
        // we still have to visit the points in order

        for (int p : order) {
            // 5 K(ts,k) -> Q(ts,q)             if dpk[ts][k] + mdist[ts][q] <= qtime[q]
            if (ts != 0) {
                for (int k = dpq[ts][p]; k <= M; k++) {
                    if (dpk[ts][k] < inf) {
                        if (dpk[ts][k] + mdist[ts][p] <= qtime[p]) {
                            setmax(dpq[ts][p], k + 1);
                            setmin(dpk[ts][k + 1], qtime[p]);
                        }
                    }
                }
            }
            // 1 Q(ts,p) -> Q(ts,q)             if q is reachable from p (walk p->q)
            if (int k = dpq[ts][p]; k > 0) {
                if (ts != 0) {
                    setmin(dpk[ts][k], qtime[p]);
                }
                for (int q : reachable[p]) {
                    setmax(dpq[ts][q], k + 1);
                    setmin(dpk[ts][k + 1], qtime[q]);
                }
            }
        }

        // at this point Q(ts,x) and K(ts,x) have been optimized for every x

        // 3 Q(ts,p) -> K(ts+i,dpq[ts][p])  cost dist[p][t] (walk p->t)
        if (ts != ALL_TOWERS) {
            for (int p : order) {
                if (int k = dpq[ts][p]; k > 0) {
                    FOR_EACH_BIT_NUMBER (bit, t, ALL_TOWERS ^ ts) {
                        setmin(dpk[ts | bit][k], qtime[p] + dist[p][t]);
                    }
                }
            }
        }

        // 4 K(ts,k) -> K(ts+i,k)           if ts is not full (visit a new tower)
        if (ts != 0 && ts != ALL_TOWERS) {
            for (int k = 0; k <= M; k++) {
                if (dpk[ts][k] < inf) {
                    FOR_EACH_BIT_NUMBER (bit, t, ALL_TOWERS ^ ts) {
                        setmin(dpk[ts | bit][k], dpk[ts][k] + mdist[ts][t]);
                    }
                }
            }
        }
    }

    // now find the best answer
    int ans = 0;
    for (int ts = 0; ts <= ALL_TOWERS && ans < M; ts++) {
        for (int k = M; k >= 0; k--) {
            if (dpk[ts][k] < inf) {
                ans = max(ans, k);
                break;
            }
        }
        for (int q = N; q < N + M; q++) {
            ans = max(ans, dpq[ts][q]);
        }
    }
    cout << ans << '\n';
    return 0;
}