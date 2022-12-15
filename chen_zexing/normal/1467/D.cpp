#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
long long mod=1000000007;
long long dp[5005][5005],cnt[5005],a[5005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++) dp[0][i]=1;
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++)
                cnt[i]+=dp[j][i]*dp[k-j][i]%mod,cnt[i]%=mod;
        long long ans=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),ans+=a[i]*cnt[i]%mod,ans%=mod;
        for(int i=1;i<=q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ans+=1LL*(y-a[x])*cnt[x]%mod,ans=(ans+mod)%mod;
            a[x]=y;
            printf("%lld\n",ans);
        }
    }
    return 0;
}