#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[405],inv[405],pw[405];

ll C(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

int n,f[405][405];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>mod;
    fact[0]=inv[0]=fact[1]=inv[1]=1;
    pw[0]=1;pw[1]=2;
    for(int i=2;i<=n;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
        pw[i]=pw[i-1]*2%mod;
    }
    for(int i=2;i<=n;i++){
        inv[i]=(ll)inv[i-1]*inv[i]%mod;
    }
    for(int i=1;i<=n;i++){
        f[i][1]=pw[i-1];
        for(int j=1;j+1<i;j++){
            int r=i-j-1;
            for(int k=1;k*2-1<=j;k++){
                f[i][k+1]=(f[i][k+1]+(ll)f[j][k]*pw[r-1]%mod*C(i-k,r))%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i*2-1<=n;i++)ans=(ans+(ll)f[n][i])%mod;
    cout<<ans;

    return 0;
}