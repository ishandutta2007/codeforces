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

int n;
pair<int, int> p[max_n];
long long ans;
ordered_set q;

int get_cnt(int r) {
    return q.order_of_key(r + 1);
}

int get_cnt(int l, int r) {
    return get_cnt(r) - get_cnt(l - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].second, &p[i].first);
    }
    sort(p, p + n);
    reverse(p, p + n);
    for (int i = 0; i < n; ) {
        int pos = i;
        while (i < n && p[i].first == p[pos].first) {
            int from = -inf;
            if (i + 1 < n && p[i].first == p[i + 1].first) {
                from = p[i + 1].second + 1;
            }
            //cout << i << ": " << (1 + get_cnt(p[i].second + 1, inf)) << "*" << (1 + get_cnt(from, p[i].second - 1)) << endl;
            ans += 1LL * (1 + get_cnt(p[i].second + 1, inf)) * (1 + get_cnt(from, p[i].second - 1));
            //cout << "add " << p[i].second << endl;
            q.insert(p[i].second);
            ++i;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}