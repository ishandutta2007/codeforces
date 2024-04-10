#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 300005;

int n, q;
vector<array<int, 3>> adj[N];
int dep[N][2], arr[N], tmp[N], up[N][2][2][20], anc[N][20], tin[N], tout[N], timer;
multiset<int> mst;

void dfs1(int v, int p){
    tmp[v] = arr[v];
    for(auto u : adj[v]){
        if(u[0] == p) continue;
        dep[u[0]][0] = dep[v][0]+u[1];
        dep[u[0]][1] = dep[v][1]+u[2];
        dfs1(u[0], v);
        tmp[v] = min(tmp[v], tmp[u[0]]+u[1]+u[2]);
    }
}

void dfs2(int v, int p){
    mst.insert(tmp[v]-dep[v][0]-dep[v][1]);
    int prv = tmp[v];
    tmp[v] = min(tmp[v], (*mst.begin())+dep[v][0]+dep[v][1]);
    for(auto u : adj[v]){
        if(u[0] == p) continue;
        dfs2(u[0], v);
    }
    mst.erase(mst.find(prv-dep[v][0]-dep[v][1]));
}

void dfs3(int v, int p){
    tin[v] = ++timer;
    anc[v][0] = p;
    for(int t = 1; t<20; t++) anc[v][t] = anc[anc[v][t-1]][t-1];
    up[v][0][0][0] = dep[v][0]-dep[p][0];
    up[v][1][1][0] = dep[v][1]-dep[p][1];
    up[v][0][1][0] = min(arr[v]+dep[v][1]-dep[p][1], arr[p]+dep[v][0]-dep[p][0]);
    up[v][1][0][0] = min(arr[p]+dep[v][1]-dep[p][1], arr[v]+dep[v][0]-dep[p][0]);
    for(int t = 1; t<20; t++)
        for(int i = 0; i<2; i++)
            for(int j = 0; j<2; j++)
                up[v][i][j][t] = min(
                    up[v][i][0][t-1]+up[anc[v][t-1]][0][j][t-1],
                    up[v][i][1][t-1]+up[anc[v][t-1]][1][j][t-1]
                );
    for(auto u : adj[v]){
        if(u[0] == p) continue;
        dfs3(u[0], v);
    }
    tout[v] = timer;
}

bool isPar(int u, int v){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int getAns(int u, int a, int v, int b){
    int _u = u, _v = v;
    int u_val[2], v_val[2], u_tmp[2], v_tmp[2];

    u_val[a] = 0, u_val[1-a] = arr[u];
    for(int t = 19; t>=0; t--)
        if(!isPar(anc[u][t], _v)){
            swap(u_tmp, u_val);
            u_val[0] = min(u_tmp[0]+up[u][0][0][t], u_tmp[1]+up[u][1][0][t]);
            u_val[1] = min(u_tmp[0]+up[u][0][1][t], u_tmp[1]+up[u][1][1][t]);
            u = anc[u][t];
        }
    if(!isPar(u, _v)){
        swap(u_tmp, u_val);
        u_val[0] = min(u_tmp[0]+up[u][0][0][0], u_tmp[1]+up[u][1][0][0]);
        u_val[1] = min(u_tmp[0]+up[u][0][1][0], u_tmp[1]+up[u][1][1][0]);
        u = anc[u][0];
    }

    v_val[b] = 0, v_val[1-b] = arr[v];
    for(int t = 19; t>=0; t--)
        if(!isPar(anc[v][t], _u)){
            swap(v_tmp, v_val);
            v_val[0] = min(v_tmp[0]+up[v][0][0][t], v_tmp[1]+up[v][1][0][t]);
            v_val[1] = min(v_tmp[0]+up[v][0][1][t], v_tmp[1]+up[v][1][1][t]);
            v = anc[v][t];
        }
    if(!isPar(v, _u)){
        swap(v_tmp, v_val);
        v_val[0] = min(v_tmp[0]+up[v][0][0][0], v_tmp[1]+up[v][1][0][0]);
        v_val[1] = min(v_tmp[0]+up[v][0][1][0], v_tmp[1]+up[v][1][1][0]);
        v = anc[v][0];
    }
    return min(u_val[0]+v_val[0], u_val[1]+v_val[1]);
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n-1; i++){
        int a, b, w1, w2; 
        cin >> a >> b >> w1 >> w2; --a; --b;
        adj[a].push_back({b, w1, w2});
        adj[b].push_back({a, w1, w2});
    }
    dfs1(0, 0);
    dfs2(0, 0);
    swap(tmp, arr);
    dfs3(0, 0);
    cin >> q;
    while(q--){
        int _u, _v; cin >> _u >> _v;
        int u = (_u+1)/2-1, v = (_v+1)/2-1;
        int a = (_u+1)%2, b = (_v+1)%2;
        cout << getAns(u, a, v, b) << endl;
    }
}