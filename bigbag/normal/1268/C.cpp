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

struct fenwick {
    long long a[max_n];

    void update(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            a[i] += x;
        }
    }

    long long get_sum(int r) const {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += a[r];
        }
        return res;
    }

    long long get_sum(int l, int r) const {
        return get_sum(r) - get_sum(l - 1);
    }
};

int n, a[max_n], pos[max_n];
fenwick t1, t2;
ordered_set q;

long long c2(long long x) {
    return x * (x - 1) / 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        pos[a[i]] = i;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += t1.get_sum(pos[i], n);
        t1.update(pos[i], 1);
        t2.update(pos[i], pos[i]);
        q.insert(pos[i]);
        int mid = *q.find_by_order(i / 2);
        long long s1 = t2.get_sum(0, mid);
        long long cnt1 = t1.get_sum(0, mid);
        long long s2 = t2.get_sum(mid + 1, n);
        long long cnt2 = t1.get_sum(mid + 1, n);
        long long res = cnt1 * mid - s1 + s2 - cnt2 * mid - c2(cnt1) - c2(cnt2 + 1);
        //cout << i << ": " << s1 << " " << cnt1 << "   " << s2 << " " << cnt2 << endl;
        //printf("%I64d ", ans);
        printf("%I64d ", ans + res);
    }
    puts("");
    return 0;
}