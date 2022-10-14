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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<long> ops(K);
    vector<int> pop(K);
    vector<vector<long>> tail(K);
    for (int i = 0; i < K; i++) {
        long mask = 0;
        cin >> pop[i];
        for (int j = 0; j < pop[i]; j++) {
            int x;
            cin >> x;
            mask |= 1LL << (x - 1);
        }
        ops[i] = mask;
        tail[i].resize(pop[i] + 1);
        for (int k = pop[i]; k > 0; mask &= mask - 1, k--) {
            tail[i][k] = mask;
        }
    }
    if (N == 1 && K == 0) {
        cout << "ACCEPTED\n";
        return 0;
    }
    vector<long> ordered(N + 1); // ordered[i]: ordered mask with i 1 bits set
    for (int i = 0; i <= N; i++) {
        ordered[i] = (1LL << N) - (1LL << (N - i));
    }
    vector<long> visited(K + 1);
    for (int i = 0; i < K; i++) {
        visited[i + 1] = visited[i] | ops[i];
    }
    vector<long> newly_visited(K);
    for (int i = 0; i < K; i++) {
        newly_visited[i] = visited[i] ^ visited[i + 1];
    }
    vector<vector<long>> add_bits(K);
    for (int i = 0; i < K; i++) {
        int b = __builtin_popcountll(newly_visited[i]);
        add_bits[i].resize(b + 1);
        long mask = newly_visited[i];
        for (int j = b; j >= 0; j--) {
            add_bits[i][j] = mask;
            mask &= mask - 1;
        }
    }
    long full = ordered[N];
    if (visited[K] != full) {
        cout << "REJECTED\n";
        return 0;
    }
    bool ok = y_combinator([&](auto self, int k, long mask) -> bool {
        if (visited[k] == full && mask == ordered[__builtin_popcountll(mask)]) {
            return true;
        }
        if (k == K) {
            return false;
        }
        // perform the next ordering. how many 1s are there already?
        for (long add : add_bits[k]) {
            long sub = mask | add;
            int b = __builtin_popcountll(sub & ops[k]);
            // set all the bits to 1, then all to 0, then add b bits
            sub = tail[k][b] | ((sub | ops[k]) ^ ops[k]);
            if (!self(k + 1, sub)) {
                return false;
            }
        }
        return true;
    })(0, 0);
    cout << (ok ? "ACCEPTED\n" : "REJECTED\n");
    return 0;
}