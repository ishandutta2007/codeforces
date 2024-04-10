#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

int n,m,q,ncc,vis[200005],icc[200005];
ll dis[200005],cyc[200005];
vector<pair<int,int>> g[200005],rg[200005];
vector<int> topo;

void dfs(int x){
    vis[x]=1;
    for(pair<int,int> &e:g[x])if(!vis[e.first]){
        dfs(e.first);
    }
    topo.emplace_back(x);
}

void rdfs(int x){
    vis[x]=2;
    for(pair<int,int> &e:rg[x])if(vis[e.first]==1){
        icc[e.first]=icc[x];
        dis[e.first]=dis[x]+e.second;
        rdfs(e.first);
    }else if(icc[e.first]==icc[x]){
        cyc[icc[x]]=gcd(cyc[icc[x]],abs(dis[x]+e.second-dis[e.first]));
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].emplace_back(v,w);
        rg[v].emplace_back(u,w);
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    reverse(topo.begin(),topo.end());
    for(int i:topo)if(vis[i]==1){
        icc[i]=++ncc;
        rdfs(i);
    }
    cin>>q;
    while(q--){
        int v,s,t;
        cin>>v>>s>>t;
        cout<<(s%gcd(cyc[icc[v]],t)==0?"YES\n":"NO\n");
    }

    return 0;
}