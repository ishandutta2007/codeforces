#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>
#include <iostream>

using namespace std;

const int kMaxN = 500005;

int D1[kMaxN], DX[kMaxN];
vector<int> G[kMaxN];

void DFS(int node, int par, int D[]) {
    D[node] = D[par] + 1;
    for (auto vec : G[node])
        if (vec != par)
            DFS(vec, node, D);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    for (int i = 2; i <= n; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    D1[0] = DX[0] = -1;
    DFS(1, 0, D1);
    DFS(x, 0, DX);
    

    int ans = 0;
    for (int node = 1; node <= n; ++node) {
        if (DX[node] < D1[node]) {
            //cerr << "OK " << node << endl;
            ans = max(ans, 2 * D1[node]);
        }
    }

    cout << ans << endl;

    return 0;
}