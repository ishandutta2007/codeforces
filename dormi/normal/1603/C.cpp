#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const ll mod=998244353;
const int MN=1e5+1;
ll arr[MN];
ll outsize[MN];
ll oldval[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>arr[i];
        ll val=0;
        ll sum=0;
        outsize[1]=1;
        oldval[1]=0;
        for(int i=2;i<=n;i++){
            ll cap=arr[i];
            outsize[i]=1;
            oldval[i]=0;
            for(int j=i-1;j>=1;j--){
                ll nsize=(arr[j]+cap-1)/cap;
                if(nsize==outsize[j])break;
                val=(val-oldval[j]+mod)%mod;
                cap=arr[j]/nsize;
                oldval[j]=(nsize-1)*ll(j)%mod;
                outsize[j]=nsize;
                val=(val+oldval[j])%mod;
            }
            sum=(sum+val)%mod;
        }
        printf("%lli\n",sum);
    }
    return 0;
}