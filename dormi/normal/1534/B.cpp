#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e5+2;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        arr[n+1]=0;
        for(int i=1;i<=n;i++)cin>>arr[i];
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll should=min(arr[i],max(arr[i-1],arr[i+1]));
            ans+=arr[i]-should+abs(should-arr[i-1]);
            arr[i]=should;
        }
        printf("%lli\n",ans+arr[n]);
    }
    return 0;
}