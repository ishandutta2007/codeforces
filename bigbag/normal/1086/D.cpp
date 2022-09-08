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
const int max_c = 111;

int n, q;
char buf[max_n];
int tr[3][max_c];

void init() {
    tr[0]['R'] = 'R';
    tr[0]['P'] = 'P';
    tr[0]['S'] = 'S';

    tr[1]['R'] = 'P';
    tr[1]['P'] = 'S';
    tr[1]['S'] = 'R';

    tr[2]['R'] = 'S';
    tr[2]['P'] = 'R';
    tr[2]['S'] = 'P';
}

int get_num(char c) {
    if (c == 'R') {
        return 0;
    } else if (c == 'S') {
        return 1;
    }
    return 2;
}

struct solver {
    int a[max_n];
    ordered_set q[3];

    void init() {
        for (int i = 0; i < n; ++i) {
            q[a[i]].insert(i);
        }
    }

    void upd(int pos, char c) {
        q[a[pos]].erase(pos);
        a[pos] = get_num(c);
        q[a[pos]].insert(pos);
    }

    int solve() const {
        if (q[1].empty()) {
            if (q[2].empty()) {
                return n;
            }
            return 0;
        }
        int mn = *q[1].begin();
        int mx = *q[1].rbegin();
        int res = q[0].order_of_key(mx) - q[0].order_of_key(mn);
        if (!q[2].empty()) {
            mn = min(mn, *q[2].begin());
            mx = max(mx, *q[2].rbegin());
        }
        res += mn + n - mx - 1;
        return res;
    }
};

solver s[3];

int solve() {
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        res += s[i].solve();
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    scanf("%d%d%s", &n, &q, buf);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i].a[j] = get_num(tr[i][buf[j]]);
        }
        s[i].init();
    }
    printf("%d\n", solve());
    while (q--) {
        int pos;
        char c;
        scanf("%d %c", &pos, &c);
        --pos;
        for (int i = 0; i < 3; ++i) {
            s[i].upd(pos, tr[i][c]);
        }
        printf("%d\n", solve());
    }
    return 0;
}