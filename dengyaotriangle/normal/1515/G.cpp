#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n,m;
vector<pair<int,int> > adj[maxn];
int dfn[maxn],low[maxn],c1;
bool ins[maxn];
long long pfx[maxn],val[maxn];
stack<int> stk;
bool ins0[maxn];
int dfi[maxn],c2;
long long dfv[maxn];

void tarjan(int u){
    dfn[u]=low[u]=++c1;
    ins[u]=1;
    ins0[u]=1;
    stk.push(u);
    for(int i=0;i<(int)adj[u].size();i++){
        int v=adj[u][i].first,w=adj[u][i].second;
        if(!dfn[v]){
            pfx[v]=pfx[u]+w;
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(ins[v]){
            low[u]=min(low[u],dfn[v]);
            if(ins0[v])val[u]=__gcd(val[u],w+pfx[u]-pfx[v]);
            else{
                val[u]=__gcd(val[u],abs(w+pfx[u]-pfx[v]));
            }
        }
    }
    if(low[u]==dfn[u]){
        ++c2;
        while(1){
            int v=stk.top();stk.pop();
            dfi[v]=c2;
            ins[v]=0;
            dfv[c2]=__gcd(dfv[c2],val[v]);
            if(v==u)break;
        }
    }
    ins0[u]=0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    int q;
    cin>>q;
    while(q--){
        int v,s,t;
        cin>>v>>s>>t;
        long long h=dfv[dfi[v]];
        if(__gcd(s,t)%__gcd(h,(long long)t)==0){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }
    return 0;
}