//
// Created by calabash_boy on 18-6-23.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char s[2][maxn];
int dp[maxn][4];
int n;
inline int getMask(int x){
    int ret_ =0;
    if(s[0][x]=='X')ret_++;
    if(s[1][x]=='X')ret_+=2;
    return ret_;
}
inline void maxx(int &a,int b){
    a = max(a,b);
}
int main(){
    scanf("%s",&s[0][1]);
    scanf("%s",&s[1][1]);
    n = strlen(&s[0][1]);
    for (int i=1;i<maxn;i++){
        for (int j=0;j<4;j++){
            dp[i][j]=-0x3f3f3f3f;
        }
    }
    int mask = getMask(1);
    dp[1][mask]=0;
    for (int i=2;i<=n;i++){
        int mask = getMask(i);
        for (int k=0;k<4;k++){
            maxx(dp[i][mask],dp[i-1][k]);
        }
        if(mask==0){
            maxx(dp[i][3],dp[i-1][0]+1);
            maxx(dp[i][3],dp[i-1][1]+1);
            maxx(dp[i][3],dp[i-1][2]+1);
            maxx(dp[i][1],dp[i-1][0]+1);
            maxx(dp[i][2],dp[i-1][0]+1);
        }else if(mask==1){
            maxx(dp[i][3],dp[i-1][0]+1);
        }else if (mask==2){
            maxx(dp[i][3],dp[i-1][0]+1);
        }
    }
    int ans =0;
    for (int i=0;i<4;i++){
        ans = max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}