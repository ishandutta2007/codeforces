//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct LinearBasis{
    int n;
    vector<ll> v;
    LinearBasis(const int &_n){
        n=_n;
        v.resize(n);
    }
    void add(ll a){
        for(int i=n-1;i>=0;i--)if(a>>i&1){
            if(v[i])a^=v[i];
            else{
                for(int j=i-1;j>=0;j--)if(a>>j&1)a^=v[j];
                for(int j=i+1;j<n;j++)if(v[j]>>i&1)v[j]^=a;
                v[i]=a;
                return;
            }
        }
    }
    ll min(ll res=0){
        for(int i=n-1;i>=0;i--)if((res^v[i])<res)res^=v[i];
        return res;
    }
};

int n,m;
LinearBasis a(60);
vector<pair<int,ll>> g[100005];
ll w[100005];
bool vis[100005];

void dfs(int x){
    vis[x]=1;
    for(pair<int,ll> &e:g[x])if(!vis[e.first]){
        w[e.first]=w[x]^e.second;
        dfs(e.first);
    }else a.add(w[e.first]^w[x]^e.second);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        ll e;
        cin>>u>>v>>e;
        g[u].emplace_back(v,e);
        g[v].emplace_back(u,e);
    }
    dfs(1);
    cout<<a.min(w[n])<<endl;

    return 0;
}