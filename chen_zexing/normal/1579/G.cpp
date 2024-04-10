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
int a[10005];
int dp[2005],nxt[2005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dp[0]=0;
        for(int i=1;i<=2000;i++) dp[i]=INT_MAX/10;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=2000;j++) nxt[j]=INT_MAX/10;
            for(int j=0;j<=2000;j++){
                if(dp[j]<=a[i]){
                    if(a[i]+j<=2000) nxt[a[i]+j]=min(nxt[a[i]+j],0);
                }
                else{
                    if(dp[j]+j<=2000) nxt[a[i]+j]=min(nxt[a[i]+j],dp[j]-a[i]);
                }
                if(j<=a[i]) nxt[0]=min(nxt[0],dp[j]+a[i]);
                else nxt[j-a[i]]=min(nxt[j-a[i]],a[i]+dp[j]);
            }
            for(int j=0;j<=2000;j++) dp[j]=nxt[j];
        }
        int ans=INT_MAX;
        for(int i=0;i<=2000;i++) ans=min(ans,dp[i]+i);
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//