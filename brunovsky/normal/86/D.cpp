#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto mosort_left_block(int N, const vector<array<int, 2>>& queries, int B = 0) {
    int Q = queries.size();
    if (B == 0 && Q > 0) {
        B = max<int>(1, N / sqrt(Q));
    }
    vector<pair<int, int>> block(Q);
    for (int i = 0; i < Q; i++) {
        auto [x, y] = queries[i];
        assert(0 <= x && x <= y && y <= N);
        block[i].first = x / B;
        block[i].second = (block[i].first & 1) ? -y : y;
    } // O(Q) divisions instead of O(Q log Q)
    vector<int> order(Q);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j) { return block[i] < block[j]; });
    return order;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int M = 1 + *max_element(begin(a), end(a));

    vector<array<int, 2>> queries(Q);
    for (auto& [l, r] : queries) {
        cin >> l >> r, l--;
    }
    auto order = mosort_left_block(N, queries);

    vector<int> cnt(M);
    vector<int64_t> ans(Q);
    int64_t sum = 0;
    int L = 0, R = 0;

    for (int q : order) {
        auto [l, r] = queries[q];
        while (L > l) {
            int x = a[--L], c = cnt[x]++, d = c + 1;
            sum += 1LL * d * d * x - 1LL * c * c * x;
        }
        while (R < r) {
            int x = a[R++], c = cnt[x]++, d = c + 1;
            sum += 1LL * d * d * x - 1LL * c * c * x;
        }
        while (L < l) {
            int x = a[L++], c = cnt[x]--, d = c - 1;
            sum += 1LL * d * d * x - 1LL * c * c * x;
        }
        while (R > r) {
            int x = a[--R], c = cnt[x]--, d = c - 1;
            sum += 1LL * d * d * x - 1LL * c * c * x;
        }
        ans[q] = sum;
    }
    for (int q = 0; q < Q; q++) {
        cout << ans[q] << '\n';
    }
    return 0;
}