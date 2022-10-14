#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e6+1;
ll arr[MAXN];
ll dp[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll r1,r2,r3,d;
    cin>>n>>r1>>r2>>r3>>d;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i]=dp[i-1]+min(r1*arr[i]+r3,min(r2+r1,arr[i]*r1+r1+r1)+d+d)+(i>1?d:0);
        if(i>=2)dp[i]=min(dp[i],dp[i-2]+min(r2+r1,arr[i]*r1+r1+r1)+min(r2+r1,arr[i-1]*r1+r1+r1)+d+d+d+(i>2?d:0));
    }
    ll ans=dp[n];
    ll sum=0;
    for(int i=n;i>=1;i--){
        if(i<n)sum+=min({arr[i]*r1+r3,r2+r1,arr[i]*r1+r1+r1})+d+d;
        else sum+=min(arr[i]*r1+r3,min(r2+r1,arr[i]*r1+r1+r1)+d+d);
        ans=min(ans,sum+dp[i-1]+(i==1?0:d));
    }
    printf("%lli\n",ans);
    return 0;
}