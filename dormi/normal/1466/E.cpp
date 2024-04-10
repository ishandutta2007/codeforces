#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
const ll mod=1e9+7;
ll arr[MN];
ll bit[61];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<60;i++)bit[i]=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            for(int j=0;j<60;j++){
                if(arr[i]&(ll(1)<<j))bit[j]++;
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ll andsum=0,orsum=0;
            for(int j=0;j<60;j++){
                if(arr[i]&(ll(1)<<j)){
                    andsum=(andsum+(ll(1)<<j)%mod*bit[j]%mod)%mod;
                    orsum=(orsum+(ll(1)<<j)%mod*ll(n)%mod)%mod;
                }
                else orsum=(orsum+(ll(1)<<j)%mod*bit[j]%mod)%mod;
            }
            ans=(ans+andsum*orsum%mod)%mod;
        }
        printf("%lli\n",ans);
    }
    return 0;
}