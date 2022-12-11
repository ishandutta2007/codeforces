#include<bits/stdc++.h>
using namespace std;
const int N=20,M=5010;
int t,n,m,a[N][M],lim,dp[M][N],f[M][N],mx[M],p[M];
void cmax(int &x,int y){y>x?x=y:0;}
bool cmp(int x,int y){return mx[x]>mx[y];}
void solve(){
    scanf("%d%d",&n,&m);lim=1<<n;
    memset(dp,0,sizeof(dp));memset(f,0,sizeof(f));memset(mx,0,sizeof(mx));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cmax(mx[i],a[j][i]);
    for(int i=0;i<m;i++)p[i]=i;sort(p,p+m,cmp);
    for(int i=0;i<min(n,m);i++)
        for(int j=0;j<lim;j++)
            for(int k=0;k<n;k++){
                int dat=0;
                for(int l=0;l<n;l++)if(j>>l&1)dat+=a[(l+k)%n][p[i]];
                cmax(f[j][i],dat);
            }
    for(int i=0;i<lim;i++)dp[i][0]=f[i][0];
    for(int i=1;i<n;i++)
        for(int j=0;j<lim;j++){
            dp[j][i]=dp[j][i-1];
            for(int k=j;k;k=(k-1)&j)
                cmax(dp[j][i],dp[j^k][i-1]+f[k][i]);
        }
    printf("%d\n",dp[lim-1][n-1]);
}
int main(){
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}