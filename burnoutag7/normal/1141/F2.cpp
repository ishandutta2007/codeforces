#include<bits/stdc++.h>
using namespace std;

int n,a[1505];
map<int,vector<pair<int,int>>> mp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=i,sum=0;j>=0;j--){
            sum+=a[j];
            mp[sum].emplace_back(j,i);
        }
    }
    vector<pair<int,int>> ans;
    for(auto [sum,v]:mp){
        sort(v.begin(),v.end(),[](const auto& a,const auto& b){
            return a.second<b.second;
        });
        int prv=-1;
        vector<pair<int,int>> cur;
        for(auto &[lb,rb]:v){
            if(lb>prv){
                cur.emplace_back(lb,rb);
                prv=rb;
            }
        }
        if(cur.size()>ans.size())ans=cur;
    }
    cout<<ans.size()<<'\n';
    for(auto [lb,rb]:ans)cout<<lb+1<<' '<<rb+1<<'\n';

    return 0;
}