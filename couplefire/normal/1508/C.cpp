#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define INF 1000000000000000009ll
#define int long long

struct DSU{
    int parent[MAXN];
    int siz[MAXN];
    DSU(){}
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]); 
    }
    void make_set(int v) {
        parent[v] = v;
        siz[v] = 1;
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (siz[a] < siz[b])
                swap(a, b);
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
} dsu;

int n, m;
vector<int> adj[MAXN];
vector<array<int, 3>> edges;
map<int, int> mp[MAXN];
int cnte = 0;
int label = 0;
int comps[MAXN];
set<int> good;
int ans = 0;
int bigxor = 0;
set<array<int, 3>> st;

void dfs(int v){
    cnte++;
    comps[v] = label;
    good.erase(v);
    int u = -1;
    auto it = good.upper_bound(u);
    while(it != good.end()){
        u = *it;
        if(!mp[u].count(v) && !mp[v].count(u)) dfs(u);
        it = good.upper_bound(u);
    }
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b; --a; --b;
        int c; cin >> c;
        edges.push_back({c, a, b});
        mp[a][b] = 1, mp[b][a] = 1;
        bigxor ^= c;
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i<n; i++) dsu.make_set(i);
    for(auto e : edges){
        if(dsu.find_set(e[1]) != dsu.find_set(e[2])) dsu.union_sets(e[1], e[2]), st.insert(e);
    }
    for(int i = 0; i<n; i++) good.insert(i);
    for(int i = 0; i<n; i++){
        if(good.count(i)) dfs(i), label++, cnte--;
    }
    for(int i = 0; i<label; i++) dsu.make_set(i);
    for(auto e : edges){
        if(dsu.find_set(comps[e[1]]) != dsu.find_set(comps[e[2]])){
            ans += e[0];
            dsu.union_sets(comps[e[1]], comps[e[2]]);
            st.erase(e);
        }
    }
    if(n*(n-1)/2-m-cnte){
        cout << ans << endl;
        exit(0);
    }
    if(!st.empty()) bigxor = min(bigxor, (*st.begin())[0]);
    ans += bigxor;
    cout << ans << endl;
}