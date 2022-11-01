#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll ans=1;
    for(int i=1;i<=n;i++)ans=ans*i%mod;
    cout<<(ans-qpow(2,n-1)+mod)%mod<<endl;

    return 0;
}