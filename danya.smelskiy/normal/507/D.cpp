#include <bits/stdc++.h>
using namespace std;

long long ans,n,k,md;
long long dp[1005][105][2];

long long p(long long x,long long y,long long z){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%z;
        x=(x*x)%z;
        y>>=1;
    }
    return res;
}
long long solve(long long x) {
    if (x==0) return 1;
    long long res=9;
    --x;
    res=res*p(10,x,md);
    return res%md;
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>md;
    dp[n+1][0][0]=1;
    for (int i=n;i>0;--i) {
        for (int j=0;j<k;++j)
        for (int z=0;z<2;++z) if (dp[i+1][j][z]) {
            for (int kk=0;kk<10;++kk) {
                    if (i==1 && kk==0) continue;
                int rr=(kk*p(10,n-i,k)+j)%k;
                bool t= (z ? true : false);
                if (kk) t=true;
                if (rr==0) {
                    if (t) {
                        ans=(ans+solve(i-1)*dp[i+1][j][z])%md;
                        continue;
                    } else dp[i][0][0]=(dp[i][0][0]+dp[i+1][0][0])%md;
                    continue;
                } else {
                    dp[i][rr][1]=(dp[i][rr][1]+dp[i+1][j][z])%md;
                }
            }
        }

    }
    cout<<ans;
}