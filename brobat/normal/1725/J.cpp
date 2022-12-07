#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<pair<int, int>>> adj;

struct S {
    pair<int, int> p; // parent + weight.
    vector<pair<int, int>> up; // 3 largest paths up with index
    vector<pair<int, int>> path; // 2 largest independent paths (not crossing subtrees)
    int wt; // weight of the subtree
    int sub, super; // ans for sub and super tree
    int down; // largest path down
};
vector<S> v;    
int total;

void print(const S& s) {
    cout << "Parent = " << s.p.first << " with weight = " << s.p.second << '\n';
    cout << "3 largest paths up : ";
    for(auto i : s.up) cout << "{" << i.first << "," << i.second << "} ";
    cout << '\n';
    cout << "2 largest independent paths : ";
    for(auto i : s.path) cout << "{" << i.first << "," << i.second << "} ";
    cout << '\n';
    cout << "Weight of subtree = " << s.wt << '\n';
    cout << "Ans for subtree = " << s.sub << " and supertree = " << s.super << '\n';
    cout << "Largest path down = " << s.down << '\n';
    cout << '\n';
}

void dfs_down(int node, int prev) {
    vector<pair<int, int>> up;
    vector<pair<int, int>> path;
    for(auto zz : adj[node]) {
        int nx = zz.first;
        int wt = zz.second;
        if(nx == prev) continue;
        v[nx].p = {node, wt};
        dfs_down(nx, node);
        up.push_back({v[nx].up.front().first + wt, nx});
        path.push_back({v[nx].sub, nx});
        v[node].wt += wt + v[nx].wt;
        v[node].sub = max(v[node].sub, v[nx].sub);
    }
    sort(up.begin(), up.end(), greater<pair<int, int>>());
    for(int i = 0; i < min(4ll, (int)up.size()); i++) {
        v[node].up[i] = up[i];
    }
    sort(path.begin(), path.end(), greater<pair<int, int>>());
    for(int i = 0; i < min(2ll, (int)path.size()); i++) {
        v[node].path[i] = path[i];
    }
    v[node].sub = max({v[node].sub, v[node].up[0].first + v[node].up[1].first});
}

void dfs_up(int node, int prev) {
    if(node == prev) {
        for(auto next : adj[node]) dfs_up(next.first, node);
        return;
    }
    v[node].down = v[prev].down + v[prev].p.second;
    v[node].super = max(v[prev].super, v[node].down);
    vector <int> all;
    all.push_back(v[node].down);
    for(int i = 0; i < 4; i++) {
        if(v[prev].up[i].second != node) {
            all.push_back(v[prev].up[i].first);
            v[node].down = max(v[node].down, v[prev].up[i].first);
        }
    }
    for(int i = 0; i < 2; i++) {
        if(v[prev].path[i].second != node) {
            v[node].super = max(v[node].super, v[prev].path[i].first);
        }
    }
    for(int i = 0; i < (int)all.size(); i++) {
        v[node].super = max(v[node].super, all[i]);
        for(int j = i + 1; j < (int)all.size(); j++) {
            v[node].super = max(v[node].super, all[i] + all[j]);
        }
    }
    for(auto next : adj[node]) if(next.first != prev) dfs_up(next.first, node);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    adj.resize(n);
    v.resize(n);
    total = 0;
    for(int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        total += w;
    }
    for(int i = 0; i < n; i++) {
        v[i].p = {-1, 0};
        v[i].up.resize(4, {0, -1});
        v[i].path.resize(2, {0, -1});
        v[i].wt = v[i].sub = v[i].super = v[i].down = 0;
    }
    dfs_down(0, 0);
    // for(int i = 0; i < n; i++) print(v[i]);
    dfs_up(0, 0);
    // for(int i = 0; i < n; i++) print(v[i]);
    int ans = (int)1E18;
    for(int i = 0; i < n; i++) {
        if(i > 0) ans = min(ans, 2*total - 2*v[i].p.second - v[i].sub - v[i].super);
        // int temp = 0;
        vector <int> temp;
        temp.push_back(v[i].down + v[i].p.second);
        // temp += v[i].down + v[i].p.second;
        for(auto i : v[i].up) temp.push_back(i.first);
        sort(temp.begin(), temp.end(), greater<int>());
        ans = min(ans, 2*total - temp[0] - temp[1] - temp[2] - temp[3]);
    }
    cout << ans;

    return 0;
}