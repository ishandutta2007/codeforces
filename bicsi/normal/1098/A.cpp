#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> parent(n, -1);
    vector<vector<int>> graph(n);

    for (int i = 1; i < n; ++i) {
        cin >> parent[i]; --parent[i];
        graph[parent[i]].push_back(i);
    }

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> a(n, -1);
    for (int i = 0; i < n; ++i) {
        if (s[i] != -1) {
            a[i] = s[i];
            if (parent[i] != -1)
                a[i] -= s[parent[i]];
        } else {
            if (graph[i].empty()) {
                s[i] = s[parent[i]];
                a[i] = 0;
            } else {
                s[i] = 2e18;
                for (auto j : graph[i]) {
                    s[i] = min(s[i], s[j]);
                }
                a[i] = s[i] - s[parent[i]];
            }
        }
    }


    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
        ret += a[i];
    }
    cout << ret << endl;

    return 0;
}