#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=501;
ll arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<ll> nums;
    for(ll i=1;(i-1)*(i-1)<=arr[0];i++){
        if((arr[0]+i-1)/i>=i*((arr[0]+i-1)/i)-arr[0])nums.push_back(i);
        ll ne=arr[0]/i;
        if(ne>0&&(arr[0]+ne-1)/ne>=ne*((arr[0]+ne-1)/ne)-arr[0])nums.push_back(ne);
        ne+=1;
        while(ne>0&&(arr[0]+ne-1)/ne>=ne*((arr[0]+ne-1)/ne)-arr[0]){
            nums.push_back(ne);
            ne++;
        }
    }
    for(int i=1;i<n;i++){
        vector<ll> te;
        for(auto x:nums)if((arr[i]+x-1)/x>=x*((arr[i]+x-1)/x)-arr[i])te.push_back(x);
        nums=te;
    }
    ll best=*max_element(nums.begin(),nums.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(arr[i]+best-1)/best;
    }
    printf("%lli\n",ans);
    return 0;
}