#include<bits/stdc++.h>
using namespace std;

int n,k,sz[105],ht[105],fa[105];
vector<int> g[105],ans;
bool vis[105];

void prec(int x){
    sz[x]=1;
    ht[x]=1;
    for(int y:g[x]){
        prec(y);
        fa[y]=x;
        ht[x]=max(ht[x],ht[y]+1);
        sz[x]+=sz[y];
    }
}

void dfs(int x,int k){
    if(k<=0)return;
    vis[x]=1;
    ans.emplace_back(x);
    k--;
    if(k==0)return;
    int mxh=0,mxhs=-1;
    for(int y:g[x])if(mxh<ht[y]){
        mxh=ht[y];
        mxhs=y;
    }
    for(int y:g[x])if(y!=mxhs){
        dfs(y,k-mxh);
        k-=max(0,min(k-mxh,sz[y]));
        ans.emplace_back(x);
    }
    if(mxhs!=-1)dfs(mxhs,k);
    ans.emplace_back(x);
}

void mian(){
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    ans.clear();
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        g[fa[i]].emplace_back(i);
    }
    prec(1);
    dfs(1,k);
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    while(ans.size()>1&&fa[ans[ans.size()-2]]==ans.back())ans.pop_back();
    cout<<ans.size()-1<<'\n';
    for(int x:ans)cout<<x<<' ';
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}