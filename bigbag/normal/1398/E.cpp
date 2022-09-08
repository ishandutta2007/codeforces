#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

struct segment_tree {
    int cnt[4 * max_n];
    long long sum[4 * max_n];

    void update(int v, int l, int r, int x, int value, int z) {
        if (l == r) {
            sum[v] += value;
            cnt[v] += z;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value, z);
        } else {
            update(2 * v + 1, mid + 1, r, x, value, z);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
    }

    long long get_sum_k(int v, int k) {
        if (!k) {
            return 0;
        }
        if (cnt[v] <= k) {
            return sum[v];
        }
        long long res = get_sum_k(2 * v + 1, k);
        k -= cnt[2 * v + 1];
        if (k > 0) {
            res += get_sum_k(2 * v, k);
        }
        return res;
    }
};

int n, tp[max_n], d[max_n], z[max_n];
multiset<int> a[2];
long long sum[2];
vector<int> all;
segment_tree t;

int compress(int x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin();
}

long long solve() {
    if (a[1].empty()) {
        return sum[0];
    }
    if (a[0].empty()) {
        return 2 * sum[1] - *a[1].begin();
    }
    int mn = *a[1].begin(), mx = *a[0].rbegin();
    long long topk = t.get_sum_k(1, a[1].size());
    long long res = sum[0] + sum[1] + topk;
    if (mn > mx) {
        res -= mn;
        res += mx;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &tp[i], &d[i]);
        z[i] = d[i] / abs(d[i]);
        all.push_back(abs(d[i]));
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i < n; ++i) {
        t.update(1, 0, all.size() - 1, compress(abs(d[i])), d[i], z[i]);
        sum[tp[i]] += d[i];
        if (z[i] < 0) {
            a[tp[i]].erase(a[tp[i]].find(-d[i]));
        } else {
            a[tp[i]].insert(d[i]);
        }
        printf("%I64d\n", solve());
    }
    return 0;
}