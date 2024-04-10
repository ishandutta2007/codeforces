#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<pair<int,ll>> adj[MN];
int st[MN],lst[MN],partof[MN],et,compind;
vector<int> nodes;
bool inst[MN];
ll gc[MN];
ll dist[MN];
void dfs(int loc, ll depth){
    dist[loc]=depth;
    st[loc]=lst[loc]=et++;
    inst[loc]=true,nodes.push_back(loc);
    for(auto x:adj[loc]){
        if(!st[x.first])dfs(x.first,depth+x.second),lst[loc]=min(lst[loc],lst[x.first]);
        else if(inst[x.first])lst[loc]=min(lst[loc],st[x.first]);
    }
    if(lst[loc]==st[loc]){
        compind++;
        while(1){
            auto cur=nodes.back();
            nodes.pop_back();
            partof[cur]=compind;
            inst[cur]=false;
            if(cur==loc)break;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    ll c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    et=1;
    for(int i=1;i<=n;i++){
        if(!st[i])dfs(i,0);
    }
    for(int i=1;i<=n;i++){
        for(auto x:adj[i]){
            if(partof[x.first]==partof[i]){
                gc[partof[i]]=__gcd(gc[partof[i]],dist[i]-dist[x.first]+x.second);
            }
        }
    }
    int q;
    cin>>q;
    ll s,t;
    while(q--){
        cin>>a>>s>>t;
        if(s%__gcd(gc[partof[a]],t)==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}