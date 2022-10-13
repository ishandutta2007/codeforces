#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> in(n);
    vector<int> out(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        if (a < b) swap(a, b);
        out[a] += 1;
        in[b].push_back(a);
    }

    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += 1LL * out[i] * in[i].size();
    }

    int q; cin >> q;
    for (int i = 0; i <= q; ++i) {
        if (i > 0) {
            int x; cin >> x; --x;
            total -= 1LL * out[x] * in[x].size();
            for (auto oth : in[x]) {
                total -= in[oth].size();
                out[oth] -= 1;
                in[oth].push_back(x);
                out[x] += 1;
                total += out[oth];
            }
            in[x].clear();
        }
               
        cout << total << '\n';
    }

    return 0;
}