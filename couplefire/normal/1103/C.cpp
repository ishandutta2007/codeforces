#include <bits/stdc++.h>
using namespace std;
#define MAXN 250005

vector<int> adj[MAXN];
vector<int> treeAdj[MAXN];
bool visited[MAXN] = {0};
int depth[MAXN];
int n, m, k, l;
vector<vector<int>> cycles;

int timer;
int tin[MAXN], tout[MAXN];
vector<vector<int>> up;

void getTreeAdj(int v = 0, int p = 0, int d = 0){
    depth[v] = d;
    visited[v] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        if(visited[u]) continue;
        treeAdj[v].push_back(u);
        treeAdj[u].push_back(v);
        getTreeAdj(u, v, d+1);
    }
}

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : treeAdj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
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

void preprocess() {
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(0, 0);
}

int getLen(int u, int v){
    return depth[u]+depth[v]-2*depth[lca(u, v)];
}

void printPath(int u, int v, int add){
    cout << "PATH" << endl;
    int len = getLen(u, v)+1;
    if(add>-1) len++;
    cout << len << endl;
    if(add>-1) cout << add+1 << " ";
    int llca = lca(u, v);
    vector<int> r1;
    vector<int> r2;
    while(u != llca){
        r1.push_back(u);
        u = up[u][0];
    }
    r1.push_back(llca);
    while(v != llca){
        r2.push_back(v);
        v = up[v][0];
    }
    reverse(r2.begin(), r2.end());
    for(auto i : r1) cout << i+1 << " ";
    for(auto i : r2) cout << i+1 << " ";
    exit(0);
}

void addCycle(int u, int v){
    int last = cycles.size()-1;
    int llca = lca(u, v);
    vector<int> r1;
    vector<int> r2;
    while(u != llca){
        r1.push_back(u);
        u = up[u][0];
    }
    r1.push_back(llca);
    while(v != llca){
        r2.push_back(v);
        v = up[v][0];
    }
    reverse(r2.begin(), r2.end());
    for(auto i : r1) cycles[last].push_back(i);
    for(auto i : r2) cycles[last].push_back(i);
    if(cycles.size() == k){
        cout << "CYCLES" << endl;
        for(auto i : cycles){
            cout << i.size() << endl;
            for(auto j : i){
                cout << j+1 << " ";
            }
            cout << endl;
        }
        exit(0);
    }
}

void getAns(int v, int p, stack<int> &st){
    st.push(v);
    if(st.size()-1 >= ceil((n+0.0)/k)){
        cout << "PATH" << endl;
        cout << st.size() << endl;
        while(st.size()>0){
            cout << st.top()+1 << " ";
            st.pop();
        }
        exit(0);
    }
    if(treeAdj[v].size() == 1 && v != 0){
        int e1 = p, e2 = p;
        for(auto u : adj[v]){
            if(e1 != p && e2 != p) break;
            if(u == p) continue;
            if(e1 == p) e1 = u;
            else e2 = u;
        }
        if(getLen(e1, v) >=ceil((n+0.0)/k)) printPath(e1, v, -1);
        else if((getLen(e1, v)+1)%3 != 0){
            cycles.push_back(vector<int>());
            addCycle(v, e1);
        }
        else if(getLen(e2, v) >=ceil((n+0.0)/k)) printPath(e2, v, -1);
        else if((getLen(e2, v)+1)%3 != 0){
            cycles.push_back(vector<int>());
            addCycle(v, e2);
        }
        else if(getLen(e1, e2)+1 >=ceil((n+0.0)/k)) printPath(e1, e2, v);
        else if((getLen(e1, v)+2)%3 != 0){
            cycles.push_back(vector<int>(1, v));
            addCycle(e1, e2);
        }
    }
    for(auto u : treeAdj[v]){
        if(u == p) continue;
        getAns(u, v, st);
    }
    st.pop();
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    getTreeAdj();
    preprocess();
    stack<int> st;
    getAns(0, 0, st);
}