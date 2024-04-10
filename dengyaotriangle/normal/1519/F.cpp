#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=6;
const int maxw=4;

constexpr int pw5(int s){
    return (s==0)?1:5*pw5(s-1);
}
int n,m;
int a[maxn],b[maxn];
int dp[pw5(6)],dp2[5][pw5(6)];
int c[maxn][maxn];
int p5[maxn+1];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++)cin>>a[i];
    sum=accumulate(a,a+n,0);
    for(int i=0;i<m;i++)cin>>b[i];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>c[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    p5[0]=1;for(int i=0;i<=n;i++)p5[i]=pw5(i);
    for(int i=0;i<m;i++){
        memset(dp2,0x3f,sizeof(dp2));
        memcpy(dp2[0],dp,sizeof(dp));
        for(int j=0;j<n;j++){
            for(int t=b[i]-1;t>=0;t--)for(int k=p5[n]-1;k>=0;k--){
                int u=(k/p5[j])%5;
                for(int s=u+1,t1=t+1,ct=k+p5[j];s<=a[j]&&t1<=b[i];s++,t1++,ct+=p5[j]){
                    dp2[t1][ct]=min(dp2[t1][ct],dp2[t][k]+c[j][i]);
                }
            }
        }
        for(int k=0;k<p5[n];k++){
            for(int j=0;j<=b[i];j++){
                dp[k]=min(dp[k],dp2[j][k]);
            }
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<p5[n];i++){
        int cs=sum;
        for(int j=0;j<n;j++){
            cs-=(i/p5[j])%5;
        }
        if(cs<=0)ans=min(ans,dp[i]);
    }
    cout<<(ans>4e8?-1:ans);
    return 0;
}