#include<bits/stdc++.h>
using namespace std;
int T,n,a[1010][1010],val[1010][1010];
int nxt[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int cal(int x,int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=x+nxt[i][0],ny=y+nxt[i][1];
        if(nx<1||nx>n||ny<1||ny>n) continue;
        if(val[nx][ny]==1) cnt++;
    }return (cnt+1)%2;
}
void solve(){
    memset(val,-1,sizeof(val));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++) val[1][i]=0,val[n][i]=1;
    for(int i=1;i<=n;i++) val[i][1]=val[i][n]=(i+1)%2;
    for(int i=2;i<=n/2;i++){
        for(int j=1;j<=n-2*i+1;j++){
            val[i][i+j-1]=cal(i-1,i+j-1);
            val[i+j-1][n+1-i]=cal(i+j-1,n+2-i);
            val[n+1-i][n+2-i-j]=cal(n+2-i,n+2-i-j);
            val[n+2-i-j][i]=cal(n+2-i-j,i-1);
        }
    }int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) ans^=val[i][j]*a[i][j];//,printf("%d ",val[i][j]);
        // puts("");
    }printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}