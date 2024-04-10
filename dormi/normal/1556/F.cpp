#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MN=14;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll arr[MN];
ll dpwin[(1<<MN)];
ll pc[(1<<MN)][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<(1<<n);i++){
        int last=-1;
        for(int j=0;j<n;j++)if(i&(1<<j))last=j;
        for(int j=0;j<n;j++){
            if(!(i&(1<<j))){
                if(last==-1)pc[i][j]=1;
                else pc[i][j]=pc[i-(1<<last)][j]*arr[j]%mod*fp(arr[j]+arr[last],mod-2)%mod;
            }
        }
    }
    ll exp=0;
    for(int i=1;i<(1<<n);i++){
        ll prob=1;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                prob=prob*pc[(1<<n)-1-i][j]%mod;
            }
        }
        ll prob2=1;
        for(int sm=(i-1)&i;;sm=(sm-1)&i){
            ll prob3=dpwin[sm];
            for(int j=0;j<n;j++){
                if(sm&(1<<j)){
                    prob3=prob3*pc[i-sm][j]%mod;
                }
            }
            prob2=(prob2-prob3+mod)%mod;
            if(sm==0)break;
        }
        dpwin[i]=prob2;
        exp=(exp+__builtin_popcount(i)*prob2%mod*prob%mod)%mod;
    }
    printf("%lli\n",exp);
    return 0;
}