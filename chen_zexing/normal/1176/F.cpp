#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
long long dp[200005][10];
vector <int> v[200005][4];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            for(int j=1,c,d;j<=x;j++) scanf("%d%d",&c,&d),v[i][c].push_back(d);
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<10;j++)
                dp[i][j]=LLONG_MIN/10;
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++) if(v[i][j].size()) sort(v[i][j].begin(),v[i][j].end(),greater<int>());
            for(int j=0;j<10;j++){
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(v[i][3].size()) dp[i][(j+1)%10]=max(dp[i][(j+1)%10],dp[i-1][j]+v[i][3][0]+(j==9?v[i][3][0]:0));
                if(v[i][2].size()) dp[i][(j+1)%10]=max(dp[i][(j+1)%10],dp[i-1][j]+v[i][2][0]+(j==9?v[i][2][0]:0));
                if(v[i][1].size()) dp[i][(j+1)%10]=max(dp[i][(j+1)%10],dp[i-1][j]+v[i][1][0]+(j==9?v[i][1][0]:0));
                if(v[i][1].size()&&v[i][2].size()) dp[i][(j+2)%10]=max(dp[i][(j+2)%10],dp[i-1][j]+v[i][2][0]+v[i][1][0]+(j==8||j==9?max(v[i][2][0],v[i][1][0]):0));
                if(v[i][1].size()>=2) dp[i][(j+2)%10]=max(dp[i][(j+2)%10],dp[i-1][j]+v[i][1][0]+v[i][1][1]+(j==8||j==9?v[i][1][0]:0));
                if(v[i][1].size()>=3) dp[i][(j+3)%10]=max(dp[i][(j+3)%10],dp[i-1][j]+v[i][1][0]+v[i][1][1]+v[i][1][2]+(j>=7?v[i][1][0]:0));
            }
        }
        long long ans=0;
        for(int i=0;i<10;i++) ans=max(ans,dp[n][i]);
        //for(int i=0;i<10;i++) cout<<dp[n][i]<<" ";puts("");
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//