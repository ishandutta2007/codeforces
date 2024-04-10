#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()

namespace Solution {

int n, m;
ve<bool> state;
ve<vi> door;
ve<vi> gr, rgr;

void makeedge(int u, int v) {
    gr[u ^ 1].push_back(v);
    gr[v ^ 1].push_back(u);
    rgr[v].push_back(u ^ 1);
    rgr[u].push_back(v ^ 1);
}

vi st, vis, comp;
void dfs(int u) {
    vis[u] = 1;
    for (int i = -1; ++i < sz(gr[u]);) {
        int v = gr[u][i];
        if (vis[v] == 0) dfs(v);
    }
    st.push_back(u);
}

int cnt = 0;
void unite(int u) {
    vis[u] = 2;
    comp[u] = cnt;
    for (int i = -1; ++i < sz(rgr[u]);) {
        int v = rgr[u][i];
        if (vis[v] < 2) unite(v);
    }
}

bool process() {
    vis.resize(2 * m);
    comp.resize(2 * m);
    for (int i = -1; ++i < 2 * m;) 
        if (vis[i] == 0) {
            dfs(i);
        }
    for (; sz(st); st.pop_back()) {
        int u = st.back();
        if (vis[u] == 2) continue;
        ++cnt;
        unite(u);
    }
    for (int i = 0; i < 2 * m; i += 2) {
        if (comp[i] == comp[i + 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    cin >> n >> m;
    state.resize(n); door.resize(n);
    for (int i = -1; ++i < n; ) {
        int t; cin >> t; state[i] = t;
    }
    for (int i = -1; ++ i < m; ) {
        int t; cin >> t;
        while (t--) {
            int u; cin >> u;
            door[--u].push_back(i);
        }
    }
    
    gr.resize(m * 2);
    rgr.resize(m * 2);
    for (int i = -1; ++i < n; ) {
        int u = door[i][0] << 1, v = door[i][1] << 1;
        if (!state[i]) {
            makeedge(u, v);
            makeedge(u ^ 1, v ^ 1);
        } else {
            makeedge(u, v ^ 1);
            makeedge(u ^ 1, v);
        }
    }

    if (process()) cout << "YES";
    else cout << "NO";
    

    return 0;
}}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    return Solution::main();
}