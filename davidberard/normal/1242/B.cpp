#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;
set<int> unvisited;
set<int> bad[N];
int n, m;

int k;

void dfs(int u) {
    unvisited.erase(u);
    int v = 0;
    while (v < N) {
        auto it = unvisited.upper_bound(v);
        if (it == unvisited.end()) {
            break;
        }
        v = *it;
        if (!bad[u].count(v)) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        unvisited.insert(i);
    }
    for (int i=1; i<=m; ++i) {
        int a, b;
        cin >> a >> b;
        bad[a].insert(b);
        bad[b].insert(a);
    }
    for (int i=1; i<=n; ++i) {
        if (unvisited.count(i)) {
            ++k;
            dfs(i);
        }
    }
    cout << k-1 << endl;

    return 0;
}