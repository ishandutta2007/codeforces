#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[200005],bud;
bool rm[200005];

void dfs(int x,int p){
    int cnt=0;
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        cnt+=!rm[y];
    }
    rm[x]=cnt;
    if(cnt)bud.emplace_back(cnt);
}

void mian(){
    for(int i=1;i<=n;i++)g[i].clear();
    memset(rm+1,0,n);
    bud.clear();
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,-1);
    int ans=0;
    for(int x:bud)ans+=x;
    ans-=bud.size()-1;
    cout<<ans<<'\n';
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