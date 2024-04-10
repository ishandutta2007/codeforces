#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500005;
vector<int> G[kMaxN];
int Parent[kMaxN];

pair<int, int> GetFarthest(int node, int par, int depth) {
    Parent[node] = par;
    pair<int, int> ans{depth, node};
    
    for (auto vec : G[node]) {
        if (vec == par) continue;
        ans = max(ans, GetFarthest(vec, node, depth + 1));
    }

    return ans;
}

long long total = 0;
vector<tuple<int, int, int>> ans;

void Push(int a, int b, int with) {
    ans.emplace_back(a, b, a);
    total += with;
}

void Propagate(int node, int par, int alt, int depth) {
    for (auto vec : G[node]) {
        if (vec == par) continue;
        Propagate(vec, node, alt, depth + 1);
    }
    Push(node, alt, depth);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int a, b, diam;
    a = GetFarthest(1, -1, 0).second;
    tie(diam, b) = GetFarthest(a, -1, 0);

    for (int it = 0; it < 2; ++it) {
        for (int node = b, da = diam, db = 0, last = -1; node != -1; 
                last = node, node = Parent[node], --da, ++db) {
            
            if (it == 0) {
                for (auto vec : G[node]) { 
                    if (vec == Parent[node] or vec == last)
                        continue;

                    Propagate(vec, node, da < db ? b : a, da < db ? db + 1 : da + 1);
                }
            } else {
                if (node != a) {
                    Push(node, a, da);
                }
            }
        }
    }
    
    cout << total << endl;
    for (auto x : ans) {
        int a, b, c; tie(a, b, c) = x;
        cout << a << ' ' << b << ' ' << c << ' ' << '\n';
    }

    return 0;
}