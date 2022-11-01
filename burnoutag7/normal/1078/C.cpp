#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,f[300005][3];
vector<int> g[300005];

void dfs(int x,int p){
    f[x][0]=1;
    ll prod=1;
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        prod=prod*(f[y][0]+f[y][2])%mod;
        f[x][0]=(ll)f[x][0]*f[y][0]%mod;
    }
    f[x][1]=prod;
    for(int y:g[x])if(y!=p){
        f[x][2]=(f[x][2]+f[y][1]*prod%mod*qpow(f[y][0]+f[y][2],mod-2))%mod;
    }
    f[x][0]=(f[x][0]+f[x][2])%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,-1);
    cout<<f[1][0];

    return 0;
}