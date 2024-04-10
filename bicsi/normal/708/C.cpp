#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> sub, down, up;
int n;

void DFSDown(int node, int par) {
    sub[node] = 1;
    if (par != -1) {
        G[node].erase(find(G[node].begin(), G[node].end(), par));
    }

    for (auto vec : G[node]) {
        DFSDown(vec, node);
        sub[node] += sub[vec];
        down[node] = max(down[node], down[vec]); 
    }
    if (2 * sub[node] <= n)
        down[node] = sub[node];
}
void DFSUp(int node, int up_val) {
    up[node] = up_val;
    
    multiset<int, greater<int>> best = {up_val};
    for (auto vec : G[node])
        best.insert(down[vec]);

    for (auto vec : G[node]) {
        best.erase(best.find(down[vec]));
        
        if (2 * (n - sub[vec]) <= n)
            DFSUp(vec, n - sub[vec]);
        else DFSUp(vec, *best.begin());

        best.insert(down[vec]);
    }
}

int main() {
    cin >> n;
    G.resize(n);
    sub.resize(n);
    down.resize(n);
    up.resize(n);


    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    DFSDown(0, -1);
    DFSUp(0, 0);

    for (int node = 0; node < n; ++node) {
        bool ok = true;
        for (auto vec : G[node]) {
            if (2 * (sub[vec] - down[vec]) > n)
                ok = false;
        }
        if (2 * (n - sub[node] - up[node]) > n)
            ok = false;
        cout << ok << " ";
    }
    cout << endl;

    return 0;
}