#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector <int> d;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

// u is an ancestor of v
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void dfs_depth(int node, int prev, int dist) {
    d[node] = dist;
    for(auto next : adj[node]) {
        if(next != prev) {
            dfs_depth(next, node, dist + 1);
        }
    }
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    preprocess(0);
    d.resize(n);
    dfs_depth(0, 0, 0);

    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        deque <int> v(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i];
            --v[i];
        }
        sort(v.begin(), v.end(), [&](int a, int b) {
            return d[a] < d[b];
        });
        if(k == 1) {
            cout << "YES\n";
            continue;
        }
        int lca = LCA(v[0], v[1]);
        for(int i = 2; i < k; i++) {
            lca = LCA(lca, v[i]);
        }
        if(v.front() != lca) {
            v.push_front(lca);
            k++;
        }
        deque <int> left;
        int curr = v.front();
        int first = -1;
        for(int i = 1; i < k; i++) {
            if(is_ancestor(curr, v[i])) {
                curr = v[i];
                if(first == -1) first = v[i];
            } else {
                left.push_back(v[i]);
            }
        }
        if(left.empty()) {
            cout << "YES" << '\n';
            continue;
        }
        bool pos = true;
        int second = left.front();
        if(LCA(first, second) != lca) pos = false;
        left.push_front(v.front());
        for(int i = 1; i < (int)left.size(); i++) {
            if(is_ancestor(left[i - 1], left[i])) continue;
            pos = false;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}