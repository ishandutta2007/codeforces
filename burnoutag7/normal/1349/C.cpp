#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,Q;
char g[1005][1005];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
ll stp[1005][1005];

int main(){

    memset(stp,0x3f,sizeof(stp));
    queue<pair<int,int>> q;
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++){
        scanf("%s",g[i]+1);
        for(int j=1;j<=m;j++){
            if(g[i][j]==g[i-1][j]){
                stp[i][j]=0;
                stp[i-1][j]=0;
                q.push(make_pair(i,j));
                q.push(make_pair(i-1,j));
            }
            if(g[i][j]==g[i][j-1]){
                stp[i][j]=0;
                stp[i][j-1]=0;
                q.push(make_pair(i,j));
                q.push(make_pair(i,j-1));
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(stp[nx][ny]==0x3f3f3f3f3f3f3f3f&&nx>0&&ny>0&&nx<=n&&ny<=m){
                stp[nx][ny]=stp[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    while(Q--){
        int x,y;
        ll t;
        scanf("%d%d%lld",&x,&y,&t);
        if(t>stp[x][y]){
            printf("%c\n",g[x][y]^((t-stp[x][y])&1));
        }else{
            printf("%c\n",g[x][y]);
        }
    }

    return 0;
}