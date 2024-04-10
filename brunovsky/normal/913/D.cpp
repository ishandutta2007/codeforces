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
    int N, T;
    cin >> N >> T;
    vector<int> a(N), t(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> t[i];
    }
    vector<vector<int>> by_cap(N + 1);
    for (int i = 0; i < N; i++) {
        by_cap[a[i]].push_back(i);
    }
    ordered_set<pair<int, int>> oset;
    int prefix = 0;
    auto erase = [&](int i, int k) {
        int S = oset.size();
        int r = oset.order_of_key(make_pair(t[i], i));
        if (r < k) {
            prefix -= t[i];
            if (S > k) {
                prefix += oset.find_by_order(k)->first;
            }
        }
        oset.erase(make_pair(t[i], i));
    };
    for (int i = 0; i < N; i++) {
        oset.insert(make_pair(t[i], i));
    }
    int ans = 0;
    for (int k = 1; k <= N; k++) {
        prefix += oset.find_by_order(k - 1)->first;
        int S = oset.size();
        if (prefix > T || S < k) {
            break;
        } else {
            ans = k;
        }
        for (int x : by_cap[k]) {
            erase(x, k);
        }
    }
    vector<pair<int, int>> ids;
    for (int i = 0; i < N; i++) {
        if (a[i] >= ans) {
            ids.emplace_back(t[i], i);
        }
    }
    sort(begin(ids), end(ids));
    cout << ans << '\n';
    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << ids[i].second + 1 << " \n"[i + 1 == ans];
    }
    return 0;
}