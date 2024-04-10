#include<bits/stdc++.h>
using namespace std;

int n,k,d[200005][45],u[200005][45];
vector<int> g[200005];

void dfs(int x,int p){
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        for(int i=0;i<k<<1;i++){
            d[x][i+1]^=d[y][i];
        }
    }
    d[x][0]^=d[x][k<<1];
}

void chr(int x,int p){
    for(int y:g[x])if(y!=p){
        for(int i=0;i<k<<1;i++){
            u[y][i+1]^=u[x][i]^d[x][i]^d[y][i?i-1:k*2-1];
        }
        u[y][0]=u[y][k<<1];
        chr(y,x);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>d[i][0];
    }
    dfs(1,-1);
    chr(1,-1);
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=k;j<k<<1;j++){
            ans^=d[i][j]^u[i][j];
        }
        cout<<(bool)ans<<' ';
    }

    return 0;
}