#include<bits/stdc++.h>
using namespace std;
const int N=20,mod=1e9+7;
int n,m,k,a[N][N],f[N][N],c[N],b[1000000];
int dfs(int x,int y){
    if(y>m)x++,y=1;if(x>n)return 1;
    int calc=-1,ans=0;
    int s=f[x-1][y]|f[x][y-1],S=~s&((1<<k)-1);
    if(n+m-x-y+1>b[S])return 0;
    for(int i=0;i<k;i++)if((!a[x][y]||a[x][y]==i+1)&&(S>>i&1)){
        c[i]++;f[x][y]=s|1<<i;
        if(c[i]==1){if(calc==-1)calc=dfs(x,y+1);(ans+=calc)%=mod;}
        else (ans+=dfs(x,y+1))%=mod;
        c[i]--;
    }
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<(1<<k);i++)b[i]=b[i>>1]+(i&1);
    if(n+m-1>k)puts("0"),exit(0);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]),c[a[i][j]-1]++;
    printf("%d\n",dfs(1,1));
    return 0;
}