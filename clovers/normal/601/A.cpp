#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=405;
int n,a[N][N],m;
int dis1[N][N],dis2[N][N];
void solve(){
    scanf("%d%d",&n,&m);
    memset(dis1,0x3f,sizeof(dis1));
    memset(dis2,0x3f,sizeof(dis2));
    for(int i=1;i<=m;i++){
        int x,y; scanf("%d%d",&x,&y);
        a[x][y]=1; a[y][x]=1;
    }
    for(int i=1;i<=n;i++){
        dis1[i][i]=0; dis2[i][i]=0;
        for(int j=1;j<=n;j++)if(j!=i){
            if(a[i][j]) dis1[i][j]=dis1[j][i]=1;
            else dis2[i][j]=dis2[j][i]=1;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) dis1[i][j]=min(dis1[i][j],dis1[i][k]+dis1[k][j]);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
    }
    int ans=max(dis1[1][n],dis2[1][n]);
    if(ans>10000000) puts("-1");
    else printf("%d\n",ans);
}

int main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){solve();}
    return 0;
}