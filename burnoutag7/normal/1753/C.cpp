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

int n,a[200005];

void mian(){
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m+=!a[i];
    }
    int k=0;
    for(int i=1;i<=m;i++){
        k+=a[i];
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans=(ans+n*(n-1ll)/2%mod*qpow((ll)i*i%mod,mod-2))%mod;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}