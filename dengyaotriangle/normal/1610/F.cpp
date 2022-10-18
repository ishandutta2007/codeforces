#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005*4;

int n,m;
int deg[2][maxn];
int ans[maxn];
vector<int> edj[2][maxn];
inline void chg(tuple<int,int,int>&u,int x,int t){
    if(get<0>(u)==x)get<0>(u)=t;
    else get<1>(u)=t;
}
vector<pair<int,int> > adj[maxn];
bool vis[maxn];
inline void dir(int x){
    if(x>0)ans[x]=1,vis[x]=1;
    else ans[-x]=2,vis[-x]=1;
}
void dfs(int u){
    while(!adj[u].empty()){
        int v,w;tie(v,w)=adj[u].back();adj[u].pop_back();
        if(vis[abs(w)])continue;
        dir(w);
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    vector<tuple<int,int,int> > edg[2];
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        deg[w-1][u]++;deg[w-1][v]++;
        edj[w-1][u].push_back(edg[w-1].size());
        edj[w-1][v].push_back(edg[w-1].size());
        edg[w-1].push_back({u,v,i});
    }
    int t=n;
    int tta=0;
    for(int i=1;i<=n;i++){
        if(deg[0][i]&1){
            tta++;
            if(deg[1][i]&1){
                bool c=0;
                int u=++t;
                chg(edg[1][edj[1][i].back()],i,u);
                for(int&x:edj[0][i]){
                    chg(edg[0][x],i,t);
                    if(!c)u=++t;
                    c=1;
                }
            }else{
                bool c=0;
                ++t;
                for(int&x:edj[0][i]){
                    chg(edg[0][x],i,t);
                    if(!c)++t;
                    c=1;
                }
            }
        }
    }
    for(int t=0;t<2;t++){
        for(auto&x:edg[t]){
            int u,v,id;tie(u,v,id)=x;
            adj[u].push_back({v,id});
            adj[v].push_back({u,-id});
        }
    }
    int pt=0;
    int lm=m;
    for(int i=1;i<=t;i++){
        if(adj[i].size()&1){
            if(pt){
                ++m;
                adj[i].push_back({pt,m});
                adj[pt].push_back({i,-m});
                pt=0;
            }else pt=i;
        }
    }
    for(int i=1;i<=t;i++)while(!adj[i].empty())dfs(i);
    cout<<tta<<'\n';
    for(int i=1;i<=lm;i++)cout<<ans[i];
    return 0;
}