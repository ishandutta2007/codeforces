#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli mod=998244353;
lli fact[(int)2e5+1];
lli inv[(int)2e5+1];
lli fastpow(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
lli choose(lli a,lli b){
    return ((fact[a]*inv[b]%mod)*inv[a-b]%mod);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,m;
    cin>>n>>m;
    lli ans=0;
    fact[0]=1;
    inv[0]=1;
    for(lli i=1;i<=m;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fastpow(fact[i],mod-2);
    }
    lli te=fastpow(2,n-3)*(lli)(n-2)%mod;
    for(int i=n-1;i<=m;i++){
        ans=(ans+(choose(i-1,n-2)*te%mod))%mod;
    }
    printf("%lli\n",ans);
    return 0;
}