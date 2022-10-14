#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll dp[MN][2];
ll arr[MN];
vector<int> adj[MN];
ll dfs(int loc, int parent){
    ll cur=arr[loc];
    vector<pair<ll,int>> childs;
    for(auto x:adj[loc]){
        if(x!=parent){
            ll te=dfs(x,loc);
            childs.push_back({te,x});
        }
    }
    if(sz(childs)==0){
        dp[loc][0]=LLONG_MAX;
        dp[loc][1]=cur;
        return cur;
    }
    sort(childs.begin(),childs.end(),greater<>());
    ll neededcost=max(ll(0),cur-childs[0].first);
    ll largestower=max(cur,childs[0].first);
    ll totcost=0;
    for(auto x:childs){
        totcost+=dp[x.second][1];
    }
    dp[loc][1]=neededcost+totcost;
    if(sz(childs)==1){
        dp[loc][0]=LLONG_MAX;
    }
    else{
        if(cur>=childs[0].first){
            dp[loc][0]=neededcost+cur-childs[1].first+totcost;
        }
        else if(cur>childs[1].first){
            ll choice1=(dp[childs[0].second][0]==LLONG_MAX?LLONG_MAX:neededcost+cur-childs[1].first+totcost-dp[childs[0].second][1]+dp[childs[0].second][0]);//build to roots height
            ll choice2=neededcost+childs[0].first-childs[1].first+totcost;//build to child0 height
            dp[loc][0]=min(choice1,choice2);
        }
        else{
            ll choice1=(dp[childs[0].second][0]==LLONG_MAX?LLONG_MAX:neededcost+totcost-dp[childs[0].second][1]+dp[childs[0].second][0]);//dont build
            ll choice2=neededcost+childs[0].first-childs[1].first+totcost;//build to child0 height
            dp[loc][0]=min(choice1,choice2);
        }
    }
    return largestower;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b),adj[b].push_back(a);
    }
    if(n==2){
        printf("%lli\n",max(arr[1],arr[2])*2);
        return 0;
    }
    int root=1;
    for(int i=1;i<=n;i++){
        if(arr[i]>arr[root])root=i;
    }
    dfs(root,0);
    printf("%lli\n",min(dp[root][0],dp[root][1]+arr[root]));
    return 0;
}