#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int precLen=500;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[precLen+5],inv[precLen+5];

ll C(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

void initialization(){
    fact[0]=1;
    for(int i=1;i<=precLen;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
    }
    inv[precLen]=qpow(fact[precLen],mod-2);
    for(int i=precLen-1;i>=0;i--){
        inv[i]=(ll)inv[i+1]*(i+1)%mod;
    }
}

int n,x,f[505][505],p[505][505],sp[505][505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();
    cin>>n>>x;
    p[0][0]=1;
    fill(sp[0],sp[0]+1+x,1);
    for(int i=1;i<=n;i++)for(int j=1;j<=x;j++){
        for(int k=1;k<=i;k++){
            p[i][j]=(p[i][j]+sp[i-k][j-1]*C(i,k))%mod;
        }
        sp[i][j]=(sp[i][j-1]+p[i][j])%mod;
    }
    for(int i=3;i<=n;i++){
        for(int j=2;j<=i-1;j++){
            f[i][j]=(ll)i*sp[i-1][j-1]%mod;
        }
    }
    for(int i=3;i<=n;i++){
        for(int j=2;j<=x;j++){
            for(int k=0;i+k<=n;k++)if(j+i+k-1<=x){
                f[i+k][j+i+k-1]=(f[i+k][j+i+k-1]+f[i][j]*C(i+k,k)%mod*sp[k][i+k-1])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=x;j++)ans=(ans+C(n,i)*qpow(j-1,n-i))%mod;
    }
    for(int i=2;i<=x;i++)ans+=f[n][i];
    cout<<ans%mod;

    return 0;
}