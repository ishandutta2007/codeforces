#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n,m;
vector<int> g[100005];
int sz[100005];
vector<ll> e,p;

void dfs(const int &x,const int &p){
    sz[x]=1;
    for(int &y:g[x])if(y!=p){
        dfs(y,x);
        sz[x]+=sz[y];
    }
    if(x!=1){
        e.emplace_back((ll)sz[x]*(n-sz[x]));
    }
}

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        static int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    e.clear();
    dfs(1,-1);
    sort(e.begin(),e.end());
    reverse(e.begin(),e.end());
    for(ll &x:e)x%=mod;
    cin>>m;
    p.resize(m);
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    sort(p.begin(),p.end());
    if(m>n-1){
        for(int i=m-2;i>=n-2;i--){
            p[i]=p[i]*p[i+1]%mod;
        }
        p.resize(n-1);
    }
    reverse(p.begin(),p.end());
    while(p.size()<n-1)p.emplace_back(1);
    ll ans=0;
    for(int i=0;i+1<n;i++){
        ans=(ans+e[i]*p[i])%mod;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}