#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int,int>> g[100005];
vector<pair<int,int>> min3[100005];
multiset<ll> star3;
set<pair<int,pair<int,int>>> edge3;
map<pair<int,int>,int> weight;

template<bool add> void upd(int u,int v,int w){
    if(u>v)swap(u,v);
    if constexpr(!add){
        w=weight[make_pair(u,v)];
    }
    for(int _=0;_<2;_++,swap(u,v)){
        ll sum=0;
        for(auto [w,v]:min3[u]){
            if(find(min3[v].begin(),min3[v].end(),make_pair(w,u))!=min3[v].end()){
                edge3.erase(make_pair(w,v>u?make_pair(u,v):make_pair(v,u)));
            }
            sum+=w;
        }
        if(min3[u].size()==3){
            star3.erase(star3.find(sum));
        }
        min3[u].clear();
    }
    for(int _=0;_<2;_++,swap(u,v))if constexpr(add){
        g[u].emplace(w,v);
    }else{
        g[u].erase(make_pair(w,v));
    }
    for(int _=0;_<2;_++,swap(u,v)){
        ll sum=0;
        for(auto [w,v]:g[u]){
            sum+=w;
            min3[u].emplace_back(w,v);
            if(min3[u].size()==3)break;
        }
        if(min3[u].size()==3){
            star3.emplace(sum);
        }
    }
    if constexpr(add){
        weight[make_pair(u,v)]=w;
    }
    for(int _=0;_<2;_++,swap(u,v)){
        for(auto [w,v]:min3[u])if(find(min3[v].begin(),min3[v].end(),make_pair(w,u))!=min3[v].end()){
            edge3.emplace(w,v>u?make_pair(u,v):make_pair(v,u));
        }
    }
}

bool intersect(pair<int,int> e1,pair<int,int> e2){
    return e1.first==e2.first||e1.second==e2.second||e1.first==e2.second||e1.second==e2.first;
}

ll get(){
    ll ans=star3.empty()?1e18:*star3.begin();
    if(edge3.empty())return ans;
    pair<int,int> e1=edge3.begin()->second;
    for(auto [w,e2]:edge3){
        if(!intersect(e1,e2)){
            ans=min(ans,(ll)w+edge3.begin()->first);
            break;
        }
    }
    for(auto [w1,v1]:min3[e1.first]){
        for(auto [w2,v2]:min3[e1.second]){
            if(!intersect(make_pair(e1.first,v1),make_pair(e1.second,v2))){
                ans=min(ans,(ll)w1+w2);
            }
        }
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        upd<1>(u,v,w);
    }
    cin>>q;
    cout<<get()<<'\n';
    while(q--){
        int t,u,v,w;
        cin>>t>>u>>v;
        if(t){
            cin>>w;
            upd<1>(u,v,w);
        }else{
            upd<0>(u,v,w);
        }
        cout<<get()<<'\n';
    }

    return 0;
}