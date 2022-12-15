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
int a[200005];
int dp[200005][2];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dp[1][0]=1;
        int ans=1;
        for(int i=2;i<=n;i++){
            dp[i][0]=(a[i]>a[i-1])*dp[i-1][0]+1;
            if(a[i]>a[i-1]) dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
            dp[i][1]=max(dp[i][1],(a[i]>a[i-2])*dp[i-2][0]+1);
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}