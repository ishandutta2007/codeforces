
// Created by calabash_boy on 18-10-10.
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int first[maxn],nxt[maxn*2],from[maxn*2],des[maxn*2],isBrige[maxn*2],tot;
int dfn[maxn],low[maxn],dfs_clock;
int cnt_e[maxn],cnt_n[maxn];int bcc_cnt;
bool ok[maxn];vector <int> ans;int m,n;
int d[maxn];
inline void addEdge(int x,int y){
    tot++;
    des[tot] =y;from[tot] =x;
    nxt[tot] = first[x];first[x] = tot;
}
void input(){
    cin>>n>>m;
    if(n == 2){
        cout<<-1<<endl;
        exit(0);
    }
    for (int i=0;i<m;i++){
        int u,v;scanf("%d%d",&u,&v);
        addEdge(u,v);addEdge(v,u);
    }
}
void dfs(int u,int fa){
    dfn[u] = low[u] = ++dfs_clock;
    for (int t = first[u];t;t=nxt[t]){
        int v = des[t];if (v==fa)continue;
        if (!dfn[v]){
            dfs(v,u);
            low[u] = min(low[v],low[u]);
            if (dfn[u]<low[v]){
                isBrige[t] = true;
                if (t&1){isBrige[t+1] = true;}
                else{isBrige[t-1] = true;}
            }
        }else if (dfn[v]<dfn[u]){low[u] = min(low[u],dfn[v]);}
    }
}
int bcc_v[maxn];
void blood_fill(int x){
    bcc_v[bcc_cnt] = x;
    dfn[x] = bcc_cnt;
    for (int t = first[x];t;t=nxt[t]){
        if (isBrige[t])continue;
        int v = des[t];
        if (!dfn[v]){blood_fill(v);}
    }
}
vector<int> E[maxn];
vector<int> leaf;
void build_st(int u,int fa){
    if (E[u].size() == 1){
        leaf.push_back(bcc_v[u]);
    }
    for (int v : E[u]){
        if (v == fa)continue;
        build_st(v,u);
    }
}
void solve(){
    for (int i=1;i<=n;i++){if (!dfn[i])dfs(i,-1);}
    memset(dfn,0,sizeof dfn);
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            bcc_cnt++;
            blood_fill(i);
        }
    }
    if (bcc_cnt == 2){
        cout<<1<<endl;
        cout<<bcc_v[1]<<" "<<bcc_v[2]<<endl;
        return;
    }else{
        if (bcc_cnt == 1){
            cout<<0<<endl;
            return;
        }
    }
    int root = -1;
    for (int i=1;i<=n;i++){
        for (int t = first[i];t;t=nxt[t]){
            if (!isBrige[t])continue;
           // cerr<<i<<","<<des[t]<<" | "<<dfn[i]<<","<<dfn[des[t]]<<endl;
            int u = dfn[i];
            int v = dfn[des[t]];
            E[u].push_back(v);
          //  cerr<<u<<","<<v<<endl;
        }
    }
    for (int i = 1;i<=bcc_cnt;i++){
        if (E[i].size() > 1){
            root = i;
        }
    }
    assert(root != -1);
   
    build_st(root, 0);
     assert(leaf.size() > 0);
    if (leaf.size() & 1)leaf.push_back(leaf.front());
    cout<<leaf.size() /2 << endl;
    for (int i=0;i< leaf.size() / 2; i ++){
        cout<<leaf[i] <<" "<<leaf[i + leaf.size() / 2]<<endl;
    }
}
int main(){
    input();
    solve();
    return 0;
}