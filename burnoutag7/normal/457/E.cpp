#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,ic[200005],cc;
ll dep[200005],mxd,mnd;
pair<pair<int,int>,int> edge[200005];
vector<pair<int,int>> g[200005];
bool vis[200005],valid;

void dfs(int x,ll d){
    dep[x]=d;
    vis[x]=1;
    ic[x]=cc;
    mnd=min(mnd,d);
    mxd=max(mxd,d);
    for(auto &[y,z]:g[x])if(!vis[y]){
        dfs(y,d+z);
    }else{
        valid&=dep[y]==dep[x]+z;
    }
}

bool check(int m){
    for(int i=1;i<=n;i++)g[i].clear();
    memset(vis+1,0,n);
    valid=1;
    cc=0;
    for(int i=1;i<=m;i++){
        auto &[p,w]=edge[i];
        auto &[u,v]=p;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,-w);
    }
    cc++;
    mxd=mnd=0;
    dfs(1,0);
    if(!valid)return 0;
    ll thr=vis[n]?dep[n]:LLONG_MAX;
    for(int i=2;i<=n;i++)if(!vis[i]){
        cc++;
        mnd=mxd=0;
        dfs(i,0);
        if(!valid||(ll)mxd-mnd>=thr)return 0;
    }
    for(int i=1;i<=n;i++){
        if(i!=1&&ic[i]==ic[1]&&dep[i]<=dep[1])return 0;
        if(i!=n&&ic[i]==ic[n]&&dep[i]>=dep[n])return 0;
    }
    return 1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w,b;
        cin>>u>>v>>w>>b;
        edge[i]={{u,v},w*b};
    }
    if(check(m)){
        if(ic[1]==ic[n]){
            cout<<dep[n]<<'\n';
        }else{
            cout<<"UNKNOWN\n";
        }
        return 0;
    }
    int l=1,r=m,mid,ans;
    while(l<=r){
        mid=l+r>>1;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
            ans=mid;
        }
    }
    cout<<"BAD "<<ans<<'\n';

    return 0;
}