#include <bits/stdc++.h>

using namespace std;

#define long int64_t

template <typename T>
struct fenwick {
    int N;
    vector<T> tree;

    explicit fenwick(int N = 0) : N(N), tree(N + 1) {}

    T sum(int i) {
        T sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }

    void add(int i, T n) {
        if (i > 0) {
            while (i <= N) {
                tree[i] += n;
                i += i & -i;
            }
        }
    }

    int lower_bound(T n) {
        int i = 0;
        int bits = CHAR_BIT * sizeof(int) - __builtin_clz(N << 1);
        for (int j = 1 << bits; j; j >>= 1) {
            if (i + j <= N && tree[i + j] < n) {
                n -= tree[i + j];
                i += j;
            }
        }
        return i + 1;
    }
};

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    unordered_map<int, vector<int>> by_value;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        by_value[A[i]].push_back(i);
    }

    uint64_t ans = 0;
    for (auto [_, indices] : by_value) {
        long cur_sum = 0;
        for (int i : indices) {
            ans += cur_sum * (N - i);
            cur_sum += i + 1;
        }
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}