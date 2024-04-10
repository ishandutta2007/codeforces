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

int n,a[300005];
ll fact[300005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    fact[0]=1;
    for(int i=1;i<=n<<1;i++){
        cin>>a[i];
        fact[i]=fact[i-1]*i%mod;
    }
    sort(a+1,a+1+(n<<1));
    ll ans=0;
    for(int i=1;i<=n;i++)ans-=a[i];
    for(int i=n+1;i<=n<<1;i++)ans+=a[i];
    ans=fact[n<<1]*qpow(fact[n],mod-2)%mod*qpow(fact[n],mod-2)%mod*(ans%mod)%mod;
    cout<<ans<<endl;

    return 0;
}