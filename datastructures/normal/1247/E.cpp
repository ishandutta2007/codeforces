#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int f[2005][2005][2],sum[2005][2005][2],rock[2005][2005][2];
int n,m;
char s[2005][2005];
signed main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for (int i=n;i>=1;i--)
        for (int j=m;j>=1;j--){
            rock[i][j][0]=rock[i][j+1][0]+(s[i][j]=='R');
            rock[i][j][1]=rock[i+1][j][1]+(s[i][j]=='R');
        }
    f[1][1][0]=f[1][1][1]=sum[1][1][0]=sum[1][1][1]=1;
    if (n==1&&m==1){
        cout<<1<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            if (i==1&&j==1)continue;
            register int k,l,r;
            l=1,r=i-1,k=i;
            while(l<=r){
                int mid=(l+r)/2;
                if (rock[mid+1][j][1]<=n-i)k=mid,r=mid-1;
                else l=mid+1;
            }
            f[i][j][0]=sum[i-1][j][1]-sum[k-1][j][1];
            f[i][j][0]=(f[i][j][0]+mod)%mod;
            l=1,r=j-1,k=j;
            while(l<=r){
                int mid=(l+r)/2;
                if (rock[i][mid+1][0]<=m-j)k=mid,r=mid-1;
                else l=mid+1;
            }
            f[i][j][1]=sum[i][j-1][0]-sum[i][k-1][0];
            f[i][j][1]=(f[i][j][1]+mod)%mod;
            sum[i][j][0]=sum[i][j-1][0]+f[i][j][0],sum[i][j][0]%=mod;
            sum[i][j][1]=sum[i-1][j][1]+f[i][j][1],sum[i][j][1]%=mod;
        }
    cout<<(f[n][m][0]+f[n][m][1])%mod<<endl;
    return 0;
}