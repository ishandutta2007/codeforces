#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int L=12252240;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

ll f[L];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    ll in,ans=0;
    {
        ll a0,x,y,m,s=0;
        cin>>n>>a0>>x>>y>>k>>m;
        for(int i=0;i<n;i++){
            f[a0%L]++;s+=a0/L*L;
            a0=(a0*x+y)%m;
        }
        s%=mod;
        in=qpow(n,mod-2);
        ans=s*in%mod*k%mod;
    }
    for(int i=0;i<L;i++)f[i]=f[i]*in%mod;
    for(int i=1;i<=k;i++){
        for(int j=0,nj=0;j<L;j++){
            ans=(ans+f[j]*j)%mod;
            if(nj+i==j){
                nj+=i;
            }else{
                f[nj]=(f[nj]+f[j]*in)%mod;
                f[j]=f[j]*(1-in+mod)%mod;
            }
        }
    }
    cout<<ans*qpow(n,k)%mod;

    return 0;
}