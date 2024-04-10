#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int a[5005],sum[5005],f[5005];
bool bo[5005][5005];
int main(){
    int t,n,m,i,j,x,mn,mx,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(bo,0,sizeof(bo));
        memset(f,-1,sizeof(f));
        f[0]=0;
        for(i=1;i<=n;++i)scanf("%d",&a[i]);
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                sum[j]=0;
            }
            mx=0;
            for(j=i;j<=n;++j){
                ++sum[a[j]];
                if(sum[a[j]]>mx)mx=sum[a[j]];
                if(mx*2<=(j-i+1)&&(j-i+1)%2==0){
                    bo[i][j]=1;
                }
            }
        }
        for(j=1;j<=n+2;++j)bo[j][j-1]=1;
        for(i=1;i<=n;++i){
            if(bo[1][i-1])f[i]=max(f[i],1);
            for(j=1;j<i;++j){
                if(a[j]==a[i]&&bo[j+1][i-1]&&f[j]!=-1){
                    f[i]=max(f[j]+1,f[i]);
                }
            }
        }
        for(j=0;j<=n;++j){
            if(bo[j+1][n])f[n+1]=max(f[n+1],f[j]);
        }
        printf("%d\n",max(0,f[n+1]));
    }
    return 0;
}