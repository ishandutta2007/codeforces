#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int parent[MAXN], num_leaves[MAXN];
bool isLeaf[MAXN];
unordered_set <int> adj[MAXN];
queue <int> bud;
int n, t1, t2;
int B, L;

void dfs(int node, int prev) {
    if(adj[node].size()==1 && node != 0) {
        isLeaf[node] = true;
        num_leaves[prev]++;
    }
    parent[node] = prev;
    for(auto next : adj[node]) {
        if(next != prev) dfs(next, node);
    }
    if(node != 0 && adj[node].size() > 1 && num_leaves[node] == adj[node].size()-1) bud.push(node);
}

void pre() {
    cin >> n;
    forn(i, 0, n) {
        parent[i] = i;
        isLeaf[i] = false;
        adj[i].clear();
        num_leaves[i] = 0;
    }
    while(!bud.empty()) bud.pop();
    B = 0; L = 0;
    forn(i, 0, n - 1) {
        cin >> t1 >> t2;
        adj[--t1].insert(--t2);
        adj[t2].insert(t1);
    }
}

void solve() {
    pre();
    dfs(0, 0);
    // while(!bud.empty()) {
    //     cout << bud.front() << " ";
    //     bud.pop();
    // }
    while(!bud.empty()) {
        int x = bud.front();
        // cerr << x << " ";
        bud.pop();
        B++;
        L += adj[x].size() - 1;
        // auto it = adj[parent[x]]
        int y = parent[x];
        adj[y].erase(x);
        // if(adj[parent[x]].size() - 1 == num_leaves[parent[x]] && parent[x]!=0) bud.push(parent[x]);
        // Now make changes to parent[x].
        if(y == 0) continue;
        if(adj[y].size() == 1) {
            isLeaf[y] = true;
            num_leaves[parent[y]]++;
            // Now we want to check if parent[y] can be a bud.
            int node = parent[y];
            if(node != 0 && adj[node].size() > 1 && num_leaves[node] == adj[node].size()-1) bud.push(node);
        }
        else {
            // Check if y can be a bud.
            int node = y;
            if(node != 0 && adj[node].size() > 1 && num_leaves[node] == adj[node].size()-1) bud.push(node);
        }
    }
    cout << L - (B - 1) + max((int)adj[0].size(), (int)1) - 1;
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}