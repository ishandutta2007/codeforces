#include<bits/stdc++.h>
using namespace std;

int n,sz[100005],ban[100005];
vector<int> g[100005];
char ans[100005];

void get_centroid(const int& x,const int& p,int& res,const int& tot){
    sz[x]=1;
    int mx=0;
    for(const int& y:g[x])if(y!=p&&!ban[y]){
        get_centroid(y,x,res,tot);
        sz[x]+=sz[y];
        mx=max(mx,sz[y]);
    }
    if(max(mx,tot-sz[x])<=tot>>1)res=x;
}

void solve(const int& x,const int& tot,const char& lvl){
    ban[x]=1;
    ans[x]=lvl;
    static int junk;
    get_centroid(x,-1,junk,tot);
    for(const int& y:g[x])if(!ban[y]){
        int centroid=114514,ctot=sz[y];
        get_centroid(y,x,centroid,ctot);
        solve(centroid,ctot,lvl+1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        static int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int centroid=114514;
    get_centroid(1,-1,centroid,n);
    solve(centroid,n,'A');
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';

    return 0;
}