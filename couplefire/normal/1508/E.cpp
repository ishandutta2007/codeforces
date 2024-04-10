#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n;
vector<int> adj[N];
int arr[N], psum[N], depth[N], tin[N], tout[N], par[N], timer;
int bit[N];
vector<array<int, 2>> badpos;
int order[N];
long long ans = 0;

int sum(int r){
    int res = 0;
    for(; r>=0; r = (r&(r+1))-1) res += bit[r];
    return res;
}

int sum(int l, int r){
    return sum(r)-sum(l-1);
}

void add(int idx, int delta){
    for(; idx < N; idx = idx|(idx+1)) bit[idx] += delta;
}

void dfs1(int v, int p, int d){
    depth[v] = d;
    tin[v] = ++timer;
    par[v] = p;
    for(auto u : adj[v]){
        if(u == p) continue;
        if(arr[u] < arr[v]) badpos.push_back({arr[u], u});
        dfs1(u, v, d+1);
    }
    tout[v] = timer;
}

void dfs2(int v, int p){
    order[v] = ++timer;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs2(u, v);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, -1, 0);
    sort(badpos.begin(), badpos.end());
    if(badpos.back()[0] != (int)badpos.size()){
        cout << "NO" << endl;
        exit(0);
    }
    for(int i = (int)badpos.size()-1; i>=0; i--){
        int v = badpos[i][1];
        ans += depth[v];
        int pval = arr[par[v]]-sum(tin[par[v]], tout[par[v]]);
        int curval = arr[v]-sum(tin[v], tout[v]);
        add(tin[v], 1);
        arr[v] = pval+sum(tin[v], tout[v]);
        arr[0] = curval+sum(tin[0], tout[0]);
    }
    for(int i = 0; i<n; i++) arr[i] = arr[i]-sum(tin[i], tout[i]);
    for(int i = 0; i<n; i++){
        sort(adj[i].begin(), adj[i].end(), [&](const int a, const int b){
            return arr[a] < arr[b];
        });
    }
    timer = 0;
    dfs2(0, -1);
    for(int i = 0; i<n; i++){
        if(order[i] != arr[i]){
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
    cout << ans << endl;
    for(int i = 0; i<n; i++) cout << order[i] << " ";
    cout << endl;
}