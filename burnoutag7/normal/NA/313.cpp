#include<bits/stdc++.h>
using namespace std;

int n,far[300005];
vector<int> g[300005];

int dfs(int x,int p,int d){
    int mx=d,smx=-1e9;
    for(int y:g[x])if(y!=p){
        int son=dfs(y,x,d+1);
        if(mx<son){
            smx=mx;
            mx=son;
        }else smx=max(smx,son);
    }
    if(smx>0)far[smx-1]=max(far[smx-1],mx+smx-2*d);
    return mx;
}

void mian(){
    for(int i=1;i<=n;i++)g[i].clear();
    fill(far,far+n,0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int dep=dfs(1,-1,0);
    for(int i=n-2;i>=0;i--)far[i]=max(far[i],far[i+1]);
    for(int x=1;x<=n;x++){
        int l=1,r=dep,m,res=dep;
        while(l<=r){
            m=l+r>>1;
            if((far[m]+1)/2+x<=m){
                r=m-1;
                res=m;
            }else{
                l=m+1;
            }
        }
        cout<<res<<' ';
    }
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