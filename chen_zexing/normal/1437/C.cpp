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
using namespace std;
int a[205],dp[405][205];
bool cmp(int a,int b){
    return a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<=n*2;i++) dp[i][0]=0;
        for(int i=0;i<=n*2;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=99999999;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n*2;i++)
            for(int j=1;j<=i;j++)
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+abs(i-a[j]));
        int ans=99999999;
        for(int i=1;i<=n*2;i++) ans=min(ans,dp[i][n]);
        printf("%d\n",ans);
    }
    return 0;
}