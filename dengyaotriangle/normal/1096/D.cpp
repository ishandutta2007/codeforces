#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int c[maxn];
long long dp[maxn][4];
char x[maxn];
int n;

int main(){
    cin>>n;
    cin>>(x+1);
    for(int i=1;i<=n;i++)cin>>c[i];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        switch(x[i]){
            case 'h':
                dp[i][0]=dp[i-1][0]+c[i];
                dp[i][1]=min(dp[i-1][1],dp[i-1][0]);
                dp[i][2]=dp[i-1][2];
                dp[i][3]=dp[i-1][3];
                break;
            case 'a':
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1]+c[i];
                dp[i][2]=min(dp[i-1][2],dp[i-1][1]);
                dp[i][3]=dp[i-1][3];
                break;
            case 'r':
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                dp[i][2]=dp[i-1][2]+c[i];
                dp[i][3]=min(dp[i-1][3],dp[i-1][2]);
                break;
            case 'd':
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                dp[i][2]=dp[i-1][2];
                dp[i][3]=dp[i-1][3]+c[i];
                break;
            default:
                for(int j=0;j<4;j++) dp[i][j]=dp[i-1][j];
        }
    }
    cout<<*min_element(dp[n],dp[n]+4);
    return 0;
}