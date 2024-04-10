#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m; cin >> n >> m;
    vector<int> dsu(m), cnt(m);
    for (int i = m; i--; ) dsu[i] = i;
    
    function<int(int)> findp = [&](int u) {
        return u == dsu[u] ? u : dsu[u] = findp(dsu[u]);
    };
    
    auto join = [&](int u, int v) {
        dsu[findp(u)] = findp(v);
    };
    
    int stupid = 0;
    while (n--) {
        int k; cin >> k;
        if (k == 0) {
            ++stupid;
            continue;
        }
        int u; cin >> u; --u;
        cnt[u]++;
        for (int i = 1; i < k; ++i) {
            int v; cin >> v; --v;
            join(u, v);
            cnt[v]++;
        }
    }
    
    int active = 0;
    for (int i = m; i--; ) {
        if (i != findp(i)) continue;
        if (cnt[i] == 0) continue;
        ++active;
    }
    cout << max(active - 1, 0) + stupid;
}