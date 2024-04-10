#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+2;
ll cost[MN],fcost[MN];
vector<ll> toremove[MN];
ll bestprice[MN];
ll dp[MN];
ll solve(vector<pll> prices){
    if(sz(prices)==1)return 0;
    for(int i=0;i<sz(prices);i++)bestprice[i]=LLONG_MAX,toremove[i]=vector<ll>();
    multiset<ll> best;
    dp[0]=0;
    best.insert(0);
    int fbad=lower_bound(prices.begin(),prices.end(),pll{prices[0].first+prices[0].second+1,-1})-prices.begin();
    toremove[fbad].push_back(0);
    if(fbad<sz(prices))bestprice[fbad]=min(bestprice[fbad],max(prices[0].second,prices[fbad].first-prices[0].first)-prices[0].second);
    for(int i=1;i<sz(prices);i++){
        for(auto x:toremove[i])best.erase(best.find(x));
        dp[i]=min((sz(best)?*best.begin():LLONG_MAX),bestprice[i]);
        best.insert(dp[i]);
        fbad=lower_bound(prices.begin(),prices.end(),pll{prices[i].first+prices[i].second+1,-1})-prices.begin();
        toremove[fbad].push_back(dp[i]);
        if(fbad<sz(prices))bestprice[fbad]=min(bestprice[fbad],max(prices[i].second,prices[fbad].first-prices[i].first)-prices[i].second+dp[i]);
    }
    return dp[sz(prices)-1];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll ans=0;
    vector<pll> prices;
    for(int i=1;i<=n;i++){
        cin>>cost[i]>>fcost[i];
        ans+=fcost[i];
        bestprice[i]=LLONG_MAX;
        if(i>1){
            prices.push_back({cost[i],fcost[i]});
        }
    }
    sort(prices.begin(),prices.end());
    ll bestadd=max(fcost[1],prices[0].first-cost[1])-fcost[1]+solve(prices);
    vector<pll> above,below;
    above.push_back({cost[1],fcost[1]});
    below.push_back({cost[1],fcost[1]});
    for(auto x:prices){
        if(x.first>=cost[1])above.push_back(x);
        else below.push_back(x);
    }
    sort(above.begin(),above.end()),sort(below.begin(),below.end());
    bestadd=min(bestadd,solve(above)+solve(below));
    printf("%lli\n",bestadd+ans);
    return 0;
}