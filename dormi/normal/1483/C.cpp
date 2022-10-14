#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
ll dp[MN],val[MN];
int height[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>height[i];
    vector<pair<int,ll>> deq;
    multiset<ll> trans;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        ll maval=dp[i-1];
        while(sz(deq)&&height[deq.back().first]>height[i]){
            trans.erase(trans.find(deq.back().second+val[deq.back().first]));
            maval=max(maval,deq.back().second);
            deq.pop_back();
        }
        deq.push_back({i,maval});
        trans.insert(maval+val[i]);
        dp[i]=*trans.rbegin();
    }
    printf("%lli\n",dp[n]);
    return 0;
}