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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[5005],b[5005];
int dp[5005][5005];
int solve(int x,int y){
    dp[0][0]=0;
    for(int i=1;i<=x;i++)
        for(int j=i;j<=y;j++)
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(a[i]-b[j])),dp[i][j+1]=dp[i][j];
    return dp[x][y];
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,x=0,y=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=INT_MAX/10;
        for(int i=1,t;i<=n;i++){
            scanf("%d",&t);
            t?a[++x]=i:b[++y]=i;
        }
        printf("%d\n",solve(x,y));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp