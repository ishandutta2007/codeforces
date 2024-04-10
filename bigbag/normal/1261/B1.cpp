#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

const int max_n = 200222, inf = 1000111222;

int n, m, a[max_n], ans[max_n];
pair<int, int> b[max_n];
vector<pair<int, int>> all[max_n];
ordered_set q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = {a[i], -i};
    }
    sort(b, b + n);
    reverse(b, b + n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int k, pos;
        scanf("%d%d", &k, &pos);
        all[k].push_back({i, pos});
    }
    for (int i = 0; i < n; ++i) {
        q.insert(-b[i].second);
        for (const auto &p : all[i + 1]) {
            int pos = *q.find_by_order(p.second - 1);
            ans[p.first] = a[pos];
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}