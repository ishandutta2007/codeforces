/**
 *  created: 25/03/2021, 15:47:17
 *  pause: 16:11 - 16:18
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_x = 2 * max_n;

vector<long long> all;

struct node {
    int cnt;
    long long sum, sum_l, sum_r;

    friend ostream& operator << (ostream &os, const node &nd) {
        os << "(cnt = " << nd.cnt << ", s = " << nd.sum << ", sl = " << nd.sum_l << ", sr = " << nd.sum_r << ")";
        return os;
    }
};

node combine(const node &a, const node &b) {
    return {a.cnt + b.cnt,
            a.sum + b.sum,
            a.sum_l + b.sum_l + a.sum * b.cnt,
            a.sum_r + b.sum_r + b.sum * a.cnt};
}

struct segment_tree {
    node a[4 * max_x];

    void build(int v, int l, int r, int cnt[]) {
        if (l == r) {
            a[v] = {cnt[l], cnt[l] * all[l], cnt[l] * all[l], cnt[l] * all[l]};
            //cout << v << ": [" << l << " " << r << "], nd = " << a[v] << endl;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, cnt);
        build(2 * v + 1, mid + 1, r, cnt);
        a[v] = combine(a[2 * v], a[2 * v + 1]);
        //cout << v << ": [" << l << " " << r << "], nd = " << a[v] << endl;
    }

    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            a[v] = {value, value * all[l], value * all[l], value * all[l]};
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        a[v] = combine(a[2 * v], a[2 * v + 1]);
    }

    node get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return combine(get_sum(2 * v, tl, mid, l, mid), get_sum(2 * v + 1, mid + 1, tr, mid + 1, r));
    }

    long long get_sum_left(int v, int tl, int tr, int k) {
        if (tl == tr) {
            if (k == 1) {
                return a[v].sum;
            }
            return 0;
        }
        int mid = (tl + tr) / 2;
        if (k <= a[2 * v].cnt) {
            return get_sum_left(2 * v, tl, mid, k);
        }
        return a[2 * v].sum + get_sum_left(2 * v + 1, mid + 1, tr, k - a[2 * v].cnt);
    }

    long long get_sum_right(int v, int tl, int tr, int k) {
        if (tl == tr) {
            if (k == 1) {
                return a[v].sum;
            }
            return 0;
        }
        int mid = (tl + tr) / 2;
        if (k <= a[2 * v + 1].cnt) {
            return get_sum_right(2 * v + 1, mid + 1, tr, k);
        }
        return a[2 * v + 1].sum + get_sum_right(2 * v, tl, mid, k - a[2 * v + 1].cnt);
    }

    node get_node_left(int v, int tl, int tr, int k) {
        if (tl == tr) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (k <= a[2 * v].cnt) {
            return get_node_left(2 * v, tl, mid, k);
        }
        return combine(a[2 * v], get_node_left(2 * v + 1, mid + 1, tr, k - a[2 * v].cnt));
    }

    node get_node_right(int v, int tl, int tr, int k) {
        if (tl == tr) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (k <= a[2 * v + 1].cnt) {
            return get_node_right(2 * v + 1, mid + 1, tr, k);
        }
        return combine(get_node_right(2 * v, tl, mid, k - a[2 * v + 1].cnt), a[2 * v + 1]);
    }
};

int n, q, tp[max_n], cnt[max_x];
long long a[max_n], b[max_n];
segment_tree st;

int compress(long long x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin();
}

long long solve() {
    //cout << "#" << st.a[1] << endl;
    long long res = st.a[1].sum_r - st.a[1].sum_l;
    const int k = st.a[1].cnt;
    if (k >= 3) {
        int pos = (k + 1) / 2 - 2;
        long long sr = st.get_sum_right(1, 0, all.size() - 1, pos + 1);
        long long sl = st.get_sum_left(1, 0, all.size() - 1, pos + 2);
        if (sr > sl) {
            int l = pos, r = k - 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                long long sr = st.get_sum_right(1, 0, all.size() - 1, mid + 1);
                long long sl = st.get_sum_left(1, 0, all.size() - 1, mid + 2);
                if (sr > sl) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            int to = l;
            l = -1;
            r = pos;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                long long sr = st.get_sum_right(1, 0, all.size() - 1, mid + 1);
                long long sl = st.get_sum_left(1, 0, all.size() - 1, mid + 2);
                if (sr > sl) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            int from = r;
            res -= st.get_node_right(1, 0, all.size() - 1, to + 1).sum_r;
            if (from) {
                res += st.get_node_right(1, 0, all.size() - 1, from).sum_r;
            }
            res += st.get_node_left(1, 0, all.size() - 1, to + 2).sum_l;
            res -= st.get_node_left(1, 0, all.size() - 1, from + 1).sum_l;
            /*for (int i = from; i <= to; ++i) {
                //res -= st.get_sum_right(1, 0, all.size() - 1, i + 1) - st.get_sum_left(1, 0, all.size() - 1, i + 2);
                res += st.get_sum_left(1, 0, all.size() - 1, i + 2);
            }*/
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%lld", &tp[i], &b[i]);
    }
    for (int i = 0; i < n; ++i) {
        all.push_back(a[i]);
    }
    for (int i = 0; i < q; ++i) {
        all.push_back(b[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i < n; ++i) {
        cnt[compress(a[i])] = 1;
    }
    st.build(1, 0, all.size() - 1, cnt);
    printf("%lld\n", solve());
    for (int i = 0; i < q; ++i) {
        if (tp[i] == 1) {
            st.update(1, 0, all.size() - 1, compress(b[i]), 1);
        } else {
            st.update(1, 0, all.size() - 1, compress(b[i]), 0);
        }
        printf("%lld\n", solve());
    }
    return 0;
}