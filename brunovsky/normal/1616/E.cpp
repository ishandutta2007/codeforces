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
        string s, t;
        cin >> N >> s >> t;

        if (s < t) {
            cout << 0 << '\n';
            continue;
        }

        ordered_set<int> active;
        for (int i = 0; i < N; i++) {
            active.insert(i);
        }

        constexpr int A = 26, L = 'a';
        array<vector<int>, A> pos = {};
        for (int i = N - 1; i >= 0; i--) {
            pos[s[i] - L].push_back(i);
        }

        int64_t ans = INT64_MAX;
        int64_t cur = 0;

        for (int i = 0, k = 0; cur < ans && k < N && i < N; k++) {
            int target = t[k] - L;
            if (s[i] < t[k]) {
                ans = min(ans, cur);
                break;
            }
            // First consider the moving a strictly lower character here
            int closest = INT_MAX, closest_char = -1;
            for (int c = target - 1; c >= 0; c--) {
                if (!pos[c].empty()) {
                    int j = pos[c].back();
                    if (closest_char == -1 || closest > j) {
                        closest = j;
                        closest_char = c;
                    }
                }
            }
            if (closest_char != -1) {
                int j = closest;
                int x = active.order_of_key(j);
                int after = N - j;
                int set_after = int(active.size()) - x;
                int more = after - set_after;
                ans = min(ans, cur + (j + more) - k);
            }
            // Now consider moving the same character here
            if (s[i] > t[k]) {
                if (pos[target].empty()) {
                    debug("DONE EMPTY", i);
                    break;
                } else {
                    // Move this index back to position k
                    int j = pos[target].back();
                    pos[target].pop_back();

                    int x = active.order_of_key(j);
                    int after = N - j - 1;
                    int set_after = int(active.size()) - x - 1;
                    int moved = after - set_after;
                    debug(s, t, cur, i, j, moved);
                    cur += j - k + moved;

                    active.erase(j);
                }
            } else {
                pos[s[i] - L].pop_back();
                do {
                    i++;
                } while (i < N && end(active) == active.find(i));
            }
        }

        cout << (ans == INT64_MAX ? -1 : ans) << '\n';
    }
    return 0;
}