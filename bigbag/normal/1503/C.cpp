/**
 *  created: 03/04/2021, 18:09:06
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

struct dsu {
    int p_or_sz[max_n];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p_or_sz[i] = -1;
        }
    }

    int find_set(int v) {
        if (p_or_sz[v] < 0) {
            return v;
        }
        return p_or_sz[v] = find_set(p_or_sz[v]);
    }

    bool union_set(int v1, int v2) {
        v1 = find_set(v1);
        v2 = find_set(v2);
        if (v1 == v2) {
            return false;
        }
        if (-p_or_sz[v1] > -p_or_sz[v2]) {
            swap(v1, v2);
        }
        p_or_sz[v2] += p_or_sz[v1];
        p_or_sz[v1] = v2;
        return true;
    }
};

int n, a[max_n], c[max_n];
long long ans;
dsu d;

bool cmp_by_c(int id1, int id2) {
    return c[id1] < c[id2];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    set<pair<pair<int, int>, int>> q;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &c[i]);
        ans += c[i];
        c[i] += a[i];
    }
    vector<int> order;
    for (int i = 0; i < n; ++i) {
        order.push_back(i);
        //cout << "#" << a[i] << " " << c[i] << endl;
        q.insert({{a[i], c[i]}, i});
    }
    sort(order.begin(), order.end(), cmp_by_c);
    d.init(n);
    for (int i : order) {
        //auto it = --q.end();
        auto it = q.upper_bound(make_pair(make_pair(c[i] + 1, -1), -1));
        if (it != q.begin()) {
            --it;
        }
        if (d.find_set(it->second) == d.find_set(i) && i != order.back()) {
            assert(q.size() > 1);
            if (it == q.begin()) {
                ++it;
            } else {
                --it;
            }
        }
        //cout << i << " -> " << it->second << ": " << max(0, it->first.first - c[i]) << endl;
        ans += max(0, it->first.first - c[i]);
        d.union_set(i, it->second);
        q.erase(it);
    }
    cout << ans << "\n";
    return 0;
}