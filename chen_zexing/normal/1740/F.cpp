#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long mod=998244353;
vector <long long> dp[2005][2005];
int a[2005],cnt[2005],lim[2005],ccnt[2005];
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=1;i<=n;i++) ccnt[cnt[i]]++;
        for(int i=n;i;i--) ccnt[i]+=ccnt[i+1];
        for(int i=1;i<=n;i++) lim[i]=lim[i-1]+ccnt[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j].resize(j/i+1);
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(i==1) for(int j=1;j<=lim[1];j++) dp[i][j][j]=1;
            else
                for(int j=1;j<=lim[i];j++)
                    for(int k=1;k<=min(int(dp[i][j].size())-1,j-1);k++)
                        if(k<dp[i-1][j-k].size())
                            dp[i][j][k]=dp[i-1][j-k][k];
            for(int j=1;j<=n;j++)
                for(int k=int(dp[i][j].size())-2;k>=1;k--)
                    dp[i][j][k]=(dp[i][j][k+1]+dp[i][j][k])%mod;
            ans+=dp[i][n][1],ans%=mod;
        }
        printf("%lld\n",ans);

    }
    return 0;
}