#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
int dp[MN];
int arr[MN];
pii smaller[MN],larger[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>arr[i];
        dp[n]=0;
        int sl=MN,sr=MN-1;
        int ll=MN,lr=MN-1;
        smaller[--sl]={arr[n],n};
        larger[--ll]={arr[n],n};
        for(int i=n-1;i>=1;i--){
            dp[i]=INT_MAX;
            int presl=sl;
            while(sl<=sr&&smaller[sl].first>arr[i])sl++;
            int loc=(sl<=sr?smaller[sl].second:n+1);
            int largeloc=lower_bound(larger+ll,larger+lr+1,loc,[&](pii it, int val){
                return it.second<val;
            })-larger;
            if(ll<=lr&&largeloc-1>=ll&&largeloc-1<=lr){
                dp[i]=dp[larger[largeloc-1].second]+1;
            }
            while(ll<=lr&&larger[ll].first<arr[i])ll++;
            loc=(ll<=lr?larger[ll].second:n+1);
            larger[--ll]={arr[i],i};
            int smallloc=lower_bound(smaller+presl,smaller+sr+1,loc,[&](pii it, int val){
                return it.second<val;
            })-smaller;
            if(sl<=sr&&smallloc-1>=sl&&smallloc-1<=sr){
                dp[i]=min(dp[i],dp[smaller[smallloc-1].second]+1);
            }
            smaller[--sl]={arr[i],i};
        }
        printf("%d\n",dp[1]);
    }
    return 0;
}