#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,m;
    cin>>n>>m;
    map<string,pair<int,int>> mp;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j+1<m;j++)mp[s.substr(j,2)]=make_pair(i,j+1);
        for(int j=0;j+2<m;j++)mp[s.substr(j,3)]=make_pair(i,j+1);
    }
    cin>>s;
    vector<int> f(m+1);
    f[0]=1;
    for(int i=1;i<=m;i++){
        if(i>=2&&mp.find(s.substr(i-2,2))!=mp.end()&&f[i-2])f[i]=2;
        if(i>=3&&mp.find(s.substr(i-3,3))!=mp.end()&&f[i-3])f[i]=3;
    }
    if(!f[m]){
        cout<<"-1\n";
        return;
    }
    vector<pair<pair<int,int>,int>> ans;
    int x=m;
    while(x){
        ans.emplace_back(make_pair(mp[s.substr(x-f[x],f[x])].second,mp[s.substr(x-f[x],f[x])].second+f[x]-1),mp[s.substr(x-f[x],f[x])].first);
        x-=f[x];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto &[seg,id]:ans)cout<<seg.first<<' '<<seg.second<<' '<<id<<'\n';
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