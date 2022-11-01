#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,m,k;
ll f[5005][5005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    f[0][0]=1;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*(n-j))%mod;
            f[i+1][j]=(f[i+1][j]+f[i][j]*j)%mod;
        }
    }
    ll ans=0,im=qpow(m,mod-2),pm=1;
    for(int i=1;i<=k;i++){
        pm=pm*im%mod;
        ans+=f[k][i]*pm%mod;
    }
    cout<<ans%mod;

    return 0;
}