#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int fact[100005],inv[100005];

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int C(const int& n,const int& r){
    if(n<r)return 0;
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

int n,k,pre[100005],ans;
char s[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s+1;
    fact[0]=inv[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        inv[i]=qpow(fact[i],mod-2);
        pre[i]=(pre[i-1]+s[i]-'0')%mod;
    }
    for(int i=1;i<=n;i++){
        ans=(ans+pre[n-i]*qpow(10,i-1)%mod*C(n-1-i,k-1))%mod;
        ans=(ans+(s[n+1-i]-'0')*qpow(10,i-1)%mod*C(n-i,k))%mod;
    }
    cout<<ans<<endl;

    return 0;
}