/**
 *  created: 30/12/2020, 17:40:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, mod = 1000000007;

struct dsu {
    int p_or_sz[max_n];
    bool ok[max_n];

    dsu() {
    }

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p_or_sz[i] = -1;
            ok[i] = 0;
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
        ok[v2] |= ok[v1];
        p_or_sz[v2] += p_or_sz[v1];
        p_or_sz[v1] = v2;
        return true;
    }
};

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int q, n;
dsu d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &q, &n);
    d.init(n);
    vector<int> ans;
    for (int i = 1; i <= q; ++i) {
        int k;
        scanf("%d", &k);
        if (k == 1) {
            int v;
            scanf("%d", &v);
            --v;
            v = d.find_set(v);
            if (!d.ok[v]) {
                ans.push_back(i);
                d.ok[v] = 1;
            }
        } else {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            if (d.ok[d.find_set(u)] && d.ok[d.find_set(v)]) {
                continue;
            }
            if (d.union_set(u, v)) {
                ans.push_back(i);
            }
        }
    }
    int cnt = 1;
    for (int i = 0; i < ans.size(); ++i) {
        cnt = mul(cnt, 2);
    }
    printf("%d %d\n", cnt, ans.size());
    for (int id : ans) {
        printf("%d ", id);
    }
    puts("");
    return 0;
}