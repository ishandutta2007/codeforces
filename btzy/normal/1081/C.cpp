#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 998244353;

long long exp(long long base, long long ex){
    if(ex==0)return 1;
    if(base==0)return 0;
    long long val=exp(base,ex>>1);
    val*=val;
    val%=MOD;
    if(ex&1){
        val*=base;
        val%=MOD;
    }
    return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m,k;
    cin>>n>>m>>k;
    long long ans=1;
    for(int i=1;i<=k;++i){
        ans*=(n-i);
        ans%=MOD;
        ans*=exp(i,MOD-2);
        ans%=MOD;
    }
    ans*=m;
    ans%=MOD;
    ans*=exp(m-1, k);
    ans%=MOD;
    cout<<ans<<'\n';
}