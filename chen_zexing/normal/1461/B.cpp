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
char s[505][505];
int dp[505][505],l[505][505],r[505][505];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        long long ans=0;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=m;i++) dp[1][i]=(s[1][i]=='*'),ans+=dp[1][i];
        for(int i=2;i<=n;i++) {
            for (int j = 1; j <= m; j++) {
                l[i][j]=s[i][j]=='*'?l[i][j-1]+1:0;
            }
            r[i][m+1]=0;
            for(int j=m;j>=1;j--)
                r[i][j]=s[i][j]=='*'?r[i][j+1]+1:0;
            for(int j=1;j<=m;j++)
                dp[i][j]=s[i][j]=='*'?min(dp[i-1][j]+1,min(l[i][j],r[i][j])):0,ans+=dp[i][j];
        }
        cout<<ans<<endl;
    }
    return 0;
}