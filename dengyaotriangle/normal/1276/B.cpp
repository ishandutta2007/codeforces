#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n,m,a,b;
vector<int> adj[maxn];

int tfa[maxn],dfn[maxn],low[maxn],c1,c2;
vector<int> tdj[maxn<<1];
stack<int> stk;
int tsz[maxn<<1];

void tarjan(int u){
    dfn[u]=low[u]=++c1;
    stk.push(u);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!dfn[v]){
            tfa[v]=u;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                ++c2;
                while(1){
                    int w=stk.top();stk.pop();
                    tdj[c2].push_back(w);
                    tdj[w].push_back(c2);
                    if(w==v)break;
                }
                tdj[c2].push_back(u);
                tdj[u].push_back(c2);
            }
        }else if(v!=tfa[u]) low[u]=min(low[u],dfn[v]);
    }
}

void dfs(int u,int f){
    tsz[u]=u<=n;
    for(int i=0;i<tdj[u].size();i++){
        int v=tdj[u][i];
        if(v!=f){
            dfs(v,u);
            tsz[u]+=tsz[v];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>a>>b;
        c1=0;c2=n;
        while(!stk.empty())stk.pop();
        for(int i=1;i<=n;i++){adj[i].clear();dfn[i]=0;tfa[i]=0;}
        for(int i=1;i<=n+n;i++){tdj[i].clear();}
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tarjan(1);
        for(int i=1;i<=c2;i++){tsz[i]=0;}
        dfs(a,0);
        long long p1=tsz[b]-1;
        for(int i=1;i<=c2;i++){tsz[i]=0;}
        dfs(b,0);
        long long p2=tsz[a]-1;
        //cerr<<p1<<','<<p2<<endl;
        cout<<p1*p2<<'\n';
        
    }    
    return 0;
}