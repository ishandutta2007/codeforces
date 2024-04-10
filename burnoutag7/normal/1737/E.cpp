#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;
const int precLen=1e6;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[precLen+5],finv[precLen+5],pw[precLen+5],ipw[precLen+5];

ll binom(int n,int r){
    return (ll)fact[n]*finv[n-r]%mod*finv[r]%mod;
}

void initialization(){
    fact[0]=pw[0]=1;
    for(int i=1;i<=precLen;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        pw[i]=pw[i-1]*2%mod;
    }
    finv[precLen]=qpow(fact[precLen],mod-2);
    ipw[precLen]=qpow(pw[precLen],mod-2);
    for(int i=precLen-1;i>=0;i--){
        finv[i]=(ll)finv[i+1]*(i+1)%mod;
        ipw[i]=ipw[i+1]*2%mod;
    }
}

int n,f[1000005],g[1000005];

void mian(){
    cin>>n;
    f[0]=g[0]=1;
    for(int i=1;i<=n;i++){
        int l=max(0,i-(n-i-1)),r=i-1;
        f[i]=(g[r]-(l?g[l-1]-mod:0))%mod;
        g[i]=(f[i]+g[i-1])%mod;
    }
    for(int k=1;k<=n;k++){
        if(k==n)cout<<ipw[(n+1)/2-1]<<'\n';
        else if(k==1)cout<<"0\n";
        else{
            cout<<(ll)ipw[(k+1)/2]*f[n-k]%mod*ipw[n-k-1]%mod<<'\n';
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}