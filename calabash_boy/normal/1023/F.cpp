#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
vector<pair<int,int> > E[maxn];
int fa[maxn];
int find(int x){
    return fa[x] == x?x : fa[x] = find(fa[x]);
}
int n,m,k;
int ans[maxn];
vector<tuple<int,int,int> > edges;
void kruskal(){
    for (int i=1;i<=n;i++)fa[i] = i;
    for (int i = 0;i < edges.size();i++){
        int u,v,w;
        tie(u,v,w) = edges[i];
        int fu = find(u);
        int fv = find(v);
        if (fu == fv)continue;
        fa[fu] = fv;
        int id = i < k?i+1:-1;
        E[u].push_back(make_pair(v,id));
        E[v].push_back(make_pair(u,id));
    }
}
int fa_e[maxn];
int fa_v[maxn];
int dep[maxn];
void dfs(int u){
    for (auto e : E[u]){
        int v,id;
        tie(v,id) = e;
        if (fa_e[v])continue;
        fa_e[v] = id;
        fa_v[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&m);
    for (int i=1;i<=n;i++)ans[i] = -1;
    for(int i=1;i<=k;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        edges.push_back(make_tuple(u,v,0));
    }
    for (int i = 1;i <= m;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges.push_back(make_tuple(u,v,w));
    }
    kruskal();
   // cerr<<"got mst"<<endl;
    fa_e[1] = -1;
    dfs(1);
    for (int i=1;i<=n;i++)fa[i] = i;
    for (int i=k;i<edges.size();i++){
        int u,v,w;
        tie(u,v,w) = edges[i];
        while (1){
          //  cerr<<i<<" "<<u<<" "<<v<<endl;
            u = find(u);
            v = find(v);
            if (u == v)break;
            if (dep[u] < dep[v])swap(u,v);
            ans[fa_e[u]] = w;
            fa[u] = fa_v[u];
        }
    }
    long long Ans = 0;
    for (int i=1;i<=k;i++){
        if (ans[i] == -1){
            cout<<-1<<endl;
            return 0;
        }
        Ans += ans[i];
    }
    cout<<Ans<<endl;
    return 0;
}