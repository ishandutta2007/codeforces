#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll mod;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll dp[402][402];
ll pc[402];
ll fact[402],inv[402];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>mod;
    fact[0]=inv[0]=1;
    pc[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    pc[1]=1;
    for(int i=2;i<=n;i++){
        pc[i]=pc[i-1]*2%mod;
    }
    dp[0][0]=1;
    for(int i=2;i<=n+1;i++){
        for(int j=1;j<i;j++){
            for(int k=i-2;k>=0;k--){
                if(j-(i-k-1)<0)break;
                dp[i][j]=(dp[i][j]+dp[k][j-(i-k-1)]*pc[i-k-1]%mod*fact[j]%mod*inv[i-k-1]%mod*inv[j-(i-k-1)]%mod)%mod;
            }
        }
    }
    ll ans=0;
    for(int j=1;j<=n;j++){
        ans=(ans+dp[n+1][j])%mod;
    }
    printf("%lli\n",ans);
    return 0;
}