#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
vc<pair<ll,pair<ll,ll> > > v[300005];
set<pair<ll,pair<ll,ll> > > s;
set<ll> g;
ll vis[300005],m,k;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin>>n>>m>>k;
    if(k>=n)k=n-1;
    for(ll i=1;i<=m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        v[x].pb({y,{w,i}});
        v[y].pb({x,{w,i}});
    }
    s.insert({0,{1,1}});
    set<pair<ll,pair<ll,ll> > >::iterator z;
    while((!s.empty())&&(g.size()<k)){
        z=s.begin();
        ll a=(*z).sc.fr;
        if(vis[a]){
            s.erase(z);
            continue;
        }
        vis[a]=1;
        if(a!=1){
            g.insert((*z).sc.sc);
        }
        for(ll i=0;i<v[a].size();i++){
            if(vis[v[a][i].fr])continue;
            s.insert({v[a][i].sc.fr+(*z).fr,{v[a][i].fr,v[a][i].sc.sc}});
        }
        s.erase(z);
    }
    cout<<k<<"\n";
    for(set<ll>::iterator z=g.begin();z!=g.end();z++){
        cout<<(*z)<<" ";
    }
}