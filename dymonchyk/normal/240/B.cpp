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
#include <complex>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

int dp[2][40002][2];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,a,b,h[202],tot[202];
    cin >> n >> a >> b;
    for(int i=0;i<n;++i) {
        cin >> h[i];
        tot[i]=h[i];
        if (i>0) tot[i]+=tot[i-1];
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    int cur=0,next=1;
    for(int i=0;i<n;++i) {
        for(int s=0;s<=a;++s) {
            for(int t=0;t<2;++t)
                if (dp[cur][s][t]!=-1) {
                    if (s+h[i]<=a) {
                        int add=0;
                        if (i>0&&t==1) add+=min(h[i],h[i-1]);
                        if (dp[next][s+h[i]][0]==-1||dp[next][s+h[i]][0]>dp[cur][s][t]+add)
                            dp[next][s+h[i]][0]=dp[cur][s][t]+add;
                    }
                    if ((tot[i]-s)<=b) {
                        int add=0;
                        if (i>0&&t==0) add+=min(h[i],h[i-1]);
                        if (dp[next][s][1]==-1||dp[next][s][1]>dp[cur][s][t]+add)
                            dp[next][s][1]=dp[cur][s][t]+add;
                    }
                }
        }
        cur^=1; next^=1;
        memset(dp[next],-1,sizeof(dp[next]));
    }
    int ans=-1;
    for(int s=0;s<=a;++s)
        for(int t=0;t<2;++t)
            if (dp[cur][s][t]!=-1&&(ans==-1||ans>dp[cur][s][t]))
                ans=dp[cur][s][t];
    cout << ans << endl;
    return 0;
}