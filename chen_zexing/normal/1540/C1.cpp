#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int c[105],b[105];
long long dp[105][10005];
int preb[105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,q,x;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>c[i];
        for(int i=1;i<n;i++) cin>>b[i];
        cin>>q>>x;
        for(int i=2;i<=n;i++){
            preb[i]=preb[i-1];
            for(int j=1;j<i;j++) preb[i]+=b[j];
        }
        long long ans=0,mod=1000000007;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            int mn=i*x+preb[i];
            for(int j=max(mn,0);j<=i*100;j++){
                for(int k=0;k<=c[i];k++)
                    if(j>=k)
                        dp[i][j]+=dp[i-1][j-k],dp[i][j]%=mod;
                if(i==n) ans+=dp[i][j],ans%=mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//