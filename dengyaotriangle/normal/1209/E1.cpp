#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=14;
const int maxm=2005;

int n,m;
int a[maxn][maxm];
int dp[maxm][20];
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        memset(dp,0xc0,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=m;i++){
            for(int j=0;j<(1<<n);j++){
                for(int k=0;k<(1<<n);k++){
                    if(k&(~j))continue;
                    int cg=j^k,fc=0;
                    for(int c=0;c<n;c++){
                        int cr=0;
                        for(int d=1;d<=n;d++){
                            if((cg>>(d-1))&1){
                                cr+=a[(d+c-1)%n+1][i];
                            }
                        }
                        fc=max(fc,cr);
                    }
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+fc);
                }
                //cout<<i<<j<<':'<<dp[i][j]<<endl;
            }
        }
        cout<<dp[m][(1<<n)-1]<<'\n';
    }
    return 0;
}