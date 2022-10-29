#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1e9;
int m,n,a[105],b[105],bsum,ans[105];
int dp[2][105][10005];
void Max(int &x,int y){x=max(x,y);}
int main(){
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i] >> b[i];
    for (int i=0;i<n;i++) bsum+=b[i];
    dp[0][0][0]=0;
    for (int i=0;i<n;i++){
        int o=i&1;
        for (int j=0;j<=i+1;j++)
            for (int k=0;k<=100*(i+1);k++)
                dp[o^1][j][k]=-inf;
        for (int j=0;j<=i;j++)
        for (int k=0;k<=100*i;k++){
            Max(dp[o^1][j][k],dp[o][j][k]);
            Max(dp[o^1][j+1][k+a[i]],dp[o][j][k]+b[i]);
        }
    }
    for (int j=1;j<=n;j++)
    for (int k=0;k<=100*n;k++){
        int x=dp[n&1][j][k],y=bsum-x;
        if (x<0) continue;
        Max(ans[j],min(k*2,x*2+y));
    }
    for (int j=1;j<=n;j++) printf("%.5f ",0.5*ans[j]);
    puts("");
    return 0;
}