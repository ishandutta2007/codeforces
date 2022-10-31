#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
typedef long long ll;
ll fac[maxn];
const ll mod = 998244353;
ll power(ll x,ll y){
    ll res = 1 ;
    while (y){
        if (y & 1){
            res = res * x % mod;
        }
        y >>=1;
        x = x * x % mod;
    }
    return res;
}
ll A(int x,int y){
    return fac[x] * power(fac[x-y],mod-2) % mod;
}
int main(){
    fac[0] = 1;
    for (int i=1;i<maxn;i++){
        fac[i] = fac[i-1] * i % mod;
    }
    int n;
    cin>>n;
    ll ans =fac[n];
    for (int i=1;i<=n-1;i++){
        (ans += 1ll * A(n,i) * (fac[n-i]-1)%mod) %= mod;
    }
    cout<<ans<<endl;
    return 0;
}