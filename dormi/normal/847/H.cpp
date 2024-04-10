#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
ll arr[MN];
ll cost[MN+2];
ll lastvals[MN+2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll best=LLONG_MAX;
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll last=arr[n-1];
    lastvals[n-1]=arr[n-1],lastvals[n]=0;
    for(int i=n-2;i>=0;i--){
        cost[i]=cost[i+1]+max(ll(0),last+1-arr[i]);
        lastvals[i]=last=max(last+1,arr[i]);
    }
    last=0;
    for(int i=0;i<n;i++){
        ans+=max(ll(0),last+1-arr[i]);
        last=max(last+1,arr[i]);
        best=min(best,ans+cost[i+1]+max(ll(0),lastvals[i+1]+1-last));
    }
    printf("%lli\n",best);
    return 0;
}