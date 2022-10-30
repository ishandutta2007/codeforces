#include <bits/stdc++.h>
using namespace std;

long long a,b,k;
int dp[800005];
long long solve(long long l,long long r){
    long long len=r-l;
    for (long long i=0;i<=len;++i){
        dp[i]=1e9;
    }
    dp[len]=0;
    for (long long i=len;i>=1;--i) {
        dp[i-1]=min(dp[i-1],dp[i]+1);
        for (long long j=2;j<=k;++j) {
            long long nxt=l+i;
            nxt-=(nxt%j);
            nxt-=l;
            if (nxt>=0)
            dp[nxt]=min(dp[nxt],dp[i]+1);
        }
    }
    return dp[0];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>k;
    long long z=2;
    for (long long i=2;i<=k;++i) {
        long long zz=__gcd(i,z);
        z=(z*i)/zz;
    }
    long long ll=(b+z-1)/z;
    ll*=z;
    long long rr=a-(a%z);
    if (ll>=rr) {
        cout<<solve(b,a)<<'\n';
        return 0;
    }
    long long ans=solve(0,z)*(rr/z-ll/z);
    ans+=solve(rr,a);
    ans+=solve(b,ll);
    cout<<ans;
}