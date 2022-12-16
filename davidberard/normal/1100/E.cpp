#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

    const int N = 100100;
namespace sccs{
    int low[N], vis[N], comp[N], comps, I;
    vector<int> edges[N]; stack<int> st;
    vector<int> cost[N];
    void dfs(int u, int c) {
        ////cerr << " " << u << " " << c << endl;
        low[u] = vis[u] = ++I;
        st.push(u);
        for(int i=0;i<edges[u].size();++i) {
            if(cost[u][i] < c) continue;
            int v = edges[u][i];
            if(!vis[v]) dfs(v, c);
            if(comp[v] == -1) low[u] = min(low[u], low[v]);
        }
        if(vis[u] <= low[u]) {
            int v;
            do {
                v=st.top();
                st.pop();
                comp[v]=comps;
            } while(v != u);
            ++comps;
        }
    }
    void get_scc(int n, int c) {
        memset(vis, 0, sizeof vis); memset(comp, -1, sizeof comp);
        comps=I=0;
        for(int i=0;i<n;++i) {
            if(!vis[i]) dfs(i, c);
        }
    }
}

vector<vector<int>> edges;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        edges.push_back(vector<int>());
        edges.back().push_back(c);
        edges.back().push_back(u);
        edges.back().push_back(v);
        edges.back().push_back(i);
        sccs::edges[u].push_back(v);
        sccs::cost[u].push_back(c);
    }
    int lo = 1, hi = 1<<30;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        sccs::get_scc(n, mid);
        //cerr << mid << " ! parts " << sccs::comps << endl;
        if(sccs::comps < n) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    int cb = lo; // cost bound

    queue<int> q;
    vector<int> in(n);
    for(int i=0;i<m;++i) {
        if(edges[i][0] >= cb) {
            ++in[edges[i][2]];
        }
    }
    for(int i=0;i<n;++i) {
        if(!in[i]) q.push(i);
    }

    vector<int> arr;
    vector<int> loc(n);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        arr.push_back(u);
        //cerr << " " << u;
        loc[u] = arr.size()-1;
        for(int i=0;i<sccs::edges[u].size();++i) {
            if(sccs::cost[u][i] < cb) continue;
            int v = sccs::edges[u][i];
            if(--in[v] == 0) q.push(v);
        }
    }
    //cerr << endl;
    assert(arr.size() == n);
    vector<int> revs;
    for(int i=0;i<m;++i) {
        if(edges[i][0] < cb) {
            if(loc[edges[i][1]] > loc[edges[i][2]]) {
                revs.push_back(i+1);
            }
        }
    }
    cout << cb-1 << " " << revs.size() << endl;
    for(auto& x : revs) cout << x << " ";
    cout << endl;
    
    
    return 0;
}