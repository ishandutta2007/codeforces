#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500005;
vector<int> G[kMaxN];
bool Viz[kMaxN][2];
int InStack[kMaxN];
int DP[kMaxN][2];
bool can_draw = false;

void DFS(int node, int col) {
    Viz[node][col] = true;
    InStack[node] += 1;
    DP[node][col] = -1;

    bool is_leaf = true;
    for (auto vec : G[node]) {
        is_leaf = false;

        if (InStack[vec]) { can_draw = true; }
        if (!Viz[vec][!col]) {
            DFS(vec, !col);
            if (DP[vec][!col] != -1) { 
                DP[node][col] = vec; 
            }
        }
    }
    if (is_leaf && col == 0) 
        DP[node][col] = node;
    InStack[node] -= 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        while (k--) {
            int x; cin >> x; --x;
            G[i].push_back(x);
        }
    }

    int s; cin >> s; --s; 
    DFS(s, 1);
    
    if (DP[s][1] != -1) {
        cout << "Win" << endl;
        int bit = 1;
        cout << s + 1 << " ";
        while (true) {
            int nxt = DP[s][bit];
            if (nxt == s) return 0;
            cout << nxt + 1 << " ";
            s = nxt;
            bit = !bit;
        }
        return 0;
    }
    if (can_draw) {
        cout << "Draw" << endl;
        return 0;
    }
    cout << "Lose" << endl;

    return 0;
}