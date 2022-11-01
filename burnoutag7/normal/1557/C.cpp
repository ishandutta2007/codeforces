#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;
const int precLen=200000;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[precLen+5],inv[precLen+5],pw[precLen+5];

ll C(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

void initialization(){
    fact[0]=pw[0]=1;
    for(int i=1;i<=precLen;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        pw[i]=pw[i-1]*2%mod;
    }
    inv[precLen]=qpow(fact[precLen],mod-2);
    for(int i=precLen-1;i>=0;i--){
        inv[i]=(ll)inv[i+1]*(i+1)%mod;
    }
}

void mian(){
    int n,k;
    cin>>n>>k;
    int all0=0;
    for(int i=0;i<n;i+=2){
        all0=(all0+C(n,i))%mod;
    }
    int same=1,ans=0;
    for(int i=1;i<=k;i++){
        if(n&1^1)ans=(ans+(ll)same*qpow(pw[k-i],n))%mod;
        same=(ll)same*(all0+(n&1))%mod;
    }
    cout<<(ans+same)%mod<<'\n';
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