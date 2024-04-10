#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=0;
        bool goodpush=false;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(i>1&&i<n){
                if(arr[i]>=2)goodpush=true;
                ans+=arr[i];
                if(arr[i]%2==1)ans++;
            }
        }
        if(ans%2==1){
            printf("-1\n");
            continue;
        }
        ans/=2;
        if(n>3){
            if(goodpush)printf("%lli\n",ans);
            else printf("-1\n");
        }
        else{
            if(arr[2]%2==0)printf("%lli\n",ans);
            else printf("-1\n");
        }
    }
    return 0;
}