#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

namespace gnu = __gnu_pbds;

template <typename T, typename CompareFn = less<T>>
using ordered_set = gnu::tree<T, gnu::null_type, CompareFn, gnu::rb_tree_tag,
                              gnu::tree_order_statistics_node_update>;

#define long int64_t

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    vector<int> id(N);
    iota(begin(id), end(id), 1);
    sort(begin(id), end(id), [&](int a, int b) { return A[a] > A[b]; });
    ordered_set<int> previous;
    long ans = 0;
    for (int y = N, j = 0; y >= 1; y--) {
        while (j < N && y <= A[id[j]]) {
            previous.insert(id[j++]);
        }
        ans += previous.order_of_key(A[y] + 1);
        ans -= y <= A[y];
    }
    return ans / 2;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}