#include<bits/stdc++.h>
using namespace std;

map<int,pair<pair<int,int>,pair<int,int>>> d;
set<int> vis;
int n,a[200005],au,av,ans=-1;

int fa(int x){
    return __builtin_popcount(x)==1?0:(1<<32-__builtin_clz(x))-x;
}

bool upd(int x,pair<int,int> cd){
    cd.first++;
    if(d[x].first<cd){
        d[x].second=d[x].first;
        d[x].first=cd;
    }else if(d[x].second<cd){
        d[x].second=cd;
    }else return false;
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        upd(a[i],{114514,i});
        q.emplace(a[i]);
    }
    while(!q.empty()){
        int x=q.top();
        q.pop();
        if(vis.find(x)!=vis.end())continue;
        vis.emplace(x);
        if(upd(fa(x),d[x].first))q.emplace(fa(x));
        if(ans<d[x].first.first+d[x].second.first){
            ans=d[x].first.first+d[x].second.first;
            au=d[x].first.second;
            av=d[x].second.second;
        }
    }
    cout<<au<<' '<<av<<' '<<ans-229030<<'\n';

    return 0;
}