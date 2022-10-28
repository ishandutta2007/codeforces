#include<bits/stdc++.h>
#define as assign
using namespace std;
vector<vector<int>>g;
vector<int>c,dp;
int n,k,i,f,t,v;
int dfs(int u){
    c[u]=2;
    for(auto s:g[u]){
        if(c[s]==2||(!c[s]&&dfs(s)))return 1;
        dp[u]=max(dp[u],dp[s]+(u<s));
    }
    return !(c[u]=1);
}
main(){
    cin>>t;
    while(t--){
        cin>>n,f=1;
        g.as(n,{});c.as(n,0);dp.as(n,1);
        for(i=0;i<n;i++){
            cin>>k;
            while(k--)cin>>v,g[i].push_back(--v);
        }
        for(i=0;i<n;i++)f&=!(!c[i]&&dfs(i));
        cout<<(f?*max_element(begin(dp),end(dp)):-1)<<"\n";
    }
}