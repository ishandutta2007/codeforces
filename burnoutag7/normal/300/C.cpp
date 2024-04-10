#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1000000007;

inline ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[1000006];
int inv[1000006];

inline int chs(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

int a,b,n;

inline bool good(int x){
    while(x){
        if(x%10!=a&&x%10!=b)return false;
        x/=10;
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0]=inv[0]=1;
    for(int i=1;i<=1e6;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        inv[i]=qpow(fact[i],mod-2);
    }
    cin>>a>>b>>n;
    int ans=0;
    for(int i=0;i<=n;i++){
        if(good(a*i+b*(n-i)))ans=(ans+chs(n,i))%mod;
    }
    cout<<ans<<endl;

    return 0;
}