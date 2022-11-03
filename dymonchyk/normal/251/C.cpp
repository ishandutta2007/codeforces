#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

const int MAX=360360;
int dp[4][MAX+2];
int simple[3*MAX+5];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    long long b,a; int k;
    cin >> b >> a >> k;
    memset(simple,-1,sizeof(simple));
    simple[0]=0;
    for(int i=1;i<=3*MAX;++i) {
        simple[i]=simple[i-1]+1;
        for(int mod=2;mod<=k;++mod) {
            int d=(i+a)%mod;
            if (d<=i&&simple[i-d]!=-1)
                simple[i]=min(simple[i],simple[i-d]+1);
        }
    }
    if (b-a<=3*MAX) {
        cout << simple[b-a] << endl;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][b%MAX]=0;
    for(int i=0;i<3;++i)
        for(int j=MAX-1;j>=0;--j)
            if (dp[i][j]!=-1) {
                for(int m=2;m<=k;++m) {
                    int ni=i,nj=j-j%m;
                    if (nj<0) ni++,nj+=MAX;
                    if (dp[ni][nj]==-1||dp[ni][nj]>dp[i][j]+1)
                        dp[ni][nj]=dp[i][j]+1;
                }
                int ni=i,nj=j-1;
                if (nj<0) ni++,nj+=MAX;
                if (dp[ni][nj]==-1||dp[ni][nj]>dp[i][j]+1)
                    dp[ni][nj]=dp[i][j]+1;
            }
    long long ans=b-a,tmp=b-b%MAX;
    for(int rem=0;rem<MAX;++rem) {
        if (dp[1][rem]==-1||dp[2][rem]==-1) continue;
//      if (dp[2][rem]-dp[1][rem]!=dp[3][rem]-dp[2][rem])
//          puts("fail");
        long long cur=dp[1][rem],nb=tmp-(rem==0 ? rem : (MAX-rem)),cnt=(nb-a)/MAX-1;
        if (cnt<0) cnt=0; nb-=cnt*MAX; cur+=(dp[2][rem]-dp[1][rem])*cnt;
        cur+=simple[nb-a];
        ans=min(ans,cur);
    }
    cout << ans << endl;
    return 0;
}