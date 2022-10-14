#include <bits/stdc++.h>
using namespace std;
map<int,int>kl;
vector<int>elist[200005];
bool vis[200005];
pair<int,int>dfs(int u,int f){
    if(vis[u])return{0,1};
    vis[u]=1;
    int a=1,b=0;
    for(int v:elist[u])if(v!=f){
        auto [x,y]=dfs(v,u);
        a+=x;b=b||y;
    }
    return {a,b};
}
int mod=1000000007;
#define rep(i,x) for(int i=0;i<(x);i++)
int main(){
    int n;cin>>n;
    rep(i,n){
        int x,y;cin>>x>>y;
        x+=1000000009;y+=1000000009;y=-y;
        if(!kl.count(x))kl[x]=i*2;
        if(!kl.count(y))kl[y]=i*2+1;
        elist[kl[x]].push_back(kl[y]);
        elist[kl[y]].push_back(kl[x]);
    }
    int r=1;
    rep(i,2*n){
        if(vis[i])continue;
        auto[a,b]=dfs(i,-1);
        int d=1;while(a--)d=2ll*d%mod;
        if(b)r=1ll*r*d%mod;
        else r=1ll*r*(d-1)%mod;
    }
    cout<<r<<endl;
}