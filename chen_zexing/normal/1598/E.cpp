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
int f[1005][1005];
long long dp[1005][1005][2];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,q;
        long long ans=0;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                dp[i][j][0]=dp[i][j][1]=1;
                dp[i][j][0]+=dp[i-1][j][1],dp[i][j][1]+=dp[i][j-1][0];
                ans+=dp[i][j][0],ans+=dp[i][j][1],ans--;
            }
        for(int i=1,x,y;i<=q;i++){
            scanf("%d%d",&x,&y);
            if(f[x][y]==0){
                f[x][y]=1;
                long long t0=dp[x][y][0],t1=dp[x][y][1];
                dp[x][y][0]=dp[x][y][1]=0;
                ans-=t0+t1-1;
                int xx=x,yy=y;
                while(1){
                    if(xx+1>n||f[xx+1][yy]) break;
                    dp[xx+1][yy][0]-=t1,xx++,ans-=t1;
                    if(yy+1>m||f[xx][yy+1]) break;
                    dp[xx][yy+1][1]-=t1,yy++,ans-=t1;
                }
                xx=x,yy=y;
                while(1){
                    if(yy+1>m||f[xx][yy+1]) break;
                    dp[xx][yy+1][1]-=t0,yy++,ans-=t0;
                    if(xx+1>n||f[xx+1][yy]) break;
                    dp[xx+1][yy][0]-=t0,xx++,ans-=t0;
                }
            }
            else{
                f[x][y]=0;
                dp[x][y][0]=dp[x-1][y][1]+1,dp[x][y][1]=dp[x][y-1][0]+1;
                long long t0=dp[x][y][0],t1=dp[x][y][1];
                ans+=t0+t1-1;
                int xx=x,yy=y;
                while(1){
                    if(xx+1>n||f[xx+1][yy]) break;
                    dp[xx+1][yy][0]+=t1,xx++,ans+=t1;
                    if(yy+1>m||f[xx][yy+1]) break;
                    dp[xx][yy+1][1]+=t1,yy++,ans+=t1;
                }
                xx=x,yy=y;
                while(1){
                    if(yy+1>m||f[xx][yy+1]) break;
                    dp[xx][yy+1][1]+=t0,yy++,ans+=t0;
                    if(xx+1>n||f[xx+1][yy]) break;
                    dp[xx+1][yy][0]+=t0,xx++,ans+=t0;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
//