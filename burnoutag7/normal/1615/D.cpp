#include<bits/stdc++.h>
using namespace std;

int n,m,sum[200005],cc,ic[200005],col[200005];
vector<pair<int,int>> g[200005],ng[200005];

void gsum(int x,int p){
    for(auto &[y,z]:g[x])if(y!=p){
        sum[y]=z==-1?sum[x]:sum[x]^z;
        if(z!=-1){
            ng[x].emplace_back(y,z&1);
            ng[y].emplace_back(x,z&1);
        }
        gsum(y,x);
    }
}

bool color(int x,int c){
    ic[x]=cc;
    col[x]=c;
    for(auto &[y,z]:ng[x])if(!ic[y]){
        if(!color(y,c^z))return false;
    }else if(col[y]!=(c^z)){
        return false;
    }
    return true;
}

void gans(int x,int p){
    for(auto &[y,z]:g[x])if(y!=p){
        if(z==-1)z=col[x]^col[y];
        cout<<x<<' '<<y<<' '<<z<<'\n';
        gans(y,x);
    }
}

void mian(){
    for(int i=1;i<=n;i++){
        g[i].clear();
        ng[i].clear();
    }
    fill(ic+1,ic+1+n,0);
    cc=0;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    gsum(1,-1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        w=__builtin_parity((sum[u]^sum[v])>>1)!=w;
        ng[u].emplace_back(v,w);
        ng[v].emplace_back(u,w);
    }
    for(int i=1;i<=n;i++)if(!ic[i]){
        cc++;
        if(!color(i,0)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    gans(1,-1);
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