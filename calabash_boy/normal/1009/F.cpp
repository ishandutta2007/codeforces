
//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> PLL;
const int MOD = -1;
const int maxn = 1e6+100;
map<int,int> Cnt[maxn];
pii Ans[maxn];
int n,cnt;
int dep[maxn];
int first[maxn],des[maxn*2],nxt[maxn*2],tot;
int root[maxn];
int sz[maxn];
int wson[maxn];
inline void addEdge(int x,int y){
    tot++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
}
int ans[maxn];
void Union(int T,int T2){
    for (pii x :Cnt[T2]){
        Cnt[T][x.first]+=x.second;
        int temp = Cnt[T][x.first];
        if (temp>Ans[T].second){
            Ans[T] = {x.first,temp};
        }else if (temp==Ans[T].second&&x.first<Ans[T].first){
            Ans[T] = {x.first,temp};
        }
    }
}
int query(int T){
    return Ans[T].first;
}
void dfs(int node,int fa){
    sz[node]=1;
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v==fa)continue;
        dep[v] = dep[node]+1;
        dfs(v,node);
        sz[node]+=sz[v];
        if (sz[v]>sz[wson[node]]){
            wson[node] = v;
        }
    }
    root[node] = root[wson[node]];
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v==fa||v==wson[node])continue;
        Union(root[node],root[v]);
    }
    if (!root[node]){
        root[node] = ++cnt;
        Ans[root[node]] = {dep[node],1};
    }
    Cnt[root[node]][dep[node]]++;
    int temp = Cnt[root[node]][dep[node]];
    if (temp>Ans[root[node]].second){
        Ans[root[node]] = {dep[node],temp};
    }else if (temp==Ans[root[node]].second&&dep[node]<Ans[root[node]].first){
        Ans[root[node]] ={dep[node],temp};
    }
    ans[node] = Ans[root[node]].first;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dep[1]=1;
    dfs(1,0);
    for (int i=1;i<=n;i++){
        printf("%d\n",ans[i]-dep[i]);
    }
    return 0;
}