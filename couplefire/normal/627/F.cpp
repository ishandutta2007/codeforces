#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, st, en, arr[N], brr[N], fa[N], dep[N], uu, vv;
vector<int> adj[N], cyc1, cyc2;
vector<array<int, 2>> edges;

void dfs(int v, int p){
    fa[v] = p;
    for(auto u : adj[v])
        if(u!=p) dep[u] = dep[v]+1, dfs(u, v);
}

int dist(int u, int v){
    int len = 0;
    while(u!=v){
        if(dep[u]<dep[v]) swap(u, v);
        u = fa[u]; len++;
    }
    return len;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i<=n; ++i){
        cin >> arr[i];
        if(arr[i]==0) st = i;
    }
    for(int i = 1; i<=n; ++i){
        cin >> brr[i];
        if(brr[i]==0) en = i;
    }
    for(int i = 1; i<n; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    dfs(en, 0);
    {
        int cur = st;
        while(cur!=en){
            swap(arr[cur], arr[fa[cur]]);
            cur = fa[cur];
        }
    }
    {
        vector<int> bruh, deg(n+1);
        set<int> se;
        int cnte = 0, cnt1 = 0, cnt2 = 0, cnt0 = 0;
        for(int i = 1; i<=n; ++i)
            if(arr[i]!=brr[i]) bruh.push_back(i), se.insert(i);
        if(!bruh.size()){
            cout << 0 << ' ' << dep[st] << '\n';
            exit(0);
        }
        int top = bruh[0];
        for(auto x : bruh)
            if(dep[x]<dep[top]) top = x;
        bruh.push_back(fa[top]);
        se.insert(fa[top]);
        for(auto [u, v] : edges)
            if(se.count(u) && se.count(v))
                cnte++, deg[u]++, deg[v]++;
        if(cnte!=(int)bruh.size()-1){
            cout << -1 << '\n';
            exit(0);
        }
        for(int i = 1; i<=n; ++i) if(se.count(i)){
            if(deg[i]==1) cnt1++;
            else if(deg[i]==2) cnt2++;
            else cnt0++;
        }
        if(cnt0 != 0 || cnt1!=2 || cnt2!=(int)bruh.size()-2){
            cout << -1 << '\n';
            exit(0);
        }
        for(int i = 1; i<=n; ++i)
            if(deg[i]==1){
                if(!uu) uu = i;
                else vv = i;
            }
        if(uu>vv) swap(uu, vv);
        vector<int> path1, path2, path;
        int tmpu = uu, tmpv = vv;
        while(tmpu!=fa[top])
            path1.push_back(tmpu), tmpu = fa[tmpu];
        while(tmpv!=fa[top])
            path2.push_back(tmpv), tmpv = fa[tmpv];
        reverse(path2.begin(), path2.end());
        path = path1;
        for(auto x : path2) path.push_back(x);
        for(auto x : path) cyc1.push_back(arr[x]), cyc2.push_back(brr[x]);
    }
    int pos = -1;
    for(int i = 0; i<(int)cyc2.size(); ++i)
        if(cyc2[i]==cyc1[0]){pos = i; break;}
    if(!pos){
        cout << -1 << '\n';
        exit(0);
    }
    rotate(cyc2.begin(), cyc2.begin()+pos, cyc2.end());
    if(cyc1!=cyc2){
        cout << -1 << '\n';
        exit(0);
    }
    cout << uu << ' ' << vv << ' ' << 1ll+min(1ll*(pos-1)*((int)cyc1.size()+1)+dist(st, uu)+dist(vv, en), 1ll*((int)cyc1.size()-pos-1)*((int)cyc1.size()+1)+dist(st, vv)+dist(uu, en)) << '\n';
}