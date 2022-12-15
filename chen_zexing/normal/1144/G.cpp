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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[200005];
int dp[200005][2],nxt[200005][2];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]++;
        for(int i=1;i<=n;i++) dp[i][0]=INT_MAX,dp[i][1]=INT_MIN;
        for(int i=n;i>=1;i--){
            if(i==n) dp[i][0]=0,dp[i][1]=1e6;
            else{
                if(a[i+1]>a[i]){
                    if(dp[i][0]>dp[i+1][0]) dp[i][0]=dp[i+1][0],nxt[i][0]=0;
                }
                if(dp[i+1][1]>a[i]){
                    if(dp[i][0]>a[i+1]) dp[i][0]=a[i+1],nxt[i][0]=1;
                }
                if(a[i+1]<a[i]){
                    if(dp[i][1]<dp[i+1][1]) dp[i][1]=dp[i+1][1],nxt[i][1]=1;
                }
                if(dp[i+1][0]<a[i]){
                    if(dp[i][1]<a[i+1]) dp[i][1]=a[i+1],nxt[i][1]=0;
                }
            }
        }
        if(dp[1][0]==INT_MAX&&dp[1][1]==INT_MIN) puts("NO");
        else{
            puts("YES");
            if(dp[1][0]!=INT_MAX){
                int now=0;
                for(int i=1;i<=n;i++) printf("%d ",now),now=nxt[i][now];
            }
            else{
                int now=1;
                for(int i=1;i<=n;i++) printf("%d ",now),now=nxt[i][now];
            }
        }
    }
    return 0;
}
//
/// 
//01
//