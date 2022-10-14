#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace gnu = __gnu_pbds;

template <typename Key, typename Value, typename CompareFn = less<Key>>
using ordered_map = gnu::tree<Key, Value, CompareFn, gnu::rb_tree_tag,
                              gnu::tree_order_statistics_node_update>;

template <typename T, typename CompareFn = less<T>>
using ordered_set = ordered_map<T, gnu::null_type, CompareFn>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i];
        }
        rotate(begin(p), find(begin(p), end(p), 1), end(p));
        vector<int> rank(N + 1);
        for (int i = 0; i < N; i++) {
            rank[p[i]] = i;
        }
        ordered_set<pair<int, int>> oset;
        oset.insert({rank[1], 1});
        oset.insert({rank[2], 2});
        uint64_t ans = 0;
        int k = 2;
        for (int n = 3; n <= N; n++) {
            int r = oset.order_of_key({rank[n], n});
            int add = r >= k ? r - k : n - 1 - k + r;
            ans += 1LL * add * (N - n + 1);
            oset.insert({rank[n], n});
            k = r + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}