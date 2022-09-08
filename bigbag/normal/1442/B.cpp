#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;

int t, n, k, a[max_n], b[max_n], pos[max_n];
bool f[max_n];

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int solve() {
    set<int> q;
    for (int i = 0; i < n; ++i) {
        q.insert(i);
        f[i] = 1;
    }
    for (int i = 0; i < k; ++i) {
        f[pos[b[i]]] = 0;
    }
    int ans = 1;
    for (int i = 0; i < k; ++i) {
        auto nxt = q.upper_bound(pos[b[i]]);
        int cnt = 0;
        if (nxt != q.end()) {
            cnt += f[*nxt];
        }
        auto pr = nxt;
        --pr;
        if (pr != q.begin()) {
            --pr;
            cnt += f[*pr];
        }
        if (!cnt) {
            return 0;
        }
        ans = mul(ans, cnt);
        --nxt;
        q.erase(nxt);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
            pos[a[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            scanf("%d", &b[i]);
            --b[i];
        }
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}