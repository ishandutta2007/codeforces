#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 400100;
const int MOD = 1000000007;

int n, k, t1, t2, root, del;
vector <int> adj[MAXN];
int sz[MAXN], dist[MAXN], depth[MAXN];

void dfs_sz(int node, int prev) {
    sz[node] = 1;
    if(adj[node].size() == 1 && node != prev) {
        depth[node] = 0;
        return;
    }
    for(auto next : adj[node]) {
        if(next==prev) continue;
        dfs_sz(next, node);
        sz[node] += sz[next];
        depth[node] = max(depth[node], depth[next] + 1);
    }
}

void dfs_find_root(int node, int prev) {
    // cout << node << endl;
    pair<int, int> g = {-1, -1};
    for(auto next : adj[node]) {
        if(next == prev) continue;
        if(sz[next] > g.first) {
            g.first = sz[next];
            g.second = next;
        }
    }
    if(g.first <= n/2) {
        root = node;
        return;
    }
    else {
        dfs_find_root(g.second, node);
    }
}

void bfs(int start) {
    forn(i, 0, n) dist[i] = -1;
    queue <int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

void dfs_final(int node, int prev) {
    if(depth[node] < k) {
        del += sz[node];
        return;
    }
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs_final(next, node);
    }
}

void solve() {
    cin >> n >> k;
    del = 0;
    forn(i, 0, n) {
        adj[i].clear();
        sz[i] = 0;
        depth[i] = -1;
    }
    forn(i, 0, n - 1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    bfs(0);
    int a = 0, temp = -1;
    forn(i, 0, n) {
        if(dist[i] > temp) {
            a = i;
            temp = dist[i];
        }
    }
    bfs(a);
    int b = 0; temp = -1;
    forn(i, 0, n) {
        if(dist[i] > temp) {
            b = i;
            temp = dist[i];
        }
    }
    // Now max diameter is equal to temp. 6 -> 3, 5 -> 2 temp/2.
    int curr = b, temp_dist = temp;
    while(true) {
        if(temp_dist == temp/2) break;
        for(auto prev : adj[curr]) {
            if(dist[prev] == dist[curr] - 1) {
                curr = prev;
                temp_dist--;
                continue;
            }
        }
    }
    // cout << curr + 1 << endl;
    root = curr;
    // dfs_sz(0, 0);
    // dfs_find_root(0, 0);
    // // forn(i, 0, n) cout << sz[i] << " ";
    // cout << root + 1 << endl;
    bfs(root);
    forn(i, 0, n) depth[i] = -1;
    dfs_sz(root, root);
    // // forn(i, 0, n) cout << depth[i] << " ";
    dfs_final(root, root);

    // cout << temp_dist << endl;
    
    if(temp % 2 == 1 && depth[root] == k) {
        cout << 0 << endl;
        return;
    }

    cout << n - del << endl;
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