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

int main(){
    int n,k;
    cin>>n>>k;
    cout<<qpow(k,k-1)*qpow(n-k,n-k)%mod<<endl;
    return 0;
}