#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        n>>=1;
        a=a*a%mod;
    }
    return res;
}

ll inv(ll a){
    return qpow(a,mod-2);
}

ll n,m,h;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;{ll t;cin>>t>>h;h-=t-1;}
    if(n*m&1){
        cout<<qpow(h,n*m)<<endl;
    }else{
        cout<<(qpow(h,n*m)+(h&1))*inv(2)%mod<<endl;
    }

    return 0;
}