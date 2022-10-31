#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int maxn = 3e5+100;
typedef long long ll;
vector<int> E[maxn];
ll ans[maxn];
int dep[maxn];
int l[maxn],r[maxn],dfn;
vector<int> Nodes[maxn];
vector<ll> Sum[maxn];
ll delta[maxn];
void dfs(int u,int fa){
    l[u] = ++dfn;
    dep[u] = dep[fa]+1;
    Nodes[dep[u]].push_back(u);
    Sum[dep[u]].push_back(0);
    for (int v :E[u]){
        if (v == fa)continue;
        dfs(v,u);
    }
    r[u] = dfn;
}
void dfs2(int u,int fa){
    ans[u] = ans[fa] + delta[u];
    for (int v :E[u]){
        if (v == fa)continue;
        dfs2(v,u);
    }
}

int n,m;
bool cmp(int x,int y){
    return l[x] < l[y];
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1,0);
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        int v,d,x;
        scanf("%d%d%d",&v,&d,&x);
        delta[v] += x;
        int depth = dep[v] + d+1;
        if (depth > n || Nodes[depth].empty())continue;
        l[0] = r[v];
        int R = lower_bound(all(Nodes[depth]),0,cmp) - Nodes[depth].begin();
        if (R<Nodes[depth].size() && r[v] == l[Nodes[depth][R]])R++;
        l[0] = l[v];
        int L = lower_bound(all(Nodes[depth]),0,cmp) - Nodes[depth].begin();
        if (R!=L){
            if (L<Nodes[depth].size()){
                Sum[depth][L] -= x;
            }
            if (R<Nodes[depth].size()){
                Sum[depth][R]+=x;
            }
        }
       // cerr<<"depth= "<<depth<<" L= "<<L<<" R= "<<R<<endl;
    }

    for (int i=1;i<=n;i++){
        if (Sum[i].empty())continue;
        delta[Nodes[i][0]] += Sum[i][0];
        for (int j=1;j<Sum[i].size();j++){
            Sum[i][j] += Sum[i][j-1];
            delta[Nodes[i][j]]+= Sum[i][j];
        }
    }
    dfs2(1,0);
    for (int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}